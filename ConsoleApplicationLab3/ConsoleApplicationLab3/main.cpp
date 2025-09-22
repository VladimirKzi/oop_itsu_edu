// ConsoleApplicationLab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

// ===== Task 1 =====
void task1()
{
	double B[] = { 2.2, 3.1, -3.6, 0.1, 2.1 };
	int n = sizeof(B) / sizeof(B[0]);
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (B[i] < 0.99)
			count++;
	}

	cout << "Кількість елементів менших за 0.99 = " << count << endl;
}

// ===== Task 2 =====
void task2()
{
	const int ROWS = 5;
	const int COLS = 7;

	/*int arr_example[ROWS][COLS] = {
		{10, 11, 12, 13, 14, 15, 16},
		{17, 18, 19, 20, 21, 22, 23},
		{24, 25, 26, 27, 28, 29, 30},
		{85, 86, 87, 88, 89, 90, 91},
		{40, 41, 42, 43, 44, 45, 46}
	};*/

	int arr[ROWS][COLS];

	cout << "Введіть матрицю 3x7:\n";
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			cin >> arr[i][j];

	cout << "\n\nПочаткова матриця\n";
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
	
	const int new_COLS = COLS - 1;
	int new_arr[ROWS][new_COLS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (j < 4) {
				new_arr[i][j] = arr[i][j];
			}
			else if (j > 4) {
				new_arr[i][j - 1] = arr[i][j];
			}
		}
	}

	cout << "\nМатриця після видалення 5-го стовпчика:\n";
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < new_COLS; j++) {
			cout << new_arr[i][j] << "\t";
		}
		cout << "\n";
	}
}

// ===== Main menu =====
int main()
{
	SetConsoleOutputCP(1251);
	int choice;
	do {
		std::cout << "\nChoice the task (1, 2, 0 = exit): ";
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
