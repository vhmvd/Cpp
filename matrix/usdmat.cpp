#include "usdmat.hpp"
#include <fstream>
#include <iostream>

using namespace std;

usdmat::usdmat()
{
    row=0;
    col=0;
}

usdmat::usdmat(int r,int c)
{
    row=r;
    col=c;
    value=new float*[r];
    for(int i=0;i<r;i++)
        value[i]=new float[c];
}

usdmat::usdmat(const usdmat &obj)
{
//    usdmat copy=obj;
}

usdmat::~usdmat()
{
}

void usdmat::setElement(string& path)
{
    ifstream read_matrix;
    read_matrix.open(path , ios::in);
    read_matrix>>row;
    read_matrix>>col;
    usdmat(row, col);
    value=new float*[row];
    for(int i=0;i<row;i++)
        value[i]=new float[col];
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            read_matrix>>value[i][j];
        }
    }
    read_matrix.close();
}

void usdmat::getElement()
{
    cout<<"\n";
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            cout<<value[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

usdmat usdmat::operator&(int scalar)
{
    usdmat temp(row,col);
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            temp.value[i][j] = value[i][j]*scalar;
        }
    }
    return temp;
}

usdmat usdmat::operator*(const usdmat &mult)
{
    if (this->row!=mult.col)
    {
        cout<<"\nMultiplication not possible!!!\n";
        return *this;
    }
    else
    {
        usdmat temp(row, mult.col);
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                temp.value[i][j]=0;
                for (int k=0; k<col; k++)
                {
                    temp.value[i][j]+=value[i][k]*mult.value[k][j];
                }
            }
        }
        return temp;
    }
}

usdmat usdmat::operator+(const usdmat &s_mult)
{
    if(s_mult.row!=row && s_mult.col!=col)
    {
        cout<<"\nAddition not possible!!!\n";
        return *this;
    }
    else
    {
        usdmat temp(row,col);
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                temp.value[i][j]=0;
            }
        }
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                temp.value[i][j]+=value[i][j]+s_mult.value[i][j];
            }
        }
        return temp;
    }
}
