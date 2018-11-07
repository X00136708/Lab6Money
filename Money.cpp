#include <iostream>
#include "Money.h"
#include <cmath>
using namespace std;

Money::Money(int majorType, int minorType) {

	major = majorType;
	minor = minorType;
}
Money::Money(int cents) {

	major = (cents / 100);
	minor = cents % 100;
}

Money Money::operator-(const Money& m2) {
	Money temp(((major - m2.major) +1) * 100 - (minor + m2.minor));
	return temp;
}
Money Money::operator*(const int amount) {
	Money temp((major * 100 + minor) * amount);
	return temp;
}
Money Money::operator/(const int num) {
	Money temp((major * 100 + minor) / num);
	return temp;
}
Money Money::operator+(const Money& m2) {
	Money temp((major + m2.major) * 100 + minor + m2.minor);
	return temp;
}
bool Money::operator==(const Money& m2) {

	if ((major + minor) == (m2.major + m2.minor)) {
		return true;
	}
	else {
		return false;
	}
}
bool Money::operator<(const Money& m2) {
	if ((major + minor) < (m2.major + m2.minor)) {
		return true;
	}
	else {
		return false;
	}
}
bool Money::operator>(const  Money& m2) {
	if ((major + minor) > (m2.major + m2.minor)) {
		return true;
	}
	else {
		return false;
	}
}

ostream& operator<<(ostream& inputStream, const Money& m1) {
	inputStream << m1.major << "." << m1.minor << " " << m1.name << endl;
	return inputStream;
}

Money Money::operator++(int a) {
	return Money(major, ++minor);
}

Money Money::operator--() {
	return Money(major, --minor);
}

Money Money::operator-() {
	return Money(-major, -minor);
}
