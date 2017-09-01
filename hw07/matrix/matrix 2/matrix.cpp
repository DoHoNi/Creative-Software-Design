//
//  matrix.cpp
//  matrix
//
//  Created by 김도현 on 2015. 11. 4..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#include "matrix.h"
#include <stdlib.h>


Matrix::Matrix():cols_(0),rows_(0){  }
Matrix::Matrix(const Matrix& m):cols_(m.cols()),rows_(m.rows()),values_(m.values_){}
Matrix::Matrix(int rows, int cols):cols_(cols),rows_(rows){}

    int& Matrix::operator()(int r, int c)
    {
        return values_[Sub2Ind(r,c)];
    }
    const int& Matrix::operator()(int r, int c) const
    {
        return values_[Sub2Ind(r,c)];
    }
    
    Matrix Matrix::operator+() const
    {
        return *this;
    }

    Matrix Matrix::operator-() const
    {
        Matrix result;
        result.Resize(rows_, cols_);
        for(int i=0;i< this->rows();++i)
        {
            for(int j=0;j< this->cols();++j)
            {
                result(i,j)=-values_[Sub2Ind(i,j)];
            }
           
        }
        return result;
    }
    
Matrix Matrix::Transpose() const
    {
        Matrix transpose;
        transpose.Resize(cols_,rows_ );
        for(int i=0;i< cols_;++i)
        {
            for(int j=0;j< rows_;++j)
            {
                transpose(i,j)=values_[Sub2Ind(j,i)];
            }
            
        }
        return transpose;
        
    }// 아래 설명 참조.

istream& operator>>(istream& is, Matrix& m)
{
    int row,col;
    cin>>row>>col;
    m.Resize(row, col);
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<col;++j)
            is>>m(i,j);
    }
    
    return cin;
}
ostream& operator<<(ostream& os, const Matrix& m)
{
    for(int i=0;i<m.rows();++i)
    {
        for(int j=0;j<m.cols();++j)
            os<<m(i,j) << " ";
        os<<endl;
    }
    return cout;
}

// 행렬연산. 왼쪽 행렬과 오른쪽 행렬의 크기가 맞지 않아 계산이 되지 않는 경우
// cout << "Invalid operation" << endl; 을 출력하고 프로그램을 종료
// (exit(0) 함수).

Matrix operator+(const Matrix& lm, const Matrix& rm)
{
    if(lm.cols()!=rm.cols() || lm.rows()!=rm.rows())
    {
        cout << "Invalid operation" << endl;
        exit(0);
    }
    Matrix result;
    result.Resize(lm.rows(), lm.cols());
    for(int i=0;i< lm.rows();i++)
    {
        for(int j=0;j< lm.cols();j++)
            result(i,j) = lm(i,j)+rm(i,j);
            
    }
    
    return result;
    
}
Matrix operator-(const Matrix& lm, const Matrix& rm)
{
    if(lm.cols()!=rm.cols() || lm.rows()!=rm.rows())
    {
        cout << "Invalid operation" << endl;
        exit(0);
    }

    Matrix result;
    result.Resize(lm.rows(), lm.cols());
    for(int i=0;i< lm.rows();++i)
    {
        for(int j=0;j< lm.cols();++j)
            result(i,j) = lm(i,j)-rm(i,j);
    }
    return result;
    

}

// 행렬곱. 왼쪽 행렬의 행의 크기와 오른쪽 행렬의 열의 크기가 맞아야 함. 안 맞을 시는 위 참조
Matrix operator*(const Matrix& lm, const Matrix& rm)
{
    if(lm.cols()!=rm.rows())
    {
        cout << "Invalid operation" << endl;
        exit(0);
    }
    Matrix result;
    result.Resize(lm.rows(), rm.cols());
    for(int i=0; i<lm.rows();i++)
    {
        for(int j=0;j<rm.cols();j++)
        {
            result(i,j)=0;
            for(int k=0;k<lm.cols();k++)
            {
                result(i,j) += lm(i,k)*rm(k,j);
            }
        }
    }
    
    return result;
}

Matrix operator+(const int& a, const Matrix& rm)
{
    Matrix result;
    result.Resize(rm.rows(), rm.cols());
    for(int i=0; i<rm.rows();i++)
    {
        for(int j=0;j<rm.cols();j++)
        {
            result(i,j)=a+rm(i,j);
            
        }
    }
    
    return result;

}
Matrix operator-(const int& a, const Matrix& rm)
{
    Matrix result;
    result.Resize(rm.rows(), rm.cols());
    for(int i=0; i<rm.rows();i++)
    {
        for(int j=0;j<rm.cols();j++)
        {
            result(i,j)=a-rm(i,j);
            
        }
    }
    
    return result;

}
Matrix operator*(const int& a, const Matrix& rm)
{
    Matrix result;
    result.Resize(rm.rows(), rm.cols());
    for(int i=0; i<rm.rows();i++)
    {
        for(int j=0;j<rm.cols();j++)
        {
            result(i,j)=a*rm(i,j);
            
        }
    }
    
    return result;

}
Matrix operator+(const Matrix& lm, const int& a)
{
    Matrix result;
    result.Resize(lm.rows(), lm.cols());
    for(int i=0; i<lm.rows();i++)
    {
        for(int j=0;j<lm.cols();j++)
        {
            result(i,j)=a+lm(i,j);
            
        }
    }
    
    return result;

}
Matrix operator-(const Matrix& lm, const int& a)
{
    Matrix result;
    result.Resize(lm.rows(), lm.cols());
    for(int i=0; i<lm.rows();i++)
    {
        for(int j=0;j<lm.cols();j++)
        {
            result(i,j)=lm(i,j)-a;
            
        }
    }
    
    return result;

}
Matrix operator*(const Matrix& lm, const int& a)
{
    Matrix result;
    result.Resize(lm.rows(), lm.cols());
    for(int i=0; i<lm.rows();i++)
    {
        for(int j=0;j<lm.cols();j++)
        {
            result(i,j)=a*lm(i,j);
            
        }
    }
    
    return result;

}

