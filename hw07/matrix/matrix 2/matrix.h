//
//  matrix.h
//  matrix
//
//  Created by 김도현 on 2015. 11. 4..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#ifndef __matrix__matrix__
#define __matrix__matrix__

#include <iostream>
#include <vector>

using namespace std;

class Matrix {
public:
    Matrix();
    Matrix(const Matrix& m);
    Matrix(int rows, int cols);
    
    int rows() const { return rows_; }
    int cols() const { return cols_; }
    void Resize(int rows, int cols) {
        values_.resize((rows_ = rows) * (cols_ = cols));
    }
    
    // (r, c)의 element를 리턴하는 연산자.
    // 예) Matrix m(3,4);  cout << m(0,0) << "," << m(1,2); m(0,0) = 0;
    int& operator()(int r, int c);
    const int& operator()(int r, int c) const;
    
    Matrix operator+() const;  // 단항연산자 (Unary operators)
    Matrix operator-() const;  // ex) Matrix m(2,3); cout << -m;
    
    Matrix Transpose() const;  // 아래 설명 참조.
    
private:
    // 행과 열을 받아 해당 원소의 배열 내의 위치를 계산하는 함수.
    int Sub2Ind(int r, int c) const { return r + c * rows_; }
    
    vector<int> values_;  // rows_ * cols_ 만큼의 정수를 가진 배열.
    int rows_, cols_;     // 행과 열의 개수.
    
    // operator 함수들을 friend 로 선언하지 말고 public 함수를 이용.
};
// 입력 형식은 아래 설명 참고.
istream& operator>>(istream& is, Matrix& m);
ostream& operator<<(ostream& os, const Matrix& m);

// 행렬연산. 왼쪽 행렬과 오른쪽 행렬의 크기가 맞지 않아 계산이 되지 않는 경우
// cout << "Invalid operation" << endl; 을 출력하고 프로그램을 종료
// (exit(0) 함수).

Matrix operator+(const Matrix& lm, const Matrix& rm);
Matrix operator-(const Matrix& lm, const Matrix& rm);

// 행렬곱. 왼쪽 행렬의 행의 크기와 오른쪽 행렬의 열의 크기가 맞아야 함. 안 맞을 시는 위 참조
Matrix operator*(const Matrix& lm, const Matrix& rm);

Matrix operator+(const int& a, const Matrix& rm);
Matrix operator-(const int& a, const Matrix& rm);
Matrix operator*(const int& a, const Matrix& rm);
Matrix operator+(const Matrix& lm, const int& a);
Matrix operator-(const Matrix& lm, const int& a);
Matrix operator*(const Matrix& lm, const int& a);

//* Class 멤버 변수, 함수 및 operator 변경 금지.

#endif /* defined(__matrix__matrix__) */
