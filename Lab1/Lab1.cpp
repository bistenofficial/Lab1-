//1.	Создайте класс BinPolynom(полином с двоичными коэффициентами) с операциями + , +=, -, -=, =, == , != , > , < , >= , <= , *, *=.Все операции над коэффициентами выполняются в двоичной арифметике.

#include <iostream>
#include <vector>
#include "BinPolynom.h"
using namespace std;
int main()
{
    int n,m;
    cout << "Enter the maximum degree of polynomial A:" << '\n';
    cin >> n;
    cout << "Enter the maximum degree of polynomial B:" << '\n';
    cin >> m;
    BinPolynom A(n),B(m);

    cout << "Enter the coefficients of polynomial A:" << '\n';
    cin >> A;

    cout << "Enter the coefficients of polynomial B:" << '\n';
    cin >> B;

    cout.setf(ios_base::fixed);
    cout.precision(0);

    cout << "Polynomial А: " << A << '\n';
    cout << "Polynomial B: " << B << '\n';

    cout << "Polynomial A+B:" << A + B << '\n';
    cout << "Polynomial A+=B:" << (A += B) << '\n';
    cout << "Polynomial A-B:"  << A - B << '\n';
    cout << "Polynomial A-=B:"  << (A -= B) << '\n';
    cout << "Polynomial A*B:"  << A * B << '\n';
    cout << "Polynomial A*=B:"  << (A *= B) << '\n';

}

