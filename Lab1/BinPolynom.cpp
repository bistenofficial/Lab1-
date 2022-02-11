#include "BinPolynom.h"
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
BinPolynom::BinPolynom()
{
    koef = NULL;
}
BinPolynom::~BinPolynom()
{
    delete[]koef;
}
BinPolynom::BinPolynom(int an)
{
    int i;
    n = an;
    koef = new double[n + 1];
    for (i = 0; i <= n; i++)
    {
        koef[i] = 0;
    }
}
BinPolynom::BinPolynom(const BinPolynom& f)
{
    n = f.n;
    koef = new double[n + 1];
    for (int i = 0; i <= n; i++)
        koef[i] = f.koef[i];
}
int BinPolynom::getn()
{
    return n;
}
double BinPolynom::getkoef(int i)
{
    if (i <= n)
        return koef[i];
    else
        return 0.0;
}
BinPolynom BinPolynom::operator-(const BinPolynom& t) //�������� ��������� �-�
{
    int i;
    if (n >= t.n)//�>B
    {
        BinPolynom Z = *this;
        for (i = 0; i <= t.n; i++)
            Z.koef[i] = koef[i] - t.koef[i];
        return Z;
    }
    else//B>A
    {
        BinPolynom Z(t.n);
        for (i = 0; i <= n; i++)
            Z.koef[i] = -t.koef[i] + koef[i];
        for (i = n + 1; i <= t.n; i++)
            Z.koef[i] = -t.koef[i];
        return Z;
    }
}
BinPolynom BinPolynom::operator-=(const BinPolynom& t) //�������� ��������� �-�
{
    int i;
    if (n >= t.n)//�>B
    {
        BinPolynom Z = *this;
        for (i = 0; i < n; i++)
        {
            Z.koef[i] = koef[i];
        }
        for (i = 0; i <= t.n; i++)
            Z.koef[i] -= t.koef[i];
        for (i = n + 1; i <= t.n; i++)
            Z.koef[i] -= t.koef[i];
        for (i = 0; i < n; i++)
        {
            koef[i] = Z.koef[i];
        }
        return Z;
    }
    else//B>A
    {
        BinPolynom Z(*this);
        for (i = 0; i < n; i++)
        {
            Z.koef[i] = t.koef[i];
        }
        for (i = 0; i <= t.n; i++)
            Z.koef[i] -= koef[i];
        for (i = 0; i < n; i++)
        {
            t.koef[i] = Z.koef[i];
        }
        return Z;
    }
}
BinPolynom BinPolynom::operator+(const BinPolynom& t)//�������� �������� A+B
{
    int i;
    if (n >= t.n)//A>B
    {
        BinPolynom Z = *this;
        for (i = 0; i <= n; i++)
            Z.koef[i] = koef[i] + t.koef[i];
        return Z;
    }
    else//A<B
    {
        BinPolynom Z = t;
        for (i = 0; i <= n; i++)
            Z.koef[i] = t.koef[i] + koef[i];
        return Z;
    }
}
BinPolynom BinPolynom::operator+=(const BinPolynom& t)//�������� �������� A+B
{
    int i;
    if (n >= t.n)//A>B
    {
        BinPolynom Z = *this;
        for (i = 0; i < n; i++)
        {
            Z.koef[i] = koef[i];
        }
        for (i = 0; i <= n; i++)
            Z.koef[i] += t.koef[i];
        return Z;
    }
    else//A<B
    {
        BinPolynom Z = t;
        for (i = 0; i < n; i++)
        {
            Z.koef[i] = t.koef[i];
        }
        for (i = 0; i <= n; i++)
            Z.koef[i] += koef[i];
        return Z;
    }
}
BinPolynom BinPolynom::operator*(const BinPolynom& t)//�������� ��������� �*�
{
    int i, j, s = 0;
    BinPolynom Y(n + t.n);
    for (i = 0; i <= n; i++)
        for (j = 0; j <= t.n; j++)
            Y.koef[i + j] += koef[i] * t.koef[j];
    return Y;
}
BinPolynom BinPolynom::operator*=(const BinPolynom& t)//�������� ��������� �*�
{
    int i, j, s = 0;
    BinPolynom Z = *this;
    BinPolynom Y(n + t.n);
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= t.n; j++) {

            for (int k = 0; k < n; k++)
            {
                Z.koef[k] = koef[k];
            }
            Z.koef[i] *= t.koef[j];
            Y.koef[i + j] += Z.koef[i];
        }
    }

    return Y;
}
BinPolynom BinPolynom::operator = (const BinPolynom& t)
{
    if (this != &t)
    {
        delete[] koef;
        n = t.n;
        koef = new double[n + 1];
        for (int i = 0; i <= n; i++)
            koef[i] = t.koef[i];
    }
    return *this;
}
istream& operator>>(istream& s, BinPolynom& c)// ������������� �������� �����
{
    int i;
    for (i = 0; i <= c.n; i++)
    {
        cout << i<<" coefficient: ";
        s >> c.koef[i];
    }
    return s;
}
ostream& operator << (ostream& s, const BinPolynom& c)
{
    int i, n = 0;
    for (i = 0; i <= c.n; i++)
    {
        if (c.koef[i] != 0)
            n++;
    }
    if (n != 0)
    {
        if (c.koef[0] != 0)
        {
            s << c.koef[0];
        }
        for (i = 1; i <= c.n; i++)
        {
            if (c.koef[i] < 0)
            {
                if (c.koef[i] != -1)
                    s << c.koef[i] << "X^" << i;
                else
                    s << "-" << "X^" << i;
            }
            else
            {
                if (c.koef[i] != 0)
                {
                    if (c.koef[i] != 1)
                        s << "+" << c.koef[i] << "X^" << i;
                    else
                        s << "+" << "X^" << i;
                }
            }
        }
        s << '\n';
    }
    else
    {
        s << 0;
    }
    return s;
}