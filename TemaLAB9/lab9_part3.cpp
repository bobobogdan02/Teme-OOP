#include <iostream>
#include <string>
using namespace std;

class Plant {
protected:
	string name;

	Plant(string name) {
		this->name = name;
	}
	virtual ~Plant() {}
public:
	virtual void ripe() = 0;
};

class FoodSource {
protected:
	int weight;

	FoodSource(int weight) {
		this->weight = weight;
	}
	virtual ~FoodSource() {}
public:
	virtual void eat() = 0;
};

class Carrot : public Plant {
public:
	Carrot(string name) : Plant(name) {}

	void ripe() override {
		cout << "The carrot is ripe\n";
	}
};

class Chicken : public FoodSource {
public:
	Chicken(int weight) : FoodSource(weight) {}

	void eat() override {
		cout << "Ate chicken \n";
	}
};

class Apple : public Plant, public FoodSource {
public:
	Apple(int weight) : Plant("Apple"), FoodSource(weight) {}

	void ripe() override {
		cout << "The apple is ripe \n";
	}
	void eat() override {
		cout << "Ate apple \n";
	}
};

int main() {
	Plant *a = new Apple(75);
	a->ripe();
	FoodSource *b = new Apple(140);
	b->eat();

	return 0;
}
