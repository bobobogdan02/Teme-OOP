#include <iostream>
#include <string>
#include <list>
#include <vector>

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

class Driver {
	std::string car;

	Driver(std::string car) {
		this->car = car;
	}
	void setCar(std::string car) {
		this->car = car;
	}
	std::string getCar() {
		return this->car;
	}

	friend class Student;
};

class StudentList {
	class Student : public Person {
		std::string idNum;

		Student(std::string name, int age, std::string idNum) :
			Person(name, age) {
			this->idNum = idNum;
		}

		void setId(std::string idNum) {
			this->idNum = idNum;
		}

		friend class StudentList;
	public:
		std::string getId() {
			return this->idNum;
		}

		bool operator==(Student stud1) {
			return this->getName() == stud1.getName();
		}
	};

	int noGroups;
	std::vector<std::list<Student>> *group;
public:

	StudentList(int noGroups) {
		this->noGroups = noGroups;
		this->group = new std::vector<std::list<Student>>(noGroups);
	}

	~StudentList() {
		delete group;
	}

	void addStudent(std::string name, int age, std::string idNum, int groupNo) {
		if (groupNo > this->noGroups) {
			return;
		}
		this->group->at(groupNo).push_back(Student(name, age, idNum));
	}

	std::list<Student> getStudents(int groupNo) {
		return this->group->at(groupNo);
	}

	void updateId(std::string name, int groupNo) {
		for (auto &it : this->group->at(groupNo)) {
			if (it.getName() == name) {
				int tempId = std::stoi(it.getId());
				tempId += 100;
				it.idNum = std::to_string(tempId);
			}
		}
	}

	void moveStudent(std::string name, int initGroup, int newGroup) {
		for (auto &it : this->group->at(initGroup)) {
			if (it.getName() == name) {
				this->group->at(newGroup).push_back(it);
				this->group->at(initGroup).remove(it);
				return;
			}
		}
	}
};

int main() {
	StudentList *SL = new StudentList(2);
	SL->addStudent("stud1", 20, "100", 0);
	SL->addStudent("stud2", 20, "101", 0);
	SL->addStudent("stud3", 20, "102", 0);
	SL->addStudent("stud4", 20, "204", 1);
	SL->addStudent("stud5", 20, "205", 1);
	
	for (auto student : SL->getStudents(0)) {
		std::cout << student.getName() << " " << student.getId() << "\n";
	}
	std::cout << "\n";
	for (auto student : SL->getStudents(1)) {
		std::cout << student.getName() << " " << student.getId() << "\n";
	}

	SL->moveStudent("stud1", 0, 1);
	SL->updateId("stud1", 1);
	
	std::cout << "\n";
	for (auto student : SL->getStudents(0)) {
		std::cout << student.getName() << " " << student.getId() << "\n";
	}
	std::cout << "\n";
	for (auto student : SL->getStudents(1)) {
		std::cout << student.getName() << " " << student.getId() << "\n";
	}

	delete SL;
	return 0;
}