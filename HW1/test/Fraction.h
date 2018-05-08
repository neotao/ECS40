// Yizhi Tao
// 912121365
//
// Fraction.h
//
// Fraction.cpp header file
//

#include <iostream>
#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
    public:
        Fraction(void);
        Fraction(int a, int b);
        Fraction(const Fraction& fract);
        ~Fraction(void);
        void set(int a, int b);
        int getNum(void) const;
        int getDen(void) const;
        friend const Fraction operator+(const Fraction& fract1, const Fraction& fract2);
        friend const Fraction operator-(const Fraction& fract1, const Fraction& fract2);
        Fraction& operator=(const Fraction& rhs);
        friend std::ostream& operator<<(std::ostream& os, const Fraction& fract);
        friend std::istream& operator>>(std::istream& is, Fraction& fract);
    private:
        int num;
        int denum;
};

#endif