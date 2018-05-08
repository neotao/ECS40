// Yizhi Tao
// 912121365
//
// Fraction.cpp
//
// Definition of the Fraction class
//

#include "Fraction.h"
#include <iostream>
#include<stdexcept>

using namespace std;

Fraction::Fraction(void)
{
	num = 0;
	denum = 1;
}

Fraction::Fraction(int a, int b)
{
    set(a, b);
}

Fraction::Fraction(const Fraction& fract)
{
    set(fract.num, fract.denum);
}


Fraction::~Fraction(void) { }

void Fraction::set(int a, int b)
{
	if (b == 0)
    {
        throw invalid_argument ("zero denominator");
    }
    int gcd, remainder;
    int n1 = a;
    int n2 = b;
    remainder = n1 % n2;
    while (remainder != 0)
    {
        n1 = n2;
        n2 = remainder;
        remainder = n1 % n2;
    }
    gcd = n2;
    int a_r = a/gcd;
    int b_r = b/gcd;
    num = a_r;
	denum = b_r;
}

int Fraction::getNum(void) const
{
    return this->num;
}

int Fraction::getDen(void) const
{
    return this->denum;
}


const Fraction operator+(const Fraction& fract1, const Fraction& fract2)
{
    int numAns = fract1.num*fract2.denum+fract2.num*fract1.denum;
    int denumAns = fract1.denum*fract2.denum;
    return Fraction(numAns, denumAns);
}

 const Fraction operator-(const Fraction& fract1, const Fraction& fract2)
{
    int numAns = fract1.num*fract2.denum-fract2.num*fract1.denum;
    int denumAns = fract1.denum*fract2.denum;
    return Fraction(numAns, denumAns);
}

Fraction& Fraction::operator=(const Fraction& rhs)
{
	if (&rhs == this) return *this;
	num = rhs.num;
	denum = rhs.denum;
	return *this;
}

ostream& operator << (ostream& os, const Fraction& fract)
{
    int num = fract.num;
    int denum = fract.denum;

    if (denum == 0)
    {
        throw invalid_argument ("zero denominator");
    }
    else if (denum == 1)
    {
        os << num;
    } 
    else if (num == 0)
    {
        os << 0;
    }
    else if (denum < 0)
    {
            denum = -1*fract.denum;
            num = -1*fract.num;
            os << num << '/' << denum;
    }
    else
    {
        os << num << '/' << denum;
    }
    return os;
}


istream& operator >> (istream& is, Fraction& fract)
{
    char divide;
    int a,b;
    is >> a >> divide >> b;
    fract.set(a, b);
    return is;
}


