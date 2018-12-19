// aistrd_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "List.h"
using namespace std;

int main()
{
	cout << "Find last list" << endl;
	List *lst = new List();
	List *lst2 = new List();
	lst->push_front(6);
	lst->push_front(4);
	lst->push_front(6);
	lst->push_front(4);
	lst->push_front(6);
	lst->push_front(4);
	lst->push_front(6);
	lst->push_front(4);




	lst2->push_front(4);
	lst2->push_front(6);

	//lst->print_to_console();
	lst->find_last(lst2);
	cout << endl;
	int x;
	List elem;
	cout << "Fill List" << endl;
	elem.push_front(12);
	elem.push_front(2);
	elem.push_front(3);
	elem.push_back(7);
	elem.print_to_console();
	cout << endl;
	cout << "Insert in List elem value 0 in position 3" << endl;
	elem.insert(0, 3);
	elem.print_to_console();
	cout << endl;
	cout << "Delete first elem" << endl;
	elem.pop_front();
	elem.print_to_console();
	cout << endl;
	cout << "Delete last elem" << endl;
	elem.pop_back();
	elem.print_to_console();





	system("pause");


	return 0;
}

