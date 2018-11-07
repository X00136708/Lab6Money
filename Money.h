#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Money {
private:
	char name[20] = "euro";
	int major;
	int minor;
public:
	Money();
	Money(int majorType, int minorType);
	Money(int cents);

	Money operator-(const Money& rvalue);
	Money operator+(const Money& rvalue);
	Money operator*(const int amount);
	Money operator/(const int amount);

	friend ostream& operator<<(ostream& output, const Money& m1);
	bool operator==(const Money& rvalue);
	bool operator<(const Money& rvalue);
	bool operator>(const Money& rvalue);
	Money operator++(const int a);
	Money operator--();
	Money operator-();
};