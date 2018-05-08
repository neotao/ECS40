// Yizhi Tao
// 912121365
//
// Restaurant.cpp
//

#include "Restaurant.h"
#include <iostream>

using namespace std;


Restaurant::Restaurant(int nLarge, int nMedium, int nSmall):
size(nLarge + nMedium + nSmall)
{
	tableList = new Table*[size];
	for (int i = 0; i < nLarge; i ++)
	{
		tableList[i] = new Table(10);
	}
	for (int i = nLarge; i < (nLarge + nMedium); i ++)
	{
		tableList[i] = new Table(7);
	}
	for (int i = nSmall; i < size; i++)
	{
		tableList[i] = new Table(5);
	}
	for (int i = 0; i < size; i++)
	{
		cout << "Table " << (i + 1) << " maximum occupancy "
		<< tableList[i]->maxOccupancy() << endl;
	}
}

void Restaurant::addGuests(int nGuests)
{
	if (nGuests < 1)
	{
		throw invalid_argument ("must be positive");
	}

	for (int i = 0; i < size ; i ++)
	{
		if (tableList[i]->addGuests(nGuests))
		{
			cout << nGuests << " guests added to table " << i + 1 << endl;
			break;
		}
		else if ((nGuests > tableList[i]->maxOccupancy()) || (i == (size - 1)))
		{
			cout << " could not accommodate " << nGuests << " guests" << endl;
			break;
		}
	}
}

void Restaurant::printSummary(void)
{
	cout << "Summary:" << endl;

	for (int i = 0; i < size; i++)
	{
		if (tableList[i]->currentOccupancy() != 0)
		{
			cout << "table " << i + 1 << " " << tableList[i]->currentOccupancy()
			<< "/" <<tableList[i]->maxOccupancy() << endl;
		}
	}
}
