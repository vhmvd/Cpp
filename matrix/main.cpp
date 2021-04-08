#include "usdmat.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
    usdmat test1, test2, test3;
    string file="test-2.txt";
    test1.setElement(file);
    test2.setElement(file);
    cout<<"Contents of test matrix";
    test1.getElement();
    cout<<"Same";
    test2.getElement();
    cout<<"Multiplication";
    test3 = test1*test1;
    test3.getElement();
    cout<<"Addition";
    test3 = test1+test2;
    test3.getElement();
    cout<<"Scalar multiplication with k=5";
    test3 = test1&5;
    test3.getElement();
    
    //Uncomment code below when passing arguments
    //Uncomment the line:25 in usdmat.hpp when compiling from main only
    
    string mat1=argv[1], mat2=argv[2];
    usdmat userGiven1, userGiven2, temp;
    userGiven1.setElement(mat1);
    userGiven2.setElement(mat2);
    cout<<"Contents of matrix 1";
    userGiven1.getElement();
    cout<<"Contents of matrix 2";
    userGiven2.getElement();
    cout<<"Multiplication";
    temp=userGiven1*userGiven2;
    temp.getElement();
    cout<<"Addition";
    temp=userGiven1+userGiven2;
    temp.getElement();
    int k=0;
    cout<<"\nINPUT scalar k to multiply with the matrix1: ";
    cin>>k;
    temp=userGiven1&k;
    cout<<"\nAfter scalar multiplication with k="<<k<<" on matrix1";
    temp.getElement();
    cout<<"\nINPUT scalar k to multiply with the matrix2: ";
    cin>>k;
    temp=userGiven2&k;
    cout<<"\nAfter scalar multiplication with k="<<k<<" on matrix2";
    temp.getElement();
}
