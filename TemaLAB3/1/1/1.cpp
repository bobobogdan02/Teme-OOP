// 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string.h>
using namespace std;

class Student {
public:
	int grade;
	string group;
	Student() {
		group = 'A';
	}

	int getGrade() {
		return grade;
	}

	void setGrade(int grade) {
		this->grade = grade;
	}
};


int main()
{
	int grade1, grade2;
	Student student1;
	Student *student2;
	student2 = new Student;
	cin >> grade1;
	student1.setGrade(grade1);
	cin >> grade2;
	student2->grade = grade2;
	cout << "Nota student 1 = " << student1.getGrade() << endl;
	cout << "Nota student 2 = " << student2->grade;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
