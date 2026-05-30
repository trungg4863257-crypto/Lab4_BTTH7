#include "CMatrix.h"

// Constructor
CMatrix::CMatrix(int d, int c) {

    dong = d;
    cot = c;

    if (dong > 0 && cot > 0) {

        data = new double* [dong];

        for (int i = 0; i < dong; i++) {

            data[i] = new double[cot];

            for (int j = 0; j < cot; j++) {
                data[i][j] = 0;
            }
        }
    }
    else {
        data = nullptr;
    }
}

// Copy constructor
CMatrix::CMatrix(const CMatrix& other) {

    dong = other.dong;
    cot = other.cot;

    if (dong > 0 && cot > 0) {

        data = new double* [dong];

        for (int i = 0; i < dong; i++) {

            data[i] = new double[cot];

            for (int j = 0; j < cot; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    else {
        data = nullptr;
    }
}

// Destructor
CMatrix::~CMatrix() {

    if (data != nullptr) {

        for (int i = 0; i < dong; i++) {
            delete[] data[i];
        }

        delete[] data;
    }
}

// =
CMatrix& CMatrix::operator=(const CMatrix& other) {

    if (this != &other) {

        if (data != nullptr) {

            for (int i = 0; i < dong; i++) {
                delete[] data[i];
            }

            delete[] data;
        }

        dong = other.dong;
        cot = other.cot;

        if (dong > 0 && cot > 0) {

            data = new double* [dong];

            for (int i = 0; i < dong; i++) {

                data[i] = new double[cot];

                for (int j = 0; j < cot; j++) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        else {
            data = nullptr;
        }
    }

    return *this;
}

// +
CMatrix CMatrix::operator+(const CMatrix& other) const {

    CMatrix temp(dong, cot);

    for (int i = 0; i < dong; i++) {

        for (int j = 0; j < cot; j++) {

            temp.data[i][j] =
                data[i][j] + other.data[i][j];
        }
    }

    return temp;
}

// -
CMatrix CMatrix::operator-(const CMatrix& other) const {

    CMatrix temp(dong, cot);

    for (int i = 0; i < dong; i++) {

        for (int j = 0; j < cot; j++) {

            temp.data[i][j] =
                data[i][j] - other.data[i][j];
        }
    }

    return temp;
}

// Matrix * Matrix
CMatrix CMatrix::operator*(const CMatrix& other) const {

    CMatrix temp(dong, other.cot);

    for (int i = 0; i < dong; i++) {

        for (int j = 0; j < other.cot; j++) {

            for (int k = 0; k < cot; k++) {

                temp.data[i][j] +=
                    data[i][k] * other.data[k][j];
            }
        }
    }

    return temp;
}

// Matrix * Vector
CVector CMatrix::operator*(const CVector& v) const {

    CVector temp(dong);

    for (int i = 0; i < dong; i++) {

        double tong = 0;

        for (int j = 0; j < cot; j++) {

            tong += data[i][j] * v.GetPhanTu(j);
        }

        temp.SetPhanTu(i, tong);
    }

    return temp;
}

// >>
istream& operator>>(istream& in, CMatrix& m) {

    cout << "Nhap so dong: ";
    in >> m.dong;

    cout << "Nhap so cot: ";
    in >> m.cot;

    if (m.data != nullptr) {

        for (int i = 0; i < m.dong; i++) {
            delete[] m.data[i];
        }

        delete[] m.data;
    }

    m.data = new double* [m.dong];

    for (int i = 0; i < m.dong; i++) {

        m.data[i] = new double[m.cot];

        for (int j = 0; j < m.cot; j++) {

            cout << "a[" << i << "][" << j << "] = ";
            in >> m.data[i][j];
        }
    }

    return in;
}

// <<
ostream& operator<<(ostream& out, const CMatrix& m) {

    for (int i = 0; i < m.dong; i++) {

        for (int j = 0; j < m.cot; j++) {

            out << m.data[i][j] << "\t";
        }

        out << endl;
    }

    return out;
}
