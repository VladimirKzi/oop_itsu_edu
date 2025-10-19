// ConsoleApplicationTopic9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

// ===== Task 1 =====
void task1()
{
	double S;
	cout << "Введіть площу квадрата: ";
	cin >> S;

	if (S <= 0) {
		cout << "Площа має бути додатною!\n";
		return;
	}

	double a = sqrt(S);
	double P = 4 * a;

	cout << "Сторона квадрата = " << a << endl;
	cout << "Периметр квадрата = " << P << endl;
}

// ===== Task 2 =====
void task2()
{
	const double PI = 3.1415926535;
	double R, r;
	cout << "Введіть зовнішній радіус R: ";
	cin >> R;
	cout << "Введіть внутрішній радіус r: ";
	cin >> r;

	if (R <= 0 || r <= 0 || R <= r) {
		cout << "Має бути R > r > 0!\n";
		return;
	}

	double S = PI * (R * R - r * r);
	cout << "Площа кільця = " << S << endl;
}

// ===== Task 3 =====
void task3()
{
	double a, b;
	cout << "Введіть катети трикутника (a, b): ";
	cin >> a >> b;

	if (a <= 0 || b <= 0) {
		cout << "Катети повинні бути додатними!\n";
		return;
	}

	double c = sqrt(a * a + b * b);
	double P = a + b + c;

	cout << "Гіпотенуза = " << c << endl;
	cout << "Периметр трикутника = " << P << endl;
}

// ===== Task 4 =====
void task4()
{
	int n;
	cout << "Введіть двоцифрове число: ";
	cin >> n;

	if (n < 10 || n > 99) {
		cout << "Число має бути двоцифровим!\n";
		return;
	}

	int tens = n / 10;
	int ones = n % 10;
	int sum = tens + ones;
	int prod = tens * ones;

	cout << "Десятків: " << tens << endl;
	cout << "Одиниць: " << ones << endl;
	cout << "Сума цифр: " << sum << endl;
	cout << "Добуток цифр: " << prod << endl;
}

// ===== Main menu =====
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	do {
		std::cout << "\nВиберіть завдання (1, 2, 3, 4, 0 = вихід): ";
		std::cin >> choice;
		switch (choice) {
		case 1: task1(); break;
		case 2: task2(); break;
		case 3: task3(); break;
		case 4: task4(); break;
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
