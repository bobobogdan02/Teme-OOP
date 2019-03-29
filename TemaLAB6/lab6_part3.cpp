#include <iostream>

class ComplexNo {
public:
	double real;
	double imag;

	ComplexNo(double real, double imag) {
		this->real = real;
		this->imag = imag;
	}

	ComplexNo operator+(const ComplexNo &z) {
		ComplexNo result(0, 0);
		result.real = this->real + z.real;
		result.imag = this->imag + z.imag;

		return result;
	}
	ComplexNo operator-(const ComplexNo &z) {
		ComplexNo result(0, 0);
		result.real = this->real - z.real;
		result.imag = this->imag - z.imag;

		return result;
	}
	ComplexNo operator*(const ComplexNo &z) {
		ComplexNo result(0, 0);
		result.real += this->real * z.real;
		result.real -= this->imag * z.imag;
		result.imag += this->real * z.imag;
		result.imag += this->imag * z.real;

		return result;
	}
	ComplexNo operator/(const ComplexNo &z) {
		ComplexNo result(this->real, this->imag);

		result.real = (this->real * z.real + this->imag * z.imag) / (pow(z.real, 2) + pow(z.imag, 2));
		result.imag = (z.real * this->imag - this->real * z.imag) / (pow(z.real, 2) + pow(z.imag, 2));

		return result;
	}
	double operator~() {
		return sqrt(pow(this->real, 2) + pow(this->imag, 2));
	}
	ComplexNo operator^(int pw) {
		ComplexNo result(this->real, this->imag);
		ComplexNo base(this->real, this->imag);
		
		for (int it = 1; it < pw; ++it) {
			result = result * base;
		}

		return result;
	}
};

int main() {
	ComplexNo z1(2, 4);
	ComplexNo z2(2, 2);

	std::cout << "z1 = " << z1.real << " + " << z1.imag << "i\n";
	std::cout << "z2 = " << z2.real << " + " << z2.imag << "i\n";

	ComplexNo result(0, 0);

	result = z1 + z2;
	std::cout << "z1 + z2 = " << result.real << " + " << result.imag << "i\n";
	result = z1 - z2;
	std::cout << "z1 - z2 = " << result.real << " + " << result.imag << "i\n";
	result = z1 * z2;
	std::cout << "z1 * z2 = " << result.real << " + " << result.imag << "i\n";
	result = z1 / z2;
	std::cout << "z1 / z2 = " << result.real << " + " << result.imag << "i\n";
	std::cout << "|z1| = " << ~z1 << "\n";
	result = z1 ^ 4;
	std::cout << "z1^4 = " << result.real << " + " << result.imag << "i\n";

	return 0;
}