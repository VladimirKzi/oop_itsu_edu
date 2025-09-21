// ConsoleApplicationLab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

// ===== Task 1 =====
void task1()
{
	double x, y;
	cout << "Введіть x: ";
	cin >> x;

	if (x > 1 && x < 3.2) {
		double numerator = -(1.4 + x);
		double denominator = log(x);
		y = numerator / denominator;
		cout << "Проміжок (1, 3.2): чисельник = " << numerator << ", знаменник = " << denominator << endl;
	}
	else if (x > 0 && x <= 1) {
		cout << "Проміжок (0, 1]: pow(" << x << ", 2) - 0.75" << endl;
		y = pow(x, 2) - 0.75;
	}
	else if (x <= 0) {
		cout << "Проміжок (-inf, 0]: pow(cos(" << x << ", 3) - pow(sin(" << x << "), 3)" << endl;
		y = pow(cos(x), 3) - pow(sin(x), 3);
	}
	else {
		cout << "Введене значення x не належить жодному з визначених проміжків." << endl;
		return;
	}

	cout << "Кінцеве значення y = " << y << endl;
}

// ===== Task 2 =====
void task2()
{
	double t_start, t_end, t_step;
	int point_num = 1;

	cout << "Введіть початкове значення аргументу (t_start - 2.3): ";
	cin >> t_start;

	cout << "Введіть кінцеве значення аргументу (t_end - 7.2): ";
	cin >> t_end;

	cout << "Введіть крок зміни аргументу (t_step - 0.8): ";
	cin >> t_step;

	cout << "---------------------------------------" << endl;
	cout << "| № точки | Значення аргументу (t) | Значення функції (y) |" << endl;
	cout << "---------------------------------------" << endl;

	double t = t_start;
	while (t <= t_end) {
		double numerator = pow(cos(t), 3);
		double denominator = 1.5 * t + 2;

		if (abs(denominator) < 1e-9) {
			cout << "| " << setw(7) << point_num << " | " << setw(21) << t << " | " << setw(20) << "Ділення на нуль!" << " |" << endl;
		}
		else {
			double y = numerator / denominator;
			cout << "| " << setw(7) << point_num << " | " << setw(21) << t << " | " << setw(20) << y << " |" << endl;
		}

		t += t_step;
		point_num++;
	}

	cout << "---------------------------------------" << endl;
}

// ===== Task 2 Ver.2 =====
void task22()
{
	double t_start, t_end, t_step;
	int point_num = 1;

	cout << "Введіть початкове значення аргументу (t_start - 2.3): ";
	cin >> t_start;

	cout << "Введіть кінцеве значення аргументу (t_end - 7.2): ";
	cin >> t_end;

	cout << "Введіть крок зміни аргументу (t_step - 0.8): ";
	cin >> t_step;

	cout << "---------------------------------------" << endl;
	cout << "| № точки | Значення аргументу (t) | Значення функції (y) |" << endl;
	cout << "---------------------------------------" << endl;

	double t = t_start;
	double numerator = pow(cos(t), 3);
	double denominator = 1.5 * t + 2;

	loop_start:
	if (t > t_end) {
		goto loop_end;
	}

	if (abs(denominator) < 1e-9) {
		cout << "| " << setw(7) << point_num << " | " << setw(21) << t << " | " << setw(20) << "Ділення на нуль!" << " |" << endl;
	}
	else {
		double y = numerator / denominator;
		cout << "| " << setw(7) << point_num << " | " << setw(21) << t << " | " << setw(20) << y << " |" << endl;
	}

	t += t_step;
	point_num++;

	goto loop_start;

	loop_end:
	cout << "---------------------------------------" << endl;
}

// ===== Task 3 =====
void task3()
{
	double z_start, z_end, t_step;
	int point_num = 1;

	cout << "Введіть початкове значення аргументу (z_start - -2/0.5): ";
	cin >> z_start;

	cout << "Введіть кінцеве значення аргументу (z_end - 0.5/3): ";
	cin >> z_end;

	cout << "Введіть крок зміни аргументу (t_step - 0.5): ";
	cin >> t_step;

	cout << "---------------------------------------" << endl;
	cout << "| № точки | Значення аргументу (z) | Значення функції (w) |" << endl;
	cout << "---------------------------------------" << endl;

	for (double z = z_start; z <= z_end; z += t_step) {
		double w;

		if (z >= -2 && z <= 0.5) {
			w = z - sin(z);
		}
		else if (z > 0.5 && z <= 3) {
			w = M_PI / 2.0 - atan(z - 0.3);
		}
		else {
			cout << "| " << setw(7) << point_num << " | " << setw(21) << z << " | " << setw(20) << "Не визначено" << " |" << endl;
			point_num++;
			continue;
		}

		cout << "| " << setw(7) << point_num << " | " << setw(21) << fixed << setprecision(4) << z << " | " << setw(20) << fixed << setprecision(6) << w << " |" << endl;
		point_num++;
	}

	cout << "---------------------------------------" << endl;
}

// ===== Main menu =====
int main()
{
	SetConsoleOutputCP(1251);
	int choice;
	do {
		std::cout << "\nChoice the task (1, 2, 22, 3, 0 = exit): ";
		std::cin >> choice;
		switch (choice) {
		case 1: task1(); break;
		case 2: task2(); break;
		case 22: task22(); break;
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
