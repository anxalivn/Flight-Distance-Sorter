#include <iostream>
#include <string>
using namespace std;
#include "city.h"

City::City(const string& str) : name(str)
{}

string City::getName() const
{
	return name;
}

bool City::operator==(const City& c) const
{
	return getName() == c.getName();
}

bool City::operator!=(const City& c) const
{
	return getName() != c.getName();
}

bool City::operator<(const City& c) const
{
	return getName() < c.getName();
}

bool City::operator<=(const City& c) const
{
	return getName() <= c.getName();
}

bool City::operator>(const City& c) const
{
	return getName() > c.getName();
}

bool City::operator>=(const City& c) const
{
	return getName() >= c.getName();
}

ostream& operator << (ostream& out, const City& c)
{
	out << c.getName();
	return out;
}
