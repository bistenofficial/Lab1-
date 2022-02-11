#include <vector>
#include<iostream>
#include<fstream>
using namespace std;

class BinPolynom
{
private:
    int n; //������� ��������
    int* koef; //��������� �� ������ ������������� �������� koef[i] - ����������� ��� i-� �������
public:
	BinPolynom();
    BinPolynom(int an);//����������� � �����������
    BinPolynom(const BinPolynom&); //�����������
    ~BinPolynom();

    int getn(); //������� ��������� ������� ��������
    double getkoef(int); //������� ��������� ������������ ��� i-� �������
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