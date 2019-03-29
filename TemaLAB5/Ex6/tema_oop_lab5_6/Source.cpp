#include <iostream>
#include <string>
#include <list>

class Dessert {
private:
	std::string name;
	int nrCal;
public:
	Dessert(std::string name, int nrCal) {
		this->name = name;
		this->nrCal = nrCal;
	}
	void setName(std::string name) {
		this->name = name;
	}
	void setCal(int nrCal) {
		this->nrCal = nrCal;
	}
	std::string getName() {
		return this->name;
	}
	int getCal() {
		return this->nrCal;
	}
	void modPrep() {
		std::cout << "Ingrediente necesare:\n";
	}
};

class Prajitura : public Dessert {
private:
	std::list<std::string> ing;
public:
	Prajitura(std::string name, int nrCal, std::list<std::string> ing) : Dessert(name, nrCal) {
		this->ing = ing;
	}
	void setIng(std::list<std::string> ing) {
		this->ing = ing;
	}
	void modPrep() {
		Dessert::modPrep();
		for (std::string it : this->ing) {
			std::cout << it << "\n";
		}
	}
};

class Tort : public Dessert {
private:
	std::list<std::string> ing;
public:
	Tort(std::string name, int nrCal, std::list<std::string> ing) : Dessert(name, nrCal) {
		this->ing = ing;
	}
	void setIng(std::list<std::string> ing) {
		this->ing = ing;
	}
	void modPrep() {
		Dessert::modPrep();
		for (std::string it : this->ing) {
			std::cout << it << "\n";
		}
	}
};

class Briosa : public Prajitura {
private:
	std::string form;
public:
	Briosa(std::string form, std::string name, int nrCal, std::list<std::string> ing) :
		Prajitura(name, nrCal, ing) {
		this->form = form;
	}
	void setForm(std::string form) {
		this->form = form;
	}
	std::string getForm() {
		return this->form;
	}
};

int main() {
	std::list<std::string> ingBriosa;
	ingBriosa.push_back("faina");
	ingBriosa.push_back("ciocolata");

	Briosa b("cerc", "briosa", 450, ingBriosa);

	std::cout << b.getName() << " " << b.getCal() << " kcal " << b.getForm() << "\n";
	b.modPrep();

	std::list<std::string> ingTort;
	ingTort.push_back("faina");
	ingTort.push_back("fructe");
	ingTort.push_back("oua");

	Tort t("tort diplomat", 1340, ingTort);

	std::cout << t.getName() << " " << t.getCal() << " kcal \n";
	t.modPrep();

	return 0;
}