// ConsoleApplicationModule1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>

using namespace std;

// ===== Task1 =====
class University {
protected:
	string name;
public:
	University(string n = "Невідомий університет") : name(n) {}
	virtual void Show() {
		cout << "Університет: " << name << endl;
	}
	virtual ~University() {}
};

class Faculty : public University {
protected:
	string facultyName;
public:
	Faculty(string u, string f) : University(u), facultyName(f) {}
	void Show() override {
		cout << "Університет: " << name
			<< ", Факультет: " << facultyName << endl;
	}
};

class Department : public Faculty {
	string departmentName;
public:
	Department(string u, string f, string d)
		: Faculty(u, f), departmentName(d) {}

	void Show() override {
		cout << "Університет: " << name
			<< ", Факультет: " << facultyName
			<< ", Кафедра: " << departmentName << endl;
	}
};

void task1()
{
	University* arr[3];
	arr[0] = new University("МНТУ");
	arr[1] = new Faculty("МНТУ", "Інженерія програмного забезпечення");
	arr[2] = new Department("МНТУ", "Інженерія програмного забезпечення", "Інформатики");

	for (int i = 0; i < 3; i++)
		arr[i]->Show();

	for (int i = 0; i < 3; i++)
		delete arr[i];
}

// ===== Task2 =====
class RotationFigure {
public:
	virtual double Volume() = 0;
	virtual void Show() = 0;
	virtual ~RotationFigure() {}
};

class Cone : public RotationFigure {
	double r, h;
public:
	Cone(double r, double h) : r(r), h(h) {}

	double Volume() override {
		return (1.0 / 3) * 3.14159 * r * r * h;
	}

	void Show() override {
		cout << "Конус: r = " << r
			<< ", h = " << h
			<< ", V = " << Volume() << endl;
	}
};

void task2()
{
	RotationFigure* figs[2];
	figs[0] = new Cone(3, 5);
	figs[1] = new Cone(2, 4);

	for (int i = 0; i < 2; i++)
		figs[i]->Show();

	for (int i = 0; i < 2; i++)
		delete figs[i];
}

// ===== Task3 =====
template <typename T>
void FindInRange(T arr[], int size, T min, T max)
{
	cout << "Елементи в діапазоні [" << min << "; " << max << "]: ";
	for (int i = 0; i < size; i++)
		if (arr[i] >= min && arr[i] <= max)
			cout << arr[i] << " ";
	cout << endl;
}

void task3()
{
	int a[] = { 1, 5, 10, 15, 20 };
	double b[] = { 1.2, 3.5, 7.8, 9.1 };

	FindInRange(a, 5, 5, 15);
	FindInRange(b, 4, 2.0, 8.0);
}

// ===== Task4 =====
template <class T1, class T2>
class Pair {
	T1 first;
	T2 second;
public:
	Pair(T1 a, T2 b) : first(a), second(b) {}

	void Show() {
		cout << "Пара: " << first << " , " << second << endl;
	}
};

void task4()
{
	Pair<int, double> p1(5, 3.14);
	Pair<string, int> p2("Age", 20);

	p1.Show();
	p2.Show();
}

// ===== Main menu =====
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "=== TASK1: Ієрархія Університет ===\n";
	task1();

	cout << "\n=== TASK2: Фігури обертання ===\n";
	task2();

	cout << "\n=== TASK3: Шаблонна функція ===\n";
	task3();

	cout << "\n=== TASK4: Шаблон класу ===\n";
	task4();

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
