// ConsoleApplicationSem2Topic2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

// ===== Task 1 =====
class Shape {
public:
	virtual void draw() {
		cout << "Малюється фігура" << endl;
	}
};

class Circle : public Shape {
public:
	void draw() override {
		cout << "Малюється коло" << endl;
	}
};

void task1() {
	Shape* p;        // покажчик на базовий клас
	Circle c;

	p = &c;          // p вказує на об’єкт похідного класу
	p->draw();      // виклик віртуальної функції
}

// ===== Task 2 =====
class Animal {
public:
	virtual void sound() {
		cout << "Тварина видає звук" << endl;
	}
};

class Dog : public Animal {
public:
	void sound() override {
		cout << "Собака гавкає" << endl;
	}
};

class Cat : public Animal {
public:
	void sound() override {
		cout << "Кішка нявкає" << endl;
	}
};

void makeSound(Animal* a) {   // покажчик на базовий клас
	a->sound();               // поліморфний виклик
}

void task2() {
	Dog d;
	Cat c;

	makeSound(&d);
	makeSound(&c);
}

// ===== Task 3 =====
class Vehicle {
public:
	virtual void move() {
		cout << "Транспорт рухається" << endl;
	}
};

class Car : public Vehicle {
public:
	void move() override {
		cout << "Автомобіль їде" << endl;
	}
};

class Bike : public Vehicle {
public:
	void move() override {
		cout << "Велосипед їде" << endl;
	}
};

class Garage {
public:
	void test(Vehicle& v) {   // посилання на базовий клас
		v.move();             // поліморфний виклик
	}
};

void task3() {
	Car car;
	Bike bike;
	Garage g;

	g.test(car);
	g.test(bike);
}

// ===== Main menu =====
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	do {
		std::cout << "\nВиберіть варіант (1, 2, 3, 0 = вихід): ";
		std::cin >> choice;
		switch (choice) {
		case 1: task1(); break;
		case 2: task2(); break;
		case 3: task3(); break;
		}
	} while (choice != 0);

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
