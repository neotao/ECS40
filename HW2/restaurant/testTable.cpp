//
// testTable.cpp
//

#include "Table.h"
#include <iostream>

using namespace std;

int main()
{
	Table t(10);
	cout << t.maxOccupancy() << endl;
	cout << t.currentOccupancy() << endl;
	cout << "add 5: " << boolalpha << t.addGuests(5) << endl;
	cout << "add 5: " << boolalpha << t.addGuests(5) << endl;
	cout << "add 1: " << boolalpha << t.addGuests(1) << endl;
}