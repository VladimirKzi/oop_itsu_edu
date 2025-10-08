// ConsoleApplicationTopic7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

// ===== Task 1 =====
void task1()
{
	// float b;
	// double d = 14.2;
	// char c = 's'; 
	// bool k = true;

	int a, b;
	int c_sum; 

	cout << "Введіть перше число: ";
	cin >> a; 

	cout << "Введіть друге число: ";
	cin >> b;

	c_sum = a + b;

	cout << "Сума чисел = " << c_sum << endl;
}

// ===== Task 2 =====
void task2()
{
	double num;
	cout << "Введіть довільне число: ";
	cin >> num;


	if (num < 10) { 
		cout << "Це число менше 10." << endl;
	}
	else {
		cout << "Це число більше або дорівнює 10." << endl;
	}

	cout << "\nВведіть довільне число для розширеної перевірки: ";
	cin >> num;

	if (num < 10) { 
		cout << "Це число менше 10." << endl;
	}
	else if (num == 10) { 
		cout << "Це число дорівнює 10." << endl;
	}
	else { 
		cout << "Це число більше 10." << endl;
	}
}

// ===== Task 3 =====
void task3()
{
	int i;
	int sum = 0;

	for (i = 1; i <= 1000; i++) { 
		sum = sum + i;
	}

	cout << "Сума чисел від 1 до 1000 = " << sum << endl;
}

// ===== Task 4 =====
void task4()
{
	int i = 0;   
	int sum = 0; 

	while (i < 1000) {
		i++;
		sum += i; 
	}

	cout << "Сума чисел від 1 до 1000 = " << sum << endl;
}

// ===== Task 5 =====
void task5()
{
	int i = 0; 
	int sum = 0;

	do {
		i++; 
		sum += i;
	} while (i < 1000);

	cout << "Сума чисел від 1 до 1000 = " << sum << endl;
}

// ===== Task 6 =====
void task6()
{
	string students[10] = {
		"Іванов", "Петров", "Сидоров",
		"Ахмедов", "Ерошкин", "Выхин",
		"Андєєв", "Вин Дизель", "Картошкин", "Чубайс"
	};

	for (int i = 0; i < 10; i++) {
		cout << students[i] << endl;
	}
}

// ===== Task 7 =====
void task7()
{
	int arr[10];

	for (int i = 0; i < 10; i++) {
		cout << "[" << i + 1 << "]" << ": ";
		cin >> arr[i];
	}

	cout << "\nМасив: ";

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

// ===== Task 8 =====
void function_name() {
	cout << "Hello, world" << endl;
}

void check_pass(string password) {
	string valid_pass = "qwerty123";

	if (password == valid_pass) {
		cout << "Доступ дозволено!" << endl;
	}
	else {
		cout << "Невірний пароль!" << endl;
	}
}

int task8()
{
	//function_name();

	string user_pass;
	cout << "Введіть пароль: ";

	cin.ignore(256, '\n');

	getline(cin, user_pass);
	check_pass(user_pass);
	return 0;
}

// ===== Main menu =====
int main()
{
	SetConsoleOutputCP(1251);
	int choice;
	do {
		std::cout << "\nChoice the task (1, 2, 3, 4, 5, 6, 7, 8, 0 = exit): ";
		std::cin >> choice;
		switch (choice) {
		case 1: task1(); break;
		case 2: task2(); break;
		case 3: task3(); break;
		case 4: task4(); break;
		case 5: task5(); break;
		case 6: task6(); break;
		case 7: task7(); break;
		case 8: task8(); break;
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
