#ifndef _CITY_H_
#define _CITY_H_

#include <iostream>
#include <string>
using namespace std;
class City
{
public:
	City(const string& = "");
	string getName() const;
	bool operator==(const City&) const;
	bool operator!=(const City&) const;
	bool operator<(const City&) const;
	bool operator<=(const City&) const;
	bool operator>(const City&) const;
	bool operator>=(const City&) const;
private:
	string name;
};

ostream& operator  << (ostream&, const City&);

#endif
