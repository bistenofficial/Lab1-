#include <vector>
#include<iostream>
#include<fstream>
using namespace std;

class BinPolynom
{
private:
    int n; //степень полинома
    int* koef; //указатель на массив коэффициентов полинома koef[i] - коэффициент при i-й степени
public:
	BinPolynom();
    BinPolynom(int an);//конструктор с параметрами
    BinPolynom(const BinPolynom&); //копирования
    ~BinPolynom();

    int getn(); //функция получения степени полинома
    double getkoef(int); //функция получения коэффициента при i-й степени
    BinPolynom operator+(const BinPolynom&);   
    BinPolynom operator-(const BinPolynom&);   
    BinPolynom operator*(const BinPolynom&);
    BinPolynom operator+=(const BinPolynom&);
    BinPolynom operator-=(const BinPolynom&);
    BinPolynom operator*=(const BinPolynom&); 
    BinPolynom operator=(const BinPolynom&);

    BinPolynom operator==(const BinPolynom&);
    BinPolynom operator<=(const BinPolynom&);
    BinPolynom operator>=(const BinPolynom&);
    BinPolynom operator<(const BinPolynom&);
    BinPolynom operator>(const BinPolynom&);
    BinPolynom operator!=(const BinPolynom&);

    friend ostream& operator<<(ostream& s, const BinPolynom& c);
    friend istream& operator>>(istream& s, BinPolynom& c); 
};