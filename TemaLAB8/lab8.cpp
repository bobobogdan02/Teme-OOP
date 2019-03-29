#include <iostream>
#include <cmath>


using namespace std;

class ComplexNr {
public:
	double real;
	double img;

	ComplexNr() {}
	ComplexNr(double real, double imag) {
		this->real = real;
		this->img = img;
	}

	double absValue() {
		return sqrt(pow(this->real, 2) + pow(this->img, 2));
	}
	bool operator<(ComplexNr &b) {
		return this->absValue() < b.absValue();
	}
	bool operator>(ComplexNr &b) {
		return this->absValue() > b.absValue();
	}
};

template <class T>
T GetMax(T a, T b) {
	T max1;
	max1 = (a > b) ? a : b;
	return (max1);
}

template <class T>
T GetMin(T a, T b) {
	T min1;
	min1 = (a < b) ? a : b;
	return (min1);
}

int main() {
	int i = 5, j = 6, k;
	long l = 10, m = 5, n;
	ComplexNr a(2, 7);
	ComplexNr b(1, 1);

	k = GetMax<int>(i, j);
	n = GetMax<long>(l, m);

	cout << k << endl;
	cout << n << endl;

	ComplexNr c = GetMax<ComplexNr>(a, b);
	ComplexNr d = GetMin<ComplexNr>(a, b);

	cout << c.real << " " << c.img << "\n";
	cout << d.real << " " << d.img << "\n";

	return 0;
}
