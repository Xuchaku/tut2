#pragma once
#include "stdafx.h"
#include "iostream"
using namespace std;
class List {




public:
	void push_back(int); // добавление в конец списка
	void push_front(int); // добавление в начало списка
	void pop_back(); // удаление последнего элемента
	void pop_front(); // удаление первого элемента
	void insert(int, int); // добавление элемента по индексу
	int at(int); // получение элемента по индексу
	void delete_elem(int); // удаление элемента по индексу
	int get_size(); // получение размера списка
	void print_to_console(); // вывод элементов списка в консоль через
	void clear(); // удаление всех элементов списка
	void set(int, int); // замена элемента по индексу на передаваемый
	bool isEmpty(); // проверка на пустоту списка
	int find_last(List *twoList);// поиск последнего вхождения другого списка в список
	List();
	~List();
private:
	class Node {
	public:
		int value;
		Node *next;
		Node(int val, Node *ne = nullptr) {
			this->value = val;
			this->next = ne;
		}
	};
	Node *head;
	int size;
};