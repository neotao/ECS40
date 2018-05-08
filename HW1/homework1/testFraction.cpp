//
// testFraction.cpp
//

#include "Fraction.h"
#include<iostream>
using namespace std;

void print_fraction(const Fraction& f)
{
  cout << "print_fraction: " << f.getNum() << "/" << f.getDen() << endl;
}

int main()
{
	Fraction x;
	cout << "Fraction void is called\n" << "x is " << x.getNum() << "/" << x.getDen() << endl;
	Fraction y(-2,3);
	cout << "Fraction int is called\n" << "y is " << y.getNum() << "/" << y.getDen() << endl;
	print_fraction(y);
	
	cout << "x + y =" << (x+y).getNum() << "/" << (x+y).getDen() << endl;
	cout << "x - y =" << (x-y).getNum() << "/" << (x-y).getDen() << endl;
	Fraction z = x + y;
	cout << "z = " << z.getNum() << "/" << z.getDen() << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cin >> x;
	cout << "new x = " << x << endl;
}