// ConsoleApplicationSem2Topic3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

// ===== Task 1 =====
double power(double n, int p = 2)
{
	double res = 1.0;

	for (int i = 0; i < p; i++)
	{
		res *= n;
	}

	return res;
}

void task1()
{
	double n;
	int exp;

	cout << "Введіть число: ";
	cin >> n;

	cout << "Введіть степінь (0 - за замовчуванням 2): ";
	cin >> exp;

	if (exp == 0)
	{
		cout << "Результат: " << power(n) << endl;
	} else {
		cout << "Результат: " << power(n, exp) << endl;
	}
}

// ===== Task 2 =====
void zeroSmaller(int& a, int& b)
{
	if (a < b)
	{
		a = 0;
	} else if (b < a) {
		b = 0;
	} else {
		a = 0;
		b = 0;
	}
}

void task2()
{
	int x, y;

	cout << "Введіть два числа: ";
	cin >> x >> y;

	zeroSmaller(x, y);

	cout << "Результат:" << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}

// ===== Task 3 =====
struct Distance
{
	int meters;
	float centimeters;
};

Distance maxDistance(Distance d1, Distance d2)
{
	float total1 = d1.meters * 100 + d1.centimeters;
	float total2 = d2.meters * 100 + d2.centimeters;

	if (total1 > total2)
	{
		return d1;
	}
	else {
		return d2;
	}
}

void task3()
{
	Distance d1, d2, result;

	cout << "Введіть першу відстань (м см): ";
	cin >> d1.meters >> d1.centimeters;

	cout << "Введіть другу відстань (м см): ";
	cin >> d2.meters >> d2.centimeters;

	result = maxDistance(d1, d2);

	cout << "Більша відстань: " << result.meters << " м " << result.centimeters << " см" << endl;
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
