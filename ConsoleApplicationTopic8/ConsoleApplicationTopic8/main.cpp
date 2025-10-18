// ConsoleApplicationTopic8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;

// ===== Task 1 =====
class Complex {
private:
	double real;
	double imag;

public:
	Complex(double r = 0, double i = 0) : real(r), imag(i) {}

	void display() const {
		if (imag >= 0)
			cout << real << " + " << imag << "i";
		else
			cout << real << " - " << fabs(imag) << "i";
	}

	// Додавання
	Complex operator+(const Complex& other) const {
		return Complex(real + other.real, imag + other.imag);
	}

	// Віднімання
	Complex operator-(const Complex& other) const {
		return Complex(real - other.real, imag - other.imag);
	}

	// Множення
	Complex operator*(const Complex& other) const {
		return Complex(real * other.real - imag * other.imag,
			real * other.imag + imag * other.real);
	}

	// Ділення
	Complex operator/(const Complex& other) const {
		double denom = other.real * other.real + other.imag * other.imag;
		return Complex((real * other.real + imag * other.imag) / denom,
			(imag * other.real - real * other.imag) / denom);
	}

	// Спряжене число
	Complex conjugate() const {
		return Complex(real, -imag);
	}

	// Піднесення до степеня n
	Complex power(int n) const {
		double r = pow(sqrt(real * real + imag * imag), n);
		double theta = atan2(imag, real) * n;
		return Complex(r * cos(theta), r * sin(theta));
	}

	// Квадратний корінь
	Complex sqrtC() const {
		double r = sqrt(sqrt(real * real + imag * imag));
		double theta = atan2(imag, real) / 2;
		return Complex(r * cos(theta), r * sin(theta));
	}
};

void task1()
{
	Complex a(3, 4), b(1, -2);

	cout << "a = "; a.display(); cout << endl;
	cout << "b = "; b.display(); cout << endl;

	cout << "\nДодавання: "; (a + b).display();
	cout << "\nВіднімання: "; (a - b).display();
	cout << "\nМноження: "; (a * b).display();
	cout << "\nДілення: "; (a / b).display();
	cout << "\nСпряжене до a: "; a.conjugate().display();
	cout << "\nПіднесення a до степеня 2: "; a.power(2).display();
	cout << "\nКвадратний корінь з a: "; a.sqrtC().display();
	cout << endl;
}

// ===== Task 2 =====
class Train {
public:
	string destination;
	int number;
	double departure;

	void input() {
		cout << "Пункт призначення: ";
		cin >> destination;
		cout << "Номер потяга: ";
		cin >> number;
		cout << "Час відправлення (години, наприклад 14.30): ";
		cin >> departure;
	}

	void print() const {
		cout << "Поїзд №" << number
			<< " | Пункт: " << destination
			<< " | Час відправлення: " << departure << endl;
	}
};

void task2()
{
	const int N = 5;
	Train trains[N];

	cout << "Введіть дані про 5 потягів:\n";
	for (int i = 0; i < N; i++) {
		cout << "\nПотяг " << i + 1 << ":\n";
		trains[i].input();
	}

	// --- Сортування за номером потяга ---
	sort(trains, trains + N, [](const Train &a, const Train &b) {
		return a.number < b.number;
		});

	cout << "\nСписок потягів (за номером):\n";
	for (auto &t : trains)
		t.print();

	// --- Пошук потяга за номером ---
	int searchNum;
	cout << "\nВведіть номер потяга для пошуку: ";
	cin >> searchNum;

	bool found = false;
	for (auto &t : trains)
		if (t.number == searchNum) {
			cout << "Знайдено потяг:\n";
			t.print();
			found = true;
			break;
		}

	if (!found) cout << "Потяг не знайдено.\n";

	// --- Сортування за пунктом призначення ---
	sort(trains, trains + N, [](const Train &a, const Train &b) {
		if (a.destination == b.destination)
			return a.departure < b.departure;
		return a.destination < b.destination;
		});

	cout << "\nСписок потягів (за пунктом призначення і часом):\n";
	for (auto &t : trains)
		t.print();
}

// ===== Task 3 =====
class Pair {
private:
	double a, b;

public:
	Pair(double x = 0, double y = 0) : a(x), b(y) {}

	void print() const {
		cout << "a = " << a << ", b = " << b << endl;
	}

	void setValues(double x, double y) {
		a = x;
		b = y;
	}

	double sum() const {
		return a + b;
	}

	double maxValue() const {
		return (a > b) ? a : b;
	}
};

void task3()
{
	Pair p(5, 9);
	cout << "Початкові значення:\n";
	p.print();

	cout << "\nЗмінимо значення (2.5, 4.5):\n";
	p.setValues(2.5, 4.5);
	p.print();

	cout << "\nСума = " << p.sum() << endl;
	cout << "Найбільше значення = " << p.maxValue() << endl;
}

// ===== Main menu =====
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	do {
		std::cout << "\nВиберіть завдання (1, 2, 3, 0 = вихід): ";
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
