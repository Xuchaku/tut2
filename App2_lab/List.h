#pragma once
#include "stdafx.h"
#include "iostream"
using namespace std;
class List {




public:
	void push_back(int); // ���������� � ����� ������
	void push_front(int); // ���������� � ������ ������
	void pop_back(); // �������� ���������� ��������
	void pop_front(); // �������� ������� ��������
	void insert(int, int); // ���������� �������� �� �������
	int at(int); // ��������� �������� �� �������
	void delete_elem(int); // �������� �������� �� �������
	int get_size(); // ��������� ������� ������
	void print_to_console(); // ����� ��������� ������ � ������� �����
	void clear(); // �������� ���� ��������� ������
	void set(int, int); // ������ �������� �� ������� �� ������������
	bool isEmpty(); // �������� �� ������� ������
	int find_last(List *twoList);// ����� ���������� ��������� ������� ������ � ������
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