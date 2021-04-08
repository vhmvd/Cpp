#include <omp.h>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#define THREADS 8

/* Global variables, Look at their usage in main() */
int image_height;
int image_width;
int image_maxShades;
int inputImage[10000][10000];
int outputImage[10000][10000];
int chunkSize;
int maskX[3][3], maskY[3][3];
int *outArr;

/* ****************Change and add functions below ***************** */
void compute_prewitt_static()
{
    /* 3x3 Sobel mask for X Dimension. */
    maskX[0][0] = +1; maskX[0][1] = 0; maskX[0][2] = -1;
    maskX[1][0] = +1; maskX[1][1] = 0; maskX[1][2] = -1;
    maskX[2][0] = +1; maskX[2][1] = 0; maskX[2][2] = -1;
    /* 3x3 Prewitt mask for Y Dimension. */
    maskY[0][0] = +1; maskY[0][1] = +1; maskY[0][2] = +1;
    maskY[1][0] = 0;  maskY[1][1] = 0;  maskY[1][2] = 0;
    maskY[2][0] = -1; maskY[2][1] = -1; maskY[2][2] = -1;

    #pragma omp parallel shared(inputImage,outputImage,chunkSize,outArr)
    {
        #pragma omp for schedule(static,chunkSize) nowait
        for (int x =0; x<image_height; x++)
        {
            outArr[x]=omp_get_thread_num();
            for (int y=0; y<image_width; y++) {
                int grad_x = 0;
                int grad_y = 0;
                int grad = 0;

                if (x == 0 || x == (image_height - 1) || y == 0 || y == (image_width - 1))
                    grad = 0;
                else {
                    /* Gradient calculation in X Dimension */
                    for (int i = -1; i <= 1; i++) {
                        for (int j = -1; j <= 1; j++) {
                            grad_x += (inputImage[x + i][y + j] * maskX[i+1][j+1]);
                        }
                    }
                    /* Gradient calculation in Y Dimension */
                    for (int i = -1; i <= 1; i++) {
                        for (int j = -1; j <= 1; j++) {
                            grad_y += (inputImage[x + i][y + j] * maskY[i+1][j+1]);
                        }
                    }
                    /* Gradient magnitude */
                    grad = (int)sqrt((grad_x*grad_x)+(grad_y*grad_y));
                }

                outputImage[x][y] = grad > 255 ? 255:grad;
                outputImage[x][y] = grad < 0 ? 0:grad;

            }
        }
    }
}
void compute_prewitt_dynamic()
{
    /* 3x3 Sobel mask for X Dimension. */
    maskX[0][0] = +1; maskX[0][1] = 0; maskX[0][2] = -1;
    maskX[1][0] = +1; maskX[1][1] = 0; maskX[1][2] = -1;
    maskX[2][0] = +1; maskX[2][1] = 0; maskX[2][2] = -1;
    /* 3x3 Prewitt mask for Y Dimension. */
    maskY[0][0] = +1; maskY[0][1] = +1; maskY[0][2] = +1;
    maskY[1][0] = 0;  maskY[1][1] = 0;  maskY[1][2] = 0;
    maskY[2][0] = -1; maskY[2][1] = -1; maskY[2][2] = -1;
    #pragma omp parallel shared(inputImage,outputImage,chunkSize,outArr)
    {
        #pragma omp for schedule(dynamic,chunkSize) nowait
        for (int x=0; x<image_height; x++)
        {
            outArr[x]=omp_get_thread_num();
            for (int y=0; y<image_width; y++) {
                int grad_x = 0;
                int grad_y = 0;
                int grad = 0;

                if (x == 0 || x == (image_height - 1) || y == 0 || y == (image_width - 1))
                    grad = 0;
                else {
                    /* Gradient calculation in X Dimension */
                    for (int i = -1; i <= 1; i++) {
                        for (int j = -1; j <= 1; j++) {
                            grad_x += (inputImage[x + i][y + j] * maskX[i+1][j+1]);
                        }
                    }
                    /* Gradient calculation in Y Dimension */
                    for (int i = -1; i <= 1; i++) {
                        for (int j = -1; j <= 1; j++) {
                            grad_y += (inputImage[x + i][y + j] * maskY[i+1][j+1]);
                        }
                    }
                    /* Gradient magnitude */
                    grad = (int)sqrt((grad_x*grad_x)+(grad_y*grad_y));
                }

                outputImage[x][y] = grad > 255 ? 255:grad;
                outputImage[x][y] = grad < 0 ? 0:grad;

            }
        }
    }

}
/* **************** Change the function below if you need to ***************** */

