#pragma once
#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
#include "CVector.h"

using namespace std;

class CMatrix {
private:
    int dong;
    int cot;
    double** data;

public:
    // Constructor
    CMatrix(int d = 0, int c = 0);

    // Copy constructor
    CMatrix(const CMatrix& other);

    // Destructor
    ~CMatrix();

    // =
    CMatrix& operator=(const CMatrix& other);

    // + -
    CMatrix operator+(const CMatrix& other) const;
    CMatrix operator-(const CMatrix& other) const;

    // Matrix * Matrix
    CMatrix operator*(const CMatrix& other) const;

    // Matrix * Vector
    CVector operator*(const CVector& v) const;

    // Nhập xuất
    friend istream& operator>>(istream& in, CMatrix& m);
    friend ostream& operator<<(ostream& out, const CMatrix& m);
};

#endif
