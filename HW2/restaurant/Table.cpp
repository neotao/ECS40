// Yizhi Tao
// 912121365
//
// Table.cpp
//

#include "Table.h"
#include <iostream>

using namespace std;


 Table::Table(int n): maxGuests(n)
 {
 	numGuests = 0;
 }

int Table::maxOccupancy(void)
{
	return maxGuests;
}

int Table::currentOccupancy(void)
{
	return numGuests;
}

bool Table::addGuests(int n)
{
	if ((numGuests + n) > maxGuests)
	{
		return false;
	}
	else
	{
		numGuests += n;
		return true;
	}
}
