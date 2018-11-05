#include <iostream>
using namespace std;

class Money {
private:
	char* name;
	int major;
	int minor;
public:
	Money();
	Money(int majorType, int minorType) {
		
		major = majorType;
		minor = minorType;
	}
	int getMajor() {
		return major;
	}
	int getMinor() {
		return minor;
	}
	friend Money operator-(Money m1, Money m2);
	friend Money operator*(Money m1, int amount);
	friend Money operator/(Money m1, double amount);
	friend ostream& operator<<(ostream& output, const Money& m1);
	friend bool operator==(Money& m1, Money& m2);
	friend bool operator<(Money& m1, Money& m2);
};
Money operator-(Money m1, Money m2) {
	return Money(m1.major + m2.major);
	}


int main() {
	int major, minor;
	cout << "Enter a money value" << endl;
	cin >> major >> minor;
	Money m1(major, minor);
	cout << "Enter a money value" << endl;
	cin >> major >> minor;
	Money m2(major, minor);

	cout << "Subtracted: " << m1.getMajor()-m2.getMajor()<< " euro and " << m1.getMinor()-m2.getMinor() << " cents." << endl;
	
}