// ConsoleApplicationTopic10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>

using namespace std;

double f1(double x) { return sin(x); }
double f2(double x) { return cos(x); }
double f3(double x) { return exp(x); }
double f4(double x) { return x * x; }

void tabulate(double(*func)(double), double a, double b, double step) {
	cout << fixed << setprecision(5);
	cout << "\nТабулювання значень функції:\n";
	cout << " x\t|\tf(x)\n";
	cout << "----------------------\n";

	for (double x = a; x <= b; x += step) {
		cout << " " << setw(6) << x << "\t|\t" << setw(8) << func(x) << endl;
	}
}

double simpson(double(*func)(double), double a, double b, int n) {
	if (n % 2 != 0) n++;
	double h = (b - a) / n;
	double sum = func(a) + func(b);

	for (int i = 1; i < n; i++) {
		double x = a + i * h;
		sum += func(x) * (i % 2 == 0 ? 2 : 4);
	}

	return (h / 3) * sum;
}

double(*chooseFunction())(double) {
	int choice;
	cout << "\nОберіть функцію для обчислення:\n";
	cout << "1. sin(x)\n";
	cout << "2. cos(x)\n";
	cout << "3. e^x\n";
	cout << "4. x^2\n";
	cout << "Ваш вибір: ";
	cin >> choice;

	switch (choice) {
	case 1: return f1;
	case 2: return f2;
	case 3: return f3;
	case 4: return f4;
	default:
		cout << "Некоректний вибір! За замовчуванням sin(x).\n";
		return f1;
	}
}

// ===== Main menu =====
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int choice;
	double a, b, step;
	int n;

	do {
		cout << "\n";
		cout << "1. Табулювання значень функції\n";
		cout << "2. Обчислення інтегралу\n";
		cout << "0. Вихід\n";
		cout << "Ваш вибір: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			auto func = chooseFunction();
			cout << "Введіть межі відрізку [a, b]: ";
			cin >> a >> b;
			cout << "Введіть крок табулювання: ";
			cin >> step;

			if (step <= 0 || a >= b) {
				cout << "Помилка: невірні дані!\n";
				break;
			}
			tabulate(func, a, b, step);
			break;
		}
		case 2: {
			auto func = chooseFunction();
			cout << "Введіть межі інтегрування [a, b]: ";
			cin >> a >> b;
			cout << "Введіть кількість підінтервалів (парне число): ";
			cin >> n;

			if (n <= 0 || a >= b) {
				cout << "Помилка: невірні дані!\n";
				break;
			}

			double result = simpson(func, a, b, n);
			cout << fixed << setprecision(6);
			cout << "Інтеграл ≈ " << result << endl;
			break;
		}
		case 0:
			cout << "Вихід з програми.\n";
			break;
		default:
			cout << "Невірний вибір!\n";
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
