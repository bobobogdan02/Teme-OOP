#include <iostream>
using namespace std;

class Form {
public:


	virtual int area() = 0;
};

class Rectangle : public Form {
public:
	Rectangle(int width, int height) : Form(width, height) {}

	int area() override {
		return this->width * this->height;
	}
};

class Triangle : public Form {
public:
	Triangle(int width, int height) : Form(width, height) {}

	int area() override {
		return (this->width * this->height) / 2;
	}
};

int main() {
	Form *rectangle = new Rectangle(10, 10);
	Form *triangle = new Triangle(2, 5);

	cout << rectangle->area() << "\n";
	cout << triangle->area() << "\n";

	return 0;
}
