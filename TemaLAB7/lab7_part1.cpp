#include <iostream>
#include <string>
#include <list>
#include <utility>

class Person {
	std::string name;
	int age;
public:
	Person(std::string name, int age) {
		this->name = name;
		this->age = age;
	}
	void setName(std::string name) {
		this->name = name;
	}
	void setAge(int age) {
		this->age = age;
	}
	std::string getName() {
		return this->name;
	}
	int getAge() {
		return this->age;
	}
};

class Driver : public Person {
	std::string carDriven;
public:
	Driver(std::string name, int age, std::string carDriven)
		: Person(name, age) {
		this->carDriven = carDriven;
	}
	void setCar(std::string carDriven) {
		this->carDriven = carDriven;
	}
	std::string getCar() {
		return this->carDriven;
	}
};

class Employee : public Driver {
	std::string company;
	int wage;
public:
	Employee(std::string name, int age, std::string car, std::string company, int wage)
		: Driver(name, age, car) {
		this->company = company;
		this->wage = wage;
	}
	void setCompany(std::string company) {
		this->company = company;
	}
	void setWage(int wage) {
		this->wage = wage;
	}
	std::string getCompany() {
		return this->company;
	}
	int getWage() {
		return this->wage;
	}
};

class Child : public Person {
	std::string school;

	friend class Parent;
public:
	Child(std::string name, int age, std::string school)
		: Person(name, age) {
		this->school = school;
	}
	std::string getSchool() {
		return this->school;
	}
protected:
	void setSchool(std::string school) {
		this->school = school;
	}
};

class Parent : public Employee {
	std::list<Child> children;
public:
	Parent(std::string name, int age, std::string car, std::string company, int wage,
		std::list<Child> children) : Employee(name, age, car, company, wage) {
		this->children = children;
	}
	void addChild(Child child) {
		this->children.push_back(child);
	}
	std::list<Child> getChildren() {
		return this->children;
	}
	void changeChildSchool(std::string name, std::string newSchool) {
		for (auto child : this->children) {
			if (child.getName() == name) {
				child.setSchool(newSchool);
			}
		}
	}
};

int main() {
	Driver *driver = new Driver("driver1", 20, "car1");
	driver->setAge(25);
	delete driver;

	Employee *employee = new Employee("employee1", 25, "car2", "company1", 1000);
	employee->setWage(2500);
	employee->setAge(30);
	delete employee;

	std::unique_ptr<Child> child1 = std::make_unique<Child>("child1", 10, "school1");
	std::unique_ptr<Child> child2 = std::make_unique<Child>("child2", 5, "school2");
	std::unique_ptr<Child> child3 = std::make_unique<Child>("child3", 15, "school1");

	child2->setName("child5");

	std::list<Child> childrenList;
	childrenList.push_back(*child1);
	childrenList.push_back(*child2);
	childrenList.push_back(*child3);

	std::unique_ptr<Parent> parent =
		std::make_unique<Parent>("parent1", 40, "car1", "comp1", 2500, childrenList);

	parent->changeChildSchool("child3", "school666");

	auto newList = parent->getChildren();

	for (auto child : newList) {
		std::cout << child.getName() << " " << child.getSchool() << "\n";
	}

	return 0;
}