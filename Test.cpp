#include <iostream>
using namespace std;
#include "Money.h"
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

	cout << "Subtracted: " << (m1 - m2) << endl;
	cout << "Added: " << (m1 + m2) << endl;
	cout << "Multiplied by " << number << ": " << (m1*number) << endl;
	cout << "Divided by " << number << ": " << (m1 / number) << endl;
	cout << "PostFix: " << (m1++) << endl;
	cout << "Minus: " << (--m1) << endl;
	cout << "Minus other thing" << (-m1) << endl;
	cout << std::boolalpha << "Money values equal?: " << (m1 == m2) << endl;
	cout << "Money1 less than Money2?: " << (m1 < m2) << endl;
	cout << "Money1 greater than Money2?: " << (m1 > m2) << endl;

}