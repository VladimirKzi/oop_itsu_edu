// ConsoleApplicationLab6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

// ===== Task 1 =====
class Time {
private:
	int hours;
	int minutes;
	int seconds;

	void normalize() {
		if (seconds >= 60) {
			minutes += seconds / 60;
			seconds %= 60;
		}
		else if (seconds < 0) {
			int borrow = (-seconds + 59) / 60;
			minutes -= borrow;
			seconds += borrow * 60;
		}

		if (minutes >= 60) {
			hours += minutes / 60;
			minutes %= 60;
		}
		else if (minutes < 0) {
			int borrow = (-minutes + 59) / 60;
			hours -= borrow;
			minutes += borrow * 60;
		}

		if (hours >= 24) hours %= 24;
		if (hours < 0) hours = (hours % 24 + 24) % 24;
	}

public:
	Time() : hours(0), minutes(0), seconds(0) {}

	Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
		normalize();
	}

	~Time() {
	}

	void input() {
		cout << "Введіть години, хвилини, секунди: ";
		cin >> hours >> minutes >> seconds;
		normalize();
	}

	void display() const {
		cout << setfill('0') << setw(2) << hours << ":"
			<< setw(2) << minutes << ":"
			<< setw(2) << seconds << endl;
	}

	void timeToMidnight() const {
		int totalSec = hours * 3600 + minutes * 60 + seconds;
		int remain = 24 * 3600 - totalSec;

		int h = remain / 3600;
		int m = (remain % 3600) / 60;
		int s = remain % 60;

		cout << "До завершення доби залишилось: "
			<< h << " год " << m << " хв " << s << " сек.\n";
	}

	Time operator+(int sec) const {
		Time t(hours, minutes, seconds + sec);
		t.normalize();
		return t;
	}

	Time operator-(int sec) const {
		Time t(hours, minutes, seconds - sec);
		t.normalize();
		return t;
	}
};

void task1()
{
	Time t1;
	t1.input();

	cout << "Поточний час: ";
	t1.display();

	t1.timeToMidnight();

	cout << "\nДодаємо 500 секунд:\n";
	Time t2 = t1 + 500;
	t2.display();

	cout << "Віднімаємо 1000 секунд:\n";
	Time t3 = t1 - 1000;
	t3.display();
}

// ===== Task 2 =====
class Circle {
private:
	double x, y;
	double r;

public:
	Circle() : x(0), y(0), r(0) {}

	Circle(double _x, double _y, double _r) : x(_x), y(_y), r(_r) {
		if (r < 0) r = 0;
	}

	~Circle() {
	}

	void input() {
		cout << "Введіть координати центру (x, y) і радіус: ";
		cin >> x >> y >> r;
		if (r < 0) r = 0;
	}

	void display() const {
		cout << "Коло: центр (" << x << ", " << y << "), радіус = " << r << endl;
	}

	double area() const {
		return M_PI * r * r;
	}

	double length() const {
		return 2 * M_PI * r;
	}

	Circle operator*(double k) const {
		return Circle(x, y, r * k);
	}

	Circle operator/(double k) const {
		if (k == 0) {
			cout << "Помилка: ділення на нуль!\n";
			return *this;
		}
		return Circle(x, y, r / k);
	}
};

void task2()
{
	Circle c1;
	c1.input();
	c1.display();

	cout << "Площа = " << c1.area() << endl;
	cout << "Довжина кола = " << c1.length() << endl;

	cout << "\nМножимо радіус на 2:\n";
	Circle c2 = c1 * 2;
	c2.display();

	cout << "Ділимо радіус на 2:\n";
	Circle c3 = c1 / 2;
	c3.display();
}

// ===== Main menu =====
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	do {
		std::cout << "\nВиберіть завдання (1, 2, 0 = вихід): ";
		std::cin >> choice;
		switch (choice) {
		case 1: task1(); break;
		case 2: task2(); break;
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
