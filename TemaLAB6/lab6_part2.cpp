#include <iostream>

class NrComplex {
public:
	double real;
	double imag;

	NrComplex(double real, double imag) {
		this->real = real;
		this->imag = imag;
	}
};

class Operatii {
public:
	double *n1 = nullptr;
	double *n2 = nullptr;

	NrComplex *z1 = nullptr;
	NrComplex *z2 = nullptr;

	static double addition(double n1, double n2) {
		return n1 + n2;
	}
	static NrComplex addition(NrComplex z1, NrComplex z2) {
		NrComplex sum(z1.real + z2.real, z1.imag + z2.imag);
		return sum;
	}

	static double subtraction(double n1, double n2) {
		return n1 - n2;
	}
	static NrComplex subtraction(NrComplex z1, NrComplex z2) {
		NrComplex dif(z1.real - z2.real, z1.imag - z2.imag);
		return dif;
	}

	static double multiplication(double n1, double n2) {
		return n1 * n2;
	}
	static NrComplex multiplication(NrComplex z1, NrComplex z2) {
		NrComplex prod(z1.real * z2.real, z1.imag * z2.imag);
		return prod;
	}

	static double division(double n1, double n2) {
		return n1 / n2;
	}
	static NrComplex division(NrComplex z1, NrComplex z2) {
		NrComplex div(z1.real / z2.real, z1.imag / z2.imag);
		return div;
	}

	Operatii(double n1, double n2) {
		this->n1 = new double(n1);
		this->n2 = new double(n2);
	}
	Operatii(NrComplex z1, NrComplex z2) {
		this->z1 = new NrComplex(z1.real, z1.imag);
		this->z2 = new NrComplex(z2.real, z2.imag);
	}
	~Operatii() {
		delete n1;
		delete n2;
		delete z1;
		delete z2;
	}
};

int main() {
	double num1 = 10.6;
	double num2 = 5.4;
	
	Operatii realInst(num1, num2);

	auto result1 = realInst.addition(*realInst.n1, *realInst.n2);
	std::cout << result1 << "\n";
	auto result2 = realInst.subtraction(*realInst.n1, *realInst.n2);
	std::cout << result2 << "\n";
	auto result3 = realInst.multiplication(*realInst.n1, *realInst.n2);
	std::cout << result3 << "\n";
	auto result4 = realInst.division(*realInst.n1, *realInst.n2);
	std::cout << result4 << "\n";

	NrComplex *z1 = new NrComplex(5.7, 6.5);
	NrComplex *z2 = new NrComplex(2.5, 3.5);

	Operatii compInst(*z1, *z2);

	auto result5 = compInst.addition(*compInst.z1, *compInst.z2);
	std::cout << "(" << result5.real << ", " << result5.imag << ")\n";
	auto result6 = compInst.subtraction(*compInst.z1, *compInst.z2);
	std::cout << "(" << result6.real << ", " << result6.imag << ")\n";
	auto result7 = compInst.multiplication(*compInst.z1, *compInst.z2);
	std::cout << "(" << result7.real << ", " << result7.imag << ")\n";
	auto result8 = compInst.division(*compInst.z1, *compInst.z2);
	std::cout << "(" << result8.real << ", " << result8.imag << ")\n";

	delete z1;
	delete z2;

	return 0;
}