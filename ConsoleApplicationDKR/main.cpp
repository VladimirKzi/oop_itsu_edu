// ConsoleApplicationDKR.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

template<typename T>
class CircularList {
	struct Node {
		T data;
		Node* next;
		Node(T d) : data(d), next(nullptr) {}
	};
	Node* head = nullptr;
	size_t count = 0;
public:
	void insert(T data) {
		Node* newNode = new Node(data);
		if (!head) { head = newNode; newNode->next = head; }
		else { newNode->next = head->next; head->next = newNode; head = newNode; }
		++count;
	}
	void remove(T data) {
		if (!head) return;
		Node* curr = head, *prev = nullptr;
		do {
			if (curr->data == data) {
				if (prev) prev->next = curr->next;
				else head = curr->next;
				delete curr; --count; return;
			}
			prev = curr; curr = curr->next;
		} while (curr != head);
	}
	void print() {
		if (!head) return;
		Node* curr = head->next;
		do {
			std::cout << curr->data << " ";
			curr = curr->next;
		} while (curr != head->next);
		std::cout << std::endl;
	}
	size_t size() { return count; }
	~CircularList() { /* delete nodes */ }
};


int main()
{
	SetConsoleOutputCP(1251);

	CircularList<int> list;

	list.insert(100);
	list.insert(20);
	list.insert(25);
	list.insert(80);
	list.insert(50);

	std::cout << "Список: ";
	list.print();

	std::cout << "Кільк. елементів: " << list.size() << "\n\n";

	list.remove(25);
	list.remove(80);

	std::cout << "Після видалення: ";
	list.print();

	std::cout << "Кількість елементів: " << list.size() << "\n";

	CircularList<std::string> names;
	names.insert("Volodymyr");
	names.insert("Olena");
	names.insert("Oleksandr");

	std::cout << "\nІмена: ";
	names.print();

	return 0;
}
