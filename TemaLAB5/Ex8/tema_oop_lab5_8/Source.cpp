#include <iostream>
#include <string>

class Mecanism {
private:
	std::string name;
	int voltage;
public:
	Mecanism(std::string name, int voltage) {
		this->name = name;
		this->voltage = voltage;
	}
	void setName(std::string name) {
		this->name = name;
	}
	void setVoltage(int voltage) {
		this->voltage = voltage;
	}
	std::string getName() {
		return this->name;
	}
	int getVoltage() {
		return this->voltage;
	}
};

class MasinaDeCalcul {
private:
	std::string name;
	int freq;
public:
	MasinaDeCalcul(std::string name, int freq) {
		this->name = name;
		this->freq = freq;
	}
	void setName(std::string name) {
		this->name = name;
	}
	void setFreq(int freq) {
		this->freq = freq;
	}
	std::string getName() {
		return this->name;
	}
	int getFreq() {
		return this->freq;
	}
};

class Computer : public MasinaDeCalcul {
private:
	int memory;
public:
	Computer(std::string name, int freq, int memory) : MasinaDeCalcul(name, freq) {
		this->memory = memory;
	}
	void setMemory(int memory) {
		this->memory = memory;
	}
	int getMemory() {
		return this->memory;
	}
};

class Robot : public Mecanism, public Computer {
private:
	int noLegs;
public:
	Robot(std::string name, int voltage, int freq, int memory, int noLegs) :
		Mecanism(name, voltage), Computer(name, freq, memory) {
		this->noLegs = noLegs;
	}
	void setLegs(int noLegs) {
		this->noLegs = noLegs;
	}
	int getLegs() {
		return this->noLegs;
	}
};

int main() {
	Robot *r = new Robot("robot1", 300, 3, 1500, 2);

	r->setVoltage(450);
	r->setFreq(4);
	r->setMemory(5000);

	std::cout << r->Mecanism::getName() << " " << r->getFreq() << " " << r->getMemory() << "\n";

	delete r;

	return 0;
}