#include "stdafx.h"
#include "List.h"
void List::push_back(int val) {
	this->size++;
	if (!this->head) {
		//если список пуст
		this->head = new Node(val, nullptr);
	}
	else {
		//если список не пуст, производится поиск последнего элемента и установка его указателя но новый созданный элемент
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
		//если список был пуст
		this->head = new Node(val, nullptr);

	}
	else {
		//если список не пуст
		Node *new_elem = new Node(val, this->head);
		this->head = new_elem;
	}
}
void List::pop_back() {
	if (this->head) {
		//если список не пуст
		Node *current = this->head;
		if (current->next) {
			for (int i = 1; i < this->size - 1; i++)
				current = current->next;

			current->next = nullptr;
			//установка у предпоследнего элемента указателя в null

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
		//если первый элемент есть

		Node *current = this->head;
		if (current->next) {
			//если есть и последующий элемент, производится перестановка указателя на 2 элемент
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
		this->push_back(val);//Если индекс больше вызываем функцию добавление последнего элемента
	else if (index <= 1)//Если индекс меньше или равен 1 вызываем функцию добавление первого  элемента
		this->push_front(val);
	else {
		//Если индекс находится в интервале,производится поиск предшествубщего элемента и перестановка указателей
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
		Node *current = this->head;//Если индекс лежит в пределах, производится поиск элемента и получение его содержимого
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
	//Если индекс 1 вызываем функцию удаления первого элемента
	if (index == 1)
		this->pop_front();
	else if (index == this->size)//Если индекс равен кол-ву элементов вызываем функцию удаления последнего элемента
		this->pop_back();
	else if (index < this->size && index > 0) {
		//Если индекс лежит в пределах,производится поиск последующего и предшествующего элемента и переставление указателей
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
	//Взятие головного элемента и пробежка по списку,вывод элементов
	Node *tmp = this->head;
	while (tmp) {
		cout << tmp->value;
		cout << " ";
		tmp = tmp->next;
	}
}
void List::clear() {

	//Цикл очистки списка
	while (this->head) {
		Node *current = this->head;
		this->head = current->next;
		free(current);
		this->size--;
	}

}
void List::set(int index, int val) {
	//проверка на ограниченность 
	if (index <= this->size && index >= 1) {
		Node *current = this->head;
		//нахождение нужного элемента по индексу
		for (int i = 1; i < index; i++)
			current = current->next;
		//Замена значения
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
	//инициализация счетчика кол-ва элементов и указателя на начало

}
List::~List() {
	clear();//освобождение памяти
}
