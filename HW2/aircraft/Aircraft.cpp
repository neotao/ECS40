// Yizhi Tao
// 912121365
//
//  Aircraft.cpp
//

#include "Aircraft.h"
#include <iostream>

using namespace std;

Aircraft::Aircraft(int n, std::string name_str): numEng(n), nm(name_str)
{
  hrs = new int[numEng];
}

const std::string Aircraft::name(void) const
{
  return nm;
}

int Aircraft::numEngines(void) const
{
  return numEng;
}

void Aircraft::setHours(int i, int h)
{
  hrs[i-1] = h;
}

void Aircraft::print(void) const
{
  cout << "Aircraft: " << nm << " type: " << type() << " has " << numEng
  << " engines" << endl;
  for (int i = 0; i < numEng; i ++)
  {
    cout << "engine " << i + 1 << ": " << hrs[i] << " hours" << endl;
  }
}

void Aircraft::printSchedule(void) const
{
  int timeUntilDue = 0;
  cout << "Maintenance schedule for " << nm << endl;
  for (int i = 0; i < numEng; i ++)
  {
    timeUntilDue = maxHours() - hrs[i];
    if (timeUntilDue > 0)
    {
      cout << "engine " << i + 1 << ": maintenance due in " << timeUntilDue
      << " hours" << endl;
    }
    else
    {
      cout << "engine " << i + 1 << ": maintenance due now!!" << endl;
    }
  }
}

Aircraft* Aircraft::makeAircraft(char ch, std::string name_str)
{
  if (ch == 'A')
  {
    return new A380(name_str);
  }
  if (ch == 'B')
  {
    return new B737(name_str);
  }
  return 0;
}

Aircraft::~Aircraft(void)
{
  delete [] hrs;
}

A380::A380(std::string name_str): Aircraft(4, name_str) {}

const std::string A380::type(void) const
{
  return "Airbus A380";
}

const int A380::maxHours(void) const
{
  return 750;
}

B737::B737(std::string name_str): Aircraft(2, name_str) {}

const std::string B737::type(void) const
{
  return "Boeing 737";
}

const int B737::maxHours(void) const
{
  return 500;
}
