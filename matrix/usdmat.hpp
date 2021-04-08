#ifndef usdmat_hpp
#define usdmat_hpp

#include <string>

class usdmat
{
private:
    std::string path;
    int row;
    int col;
    float **value;
public:
    usdmat(); //empty
    usdmat(int, int); //rows and columns
    usdmat(const usdmat&); //copy
    ~usdmat(); //destructor
    void getElement();
    void setElement(std::string&);
    usdmat operator+(const usdmat&);
    usdmat operator*(const usdmat&);
    usdmat operator&(int);
};

//#include "usdmat.cpp"
#endif /* usdmat_hpp */