int main(int argc, char* argv[])
{
    if (argc != 5)
    {
        std::cout << "ERROR: Incorrect number of arguments. Format is: <Input image filename> <Output image filename> <Chunk size> <a1/a2>" << std::endl;
        return 0;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cout << "ERROR: Could not open file " << argv[1] << std::endl;
        return 0;
    }

    std::cout << "Detect edges in " << argv[1] << " using OpenMP threads\n" << std::endl;

    /* ******Reading image into 2-D array below******** */

    std::string workString;
    /* Remove comments '#' and check image format */
    while (std::getline(file, workString))
    {
        if (workString.at(0) != '#') {
            if (workString.at(1) != '2') {
                std::cout << "Input image is not a valid PGM image" << std::endl;
                return 0;
            }
            else {
                break;
            }
        }
        else {
            continue;
        }
    }
    /* Check image size */
    while (std::getline(file, workString))
    {
        if (workString.at(0) != '#') {
            std::stringstream stream(workString);
            int n;
            stream >> n;
            image_width = n;
            stream >> n;
            image_height = n;
            break;
        }
        else {
            continue;
        }
    }

    chunkSize = image_height / std::atoi(argv[3]);

    /* Check image max shades */
    while (std::getline(file, workString))
    {
        if (workString.at(0) != '#') {
            std::stringstream stream(workString);
            stream >> image_maxShades;
            break;
        }
        else {
            continue;
        }
    }
    /* Fill input image matrix */
    int pixel_val;
    for (int i = 0; i < image_height; i++)
    {
        if (std::getline(file, workString) && workString.at(0) != '#') {
            std::stringstream stream(workString);
            for (int j = 0; j < image_width; j++) {
                if (!stream)
                    break;
                stream >> pixel_val;
                inputImage[i][j] = pixel_val;
            }
        }
        else {
            continue;
        }
    }

    /************ Call functions to process image *********/
    outArr = new int[image_height];

    omp_set_num_threads(THREADS);

    double dtime_static, dtime_dyn;

    std::string opt = argv[4];

    if (!opt.compare("static"))
    {
        dtime_static = omp_get_wtime();
        compute_prewitt_static();
        dtime_static = omp_get_wtime() - dtime_static;
        std::cout << "Time taken for static: " << dtime_static << std::endl;
    }
    else {
        dtime_dyn = omp_get_wtime();
        compute_prewitt_dynamic();
        dtime_dyn = omp_get_wtime() - dtime_dyn;
        std::cout << "Time taken for dynamic: " << dtime_dyn << std::endl;
    }

    /* ********Start writing output to your file************ */
    std::ofstream ofile(argv[2]);
    if (ofile.is_open())
    {
        ofile << "P2" << "\n" << image_width << " " << image_height << "\n" << image_maxShades << "\n";
        for (int i = 0; i < image_height; i++)
        {
            for (int j = 0; j < image_width; j++) {
                ofile << outputImage[i][j] << " ";
            }
            ofile << "\n";
        }
    }
    else {
        std::cout << "ERROR: Could not open output file " << argv[2] << std::endl;
        return 0;
    }

    int tid_thread = outArr[0];
    std::cout<<"Thread: "<<tid_thread<<" Chunk processing row: "<<0<< std::endl;;
    for (int i=1; i<image_height; i++) {
        if (tid_thread != outArr[i]) {
            tid_thread = outArr[i];
            std::cout<<"Thread: "<<tid_thread<<" Chunk processing row: "<<i<< std::endl;;
        }

    }
    return 0;
}