#pragma once
#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
using namespace std;

class CVector {
private:
    int soChieu;
    double* data;

public:
    // Constructor
    CVector(int n = 0);

    // Copy constructor
    CVector(const CVector& other);

    // Destructor
    ~CVector();

    // =
    CVector& operator=(const CVector& other);

    // Getter
    int GetSoChieu() const;
    double GetPhanTu(int i) const;

    // Setter
    void SetPhanTu(int i, double value);

    // Nhập xuất
    friend istream& operator>>(istream& in, CVector& v);
    friend ostream& operator<<(ostream& out, const CVector& v);
};

#endif
