#include "stdafx.h"
#include "List.h"
void List::push_back(int val) {
	this->size++;
	if (!this->head) {
		//���� ������ ����
		this->head = new Node(val, nullptr);
	}
	else {
		//���� ������ �� ����, ������������ ����� ���������� �������� � ��������� ��� ��������� �� ����� ��������� �������
		Node *current = this->head;
		while (current->next) {
			current = current->next;
		}
		current->next = new Node(val, nullptr);

	}
}
void List::push_front(int val) {
	this->size++;
	if (!this->head) {
		//���� ������ ��� ����
		this->head = new Node(val, nullptr);

	}
	else {
		//���� ������ �� ����
		Node *new_elem = new Node(val, this->head);
		this->head = new_elem;
	}
}
void List::pop_back() {
	if (this->head) {
		//���� ������ �� ����
		Node *current = this->head;
		if (current->next) {
			for (int i = 1; i < this->size - 1; i++)
				current = current->next;

			current->next = nullptr;
			//��������� � �������������� �������� ��������� � null

		}
		else
			this->head = nullptr;
		this->size--;
	}
	else {
		throw out_of_range("No elements");
	}
}
void List::pop_front() {
	if (this->head) {
		//���� ������ ������� ����

		Node *current = this->head;
		if (current->next) {
			//���� ���� � ����������� �������, ������������ ������������ ��������� �� 2 �������
			current = current->next;
			this->head = current;
		}
		else
			this->head = nullptr;
		this->size--;
	}
	else {
		throw out_of_range("No elements");
	}
}
void List::insert(int val, int index) {
	if (index > this->size)
		this->push_back(val);//���� ������ ������ �������� ������� ���������� ���������� ��������
	else if (index <= 1)//���� ������ ������ ��� ����� 1 �������� ������� ���������� �������  ��������
		this->push_front(val);
	else {
		//���� ������ ��������� � ���������,������������ ����� ��������������� �������� � ������������ ����������
		Node *current = this->head;
		for (int i = 1; i < index - 1; i++)
			current = current->next;
		Node *current2 = current->next;
		current->next = new Node(val, current2);
		this->size++;


	}
}
int List::at(int index) {
	if (index <= this->size && index >= 1) {
		Node *current = this->head;//���� ������ ����� � ��������, ������������ ����� �������� � ��������� ��� �����������
		for (int i = 1; i < index; i++)
			current = current->next;
		return current->value;
	}
	else {
		throw out_of_range("Index incorrect");
		return -1;
	}

}
void List::delete_elem(int index) {
	//���� ������ 1 �������� ������� �������� ������� ��������
	if (index == 1)
		this->pop_front();
	else if (index == this->size)//���� ������ ����� ���-�� ��������� �������� ������� �������� ���������� ��������
		this->pop_back();
	else if (index < this->size && index > 0) {
		//���� ������ ����� � ��������,������������ ����� ������������ � ��������������� �������� � ������������� ����������
		Node *current = this->head;
		for (int i = 1; i < index - 1; i++) {
			current = current->next;
		}

		Node *current2 = current->next;
		current->next = current2->next;
		current2->next = nullptr;
	}
	else {
		throw out_of_range("Incorrect index");
	}
}
int List::get_size() {
	return this->size;
}
void List::print_to_console() {
	//������ ��������� �������� � �������� �� ������,����� ���������
	Node *tmp = this->head;
	while (tmp) {
		cout << tmp->value;
		cout << " ";
		tmp = tmp->next;
	}
}
void List::clear() {

	//���� ������� ������
	while (this->head) {
		Node *current = this->head;
		this->head = current->next;
		free(current);
		this->size--;
	}

}
void List::set(int index, int val) {
	//�������� �� �������������� 
	if (index <= this->size && index >= 1) {
		Node *current = this->head;
		//���������� ������� �������� �� �������
		for (int i = 1; i < index; i++)
			current = current->next;
		//������ ��������
		current->value = val;

	}
	else {
		throw out_of_range("Index incorrect");
	}
}
int List::find_last(List *twoList) {

	if (twoList->size <= this->size && twoList->size > 0) {
		int count = 0;
		int j = 0;
		int in_list = 0;
		int iter = this->size - twoList->size + 1;
		Node *currentTwo = this->head;

		//Node *run = twoList->head;
		for (int i = 0; i < iter; i++) {
			Node *current = twoList->head;
			while (current) {

				if (current->value == currentTwo->value) {
					current = current->next;
					currentTwo = currentTwo->next;
					count++;
				}
				else {
					break;
				}
			}
			if (count == twoList->size) {
				system("cls");
				cout << "Firt List:";
				twoList->print_to_console();
				cout << endl;
				cout << "Two List:";
				this->print_to_console();
				cout << endl;
				cout << "Last entry 1 List in 2 List position: ";
				cout << i + 1;
				in_list = 1;
				j = i + 1;


			}
			count = 0;
			currentTwo = this->head;
			for (int k = i; k >= 0; k--)
				currentTwo = currentTwo->next;


		}
		if (!in_list) {
			cout << "Firt List:";
			twoList->print_to_console();
			cout << endl;
			cout << "Two List:";
			this->print_to_console();
			cout << endl;
			cout << "No occurrences found 1-List in 2-List";
			return -1;
		}
		else return j;
	}
	else {

		throw out_of_range("Onelst grow twolst\n");
		return -1;
	}
}
bool List::isEmpty() {

	if (!this->head)
		return 0;
	else return this->size;
}
List::List() {
	this->size = 0;
	this->head = nullptr;
	//������������� �������� ���-�� ��������� � ��������� �� ������

}
List::~List() {
	clear();//������������ ������
}
