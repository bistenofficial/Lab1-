//1.	Создайте класс BinPolynom(полином с двоичными коэффициентами) с операциями + , +=, -, -=, =, == , != , > , < , >= , <= , *, *=.Все операции над коэффициентами выполняются в двоичной арифметике.

#include <iostream>
#include <vector>
#include "BinPolynom.cpp"
using namespace std;
int main()
{
    vector<int> deg;
    int* pointer = deg.data();
    for (int i = 0; i < 5; ++i)
    {
        pointer[i] = i;///равносильно vecInt[i]=I;
    }
}

