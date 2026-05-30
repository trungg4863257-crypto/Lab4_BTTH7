#include "CMatrix.h"

int main() {

    CMatrix m1, m2;

    cout << "===== NHAP MA TRAN 1 =====\n";
    cin >> m1;

    cout << "\n===== NHAP MA TRAN 2 =====\n";
    cin >> m2;

    cout << "\n===== MA TRAN 1 =====\n";
    cout << m1 << endl;

    cout << "\n===== MA TRAN 2 =====\n";
    cout << m2 << endl;

    // +
    cout << "\n===== TONG HAI MA TRAN =====\n";
    cout << m1 + m2 << endl;

    // -
    cout << "\n===== HIEU HAI MA TRAN =====\n";
    cout << m1 - m2 << endl;

    // *
    cout << "\n===== TICH HAI MA TRAN =====\n";
    cout << m1 * m2 << endl;

    // Matrix * Vector
    CVector v;

    cout << "\n===== NHAP VECTOR =====\n";
    cin >> v;

    cout << "\n===== MA TRAN * VECTOR =====\n";
    cout << m1 * v << endl;

    return 0;
}
