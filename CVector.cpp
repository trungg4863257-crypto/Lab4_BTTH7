#include "CVector.h"

// Constructor
CVector::CVector(int n) {

    soChieu = n;

    if (soChieu > 0) {

        data = new double[soChieu];

        for (int i = 0; i < soChieu; i++) {
            data[i] = 0;
        }
    }
    else {
        data = nullptr;
    }
}

// Copy constructor
CVector::CVector(const CVector& other) {

    soChieu = other.soChieu;

    if (soChieu > 0) {

        data = new double[soChieu];

        for (int i = 0; i < soChieu; i++) {
            data[i] = other.data[i];
        }
    }
    else {
        data = nullptr;
    }
}

// Destructor
CVector::~CVector() {
    delete[] data;
}

// =
CVector& CVector::operator=(const CVector& other) {

    if (this != &other) {

        delete[] data;

        soChieu = other.soChieu;

        if (soChieu > 0) {

            data = new double[soChieu];

            for (int i = 0; i < soChieu; i++) {
                data[i] = other.data[i];
            }
        }
        else {
            data = nullptr;
        }
    }

    return *this;
}

// Getter
int CVector::GetSoChieu() const {
    return soChieu;
}

double CVector::GetPhanTu(int i) const {
    return data[i];
}

// Setter
void CVector::SetPhanTu(int i, double value) {
    data[i] = value;
}

// >>
istream& operator>>(istream& in, CVector& v) {

    cout << "Nhap so chieu vector: ";
    in >> v.soChieu;

    if (v.data != nullptr) {
        delete[] v.data;
    }

    v.data = new double[v.soChieu];

    for (int i = 0; i < v.soChieu; i++) {

        cout << "Phan tu [" << i << "] = ";
        in >> v.data[i];
    }

    return in;
}

// <<
ostream& operator<<(ostream& out, const CVector& v) {

    out << "(";

    for (int i = 0; i < v.soChieu; i++) {

        out << v.data[i];

        if (i != v.soChieu - 1)
            out << ", ";
    }

    out << ")";

    return out;
}
