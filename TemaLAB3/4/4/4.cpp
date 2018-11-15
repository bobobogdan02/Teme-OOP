// 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

class Student3
{
	struct Node
	{
		int data;
		Node *next;
	};
private:
	Node *head;
public:
	static int count2;
	Student3()
	{
		head = NULL;
	}
	void addValue(int val)
	{
		Node *n = new Node();
		n->data = val;
		n->next = head;
		head = n;
		count2++;
	}
	void display()
	{
		while (head != NULL)
		{
			cout << head->data << " ";
			head = head->next;
		}
		cout << "\n";
	}
};

int main()
{
	Student3 s1;
	s1.addValue(5);
	s1.addValue(20);
	s1.addValue(10);
	cout << "Number of elements in list:" << s1.count2 << '\n';
	s1.display();

}
