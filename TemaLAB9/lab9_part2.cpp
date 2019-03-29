#include <iostream>
#include <string>

class Weapon {
protected:
	std::string ammoType;

	Weapon(std::string ammoType) {
		this->ammoType = ammoType;
	}
	virtual ~Weapon() {}
public:
	virtual void getDetails() = 0;
	virtual void fireWeapon() = 0;
};

class Sling : public Weapon {
protected:
	double projSize;
public:
	Sling(double projSize) : Weapon("stone") {
		this->projSize = projSize;
	}
	void getDetails() override {
		std::cout << "Slingshot that can fire a " << this->ammoType << " weighting " << this->projSize << "\n";
	}
	void fireWeapon() override {
		this->projSize = 0;
	}
};

class AtomicBomb : public Weapon {
	~AtomicBomb() {}
public:
	AtomicBomb() : Weapon("nuclear fission") {};
	void getDetails() override {
		std::cout << "Explosive device powered by " << this->ammoType << "\n";
	}
	void fireWeapon() override {
		this->~AtomicBomb();
	}
};

class Gun : public Weapon {
protected:
	double calib;
	int rounds;

	Gun(double calib, int rounds) : Weapon("bullets") {
		this->calib = calib;
		this->rounds = rounds;
	}
	virtual ~Gun() {}
public:
	void getDetails() override {
		std::cout << "Gun with " << this->rounds << " " << this->ammoType << " of " << this->calib << " caliber\n";
	}
};

class Rifle : public Gun {
protected:
	virtual ~Rifle() {}
public:
	Rifle(int rounds) : Gun(7.62, rounds) {}

	void fireWeapon() override {
		this->rounds -= 1;
	}
};

class MachineGun : public Rifle {
public:
	MachineGun() : Rifle(30) {}

	void fireWeapon() override {
		this->rounds -= 3;
	}
};

int main() {
	Weapon *MG = new MachineGun();
	MG->fireWeapon();
	MG->fireWeapon();
	MG->getDetails();

	Weapon *NB = new AtomicBomb();
	NB->getDetails();
	NB->fireWeapon();

	Sling S(4);
	S.getDetails();
	S.fireWeapon();
	S.getDetails();

	return 0;
}
