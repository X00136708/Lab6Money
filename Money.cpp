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
	Money(int majorType, int minorType) {

		major = majorType;
		minor = minorType;
	}
	Money(int cents) {

		major = floor(cents / 100);
		minor = cents % 100;
	}

	friend Money operator-(Money& m1, Money& m2);
	friend Money operator+(Money& m1, Money& m2);
	friend Money operator*(Money& m1, int amount);
	friend Money operator/(Money& m1, int amount);
	friend ostream& operator<<(ostream& output, const Money& m1);
	friend bool operator==(Money& m1, Money& m2);
	friend bool operator<(Money& m1, Money& m2);
	friend bool operator>(Money& m1, Money& m2);
};
Money operator-(Money& m1, Money& m2) {
	Money temp((m1.major - m2.major) *100 - (m1.minor + m2.minor));
	return temp;
}
Money operator*(Money& m1, int amount) {
	Money temp((m1.major * 100 + m1.minor) * amount);
	return temp;
}
Money operator/(Money& m1, int num) {
	Money temp((m1.major *100 + m1.minor)/num);
	return temp;
}
Money operator+(Money& m1, Money& m2) {
	Money temp((m1.major + m2.major) * 100 + m1.minor + m2.minor);
	return temp;
}
bool operator==(Money& m1, Money& m2) {

	if ((m1.major+m1.minor) == (m2.major+m2.minor)) {
		return true;
	}
	else {
		return false;
	}
}
bool operator<(Money& m1, Money& m2) {
	if ((m1.major + m1.minor) < (m2.major + m2.minor)) {
		return true;
	}
	else {
		return false;
	}
}
bool operator>(Money& m1, Money& m2) {
	if ((m1.major + m1.minor) > (m2.major + m2.minor)) {
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


int main() {
	int major, minor, number;
	cout << "Enter a money value" << endl;
	cin >> major >> minor;
	Money m1(major, minor);
	cout << "Enter a money value" << endl;
	cin >> major >> minor;
	Money m2(major, minor);
	cout << "Enter a number to multiple m1 by ";
	cin >> number;

	cout << "Subtracted: " << (m1 - m2) <<  endl;
	cout << "Added: " << (m1 + m2) << endl;
	cout << "Multiplied by " << number << ": " << (m1*number) << endl;
	cout << "Divided by " << number << ": " << (m1/number) << endl;
	
	cout <<std::boolalpha << "Money values equal?: " << (m1 == m2) << endl;
	cout << "Money1 less than Money2?: " << (m1 < m2) << endl;
	cout << "Money1 greater than Money2?: " << (m1 > m2) << endl;

}