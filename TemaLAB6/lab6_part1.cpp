#include <iostream>

class NumarComplex {
public:
	int real;
	int imag;

	NumarComplex(int real, int imag) {
		this->real = real;
		this->imag = imag;
	}
};

class Operatii {
public:
	double *nr = nullptr;
	NumarComplex *z = nullptr;

	static double absValue(double nr) {
		return fabs(nr);
	}
	static double absValue(NumarComplex z) {
		return sqrt(pow(z.real, 2) + pow(z.imag, 2));
	}
	static void afisare(double nr) {
		std::cout << "Numarul este: " << nr << "\n";
	}
	static void afisare(NumarComplex z) {
		std::cout << "Numarul este: " << z.real << " + " << z.imag << "i\n";
	}

	Operatii(double nr) {
		this->nr = new double(nr);
	}
	Operatii(NumarComplex z) {
		this->z = new NumarComplex(z.real, z.imag);
	}
};

int main() {
	double n = -5.4;
	NumarComplex z(2, 3);

	Operatii realInst(n);
	Operatii compInst(z);

	realInst.afisare(*realInst.nr);
	auto result1 = realInst.absValue(*realInst.nr);
	std::cout << result1 << "\n";

	compInst.afisare(*compInst.z);
	auto result2 = compInst.absValue(*compInst.z);
	std::cout << result2 << "\n";

	return 0;
}