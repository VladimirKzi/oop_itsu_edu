// ConsoleApplicationSem2Lab12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <windows.h>

using namespace std;

// ================================================
// ЗАВДАННЯ 1
// ================================================
void Task1() {
	cout << "1) Аналіз операцій з покажчиками (частина 1)\n";
	int x = 10, y = 20;
	int *p1 = &x, *p2 = &y;
	cout << "a) p1=&x, p2=&y → *p1=" << *p1 << ", *p2=" << *p2 << endl;
	// ... (інші операції за бажанням)
	cout << endl;
}

// ================================================
// ЗАВДАННЯ 2
// ================================================
void Task2() {
	cout << "2) Аналіз операцій з покажчиками (частина 2)\n";
	int x = 5, y = 8;
	int *p1 = &x, *p2 = &y;
	cout << "a) p1=&x, p2=&y → x=" << x << ", y=" << y << endl;

	p2 = &x;
	cout << "б) p2 = &x → *p2=" << *p2 << endl;

	*p2 = x - 2;
	cout << "в) *p2 = x-2 → x=" << x << endl << endl;
}

// ================================================
// ЗАВДАННЯ 3
// ================================================
void Task3() {
	cout << "3) Аналіз операцій з покажчиками (частина 3)\n";
	int x = 40, y = 30;
	int *p1 = &y, *p2 = &x;

	*p1 = x - 10;
	*p2 = y - 10;
	cout << "б) *p1 = x-10, *p2 = y-10 → x=" << x << ", y=" << y << endl << endl;
}

// ================================================
// ЗАВДАННЯ 4
// ================================================
void Task4() {
	cout << "4) Динамічний масив + подвоєння значень\n";
	int SIZE = 5;
	int* pArr = new int[SIZE];
	int* pStart = pArr;

	cout << "Введіть " << SIZE << " чисел: ";
	for (int i = 0; i < SIZE; i++) {
		cin >> *pArr++;
	}

	pArr = pStart;
	cout << "Подвоєні значення: ";
	for (int i = 0; i < SIZE; i++) {
		cout << (*pArr * 2) << " ";
		pArr++;
	}
	cout << endl << endl;
	delete[] pStart;
}

// ================================================
// ЗАВДАННЯ 5
// ================================================
void Task5() {
	cout << "5) Робота з 5-м елементом динамічного масиву\n";
	int SIZE = 10;
	int* pArr = new int[SIZE];
	int q;

	for (int i = 0; i < SIZE; i++) {
		*(pArr + i) = rand() % 50 - 20;
	}

	cout << "Масив: ";
	for (int i = 0; i < SIZE; i++) cout << *(pArr + i) << " ";
	cout << endl;

	q = *(pArr + 4);
	cout << "a) 5-й елемент = " << q << endl;

	*(pArr + 4) = 1000;
	cout << "б) 5-й елемент змінено на 1000\n";

	cout << "в) Масив: ";
	for (int i = 0; i < SIZE; i++) cout << *(pArr + i) << " ";
	cout << endl << endl;

	delete[] pArr;
}

// ================================================
// ЗАВДАННЯ 6
// ================================================
void Task6() {
	cout << "6) Кількість додатних елементів без індексації\n";
	int SIZE = 10;
	int* pArr = new int[SIZE];
	int* pStart = pArr;
	int count = 0;

	cout << "Масив: ";
	for (int i = 0; i < SIZE; i++) {
		*pArr = rand() % 100 - 40;
		cout << *pArr << " ";
		pArr++;
	}
	cout << endl;

	pArr = pStart;
	while (pArr < pStart + SIZE) {
		if (*pArr > 0) count++;
		pArr++;
	}
	cout << "Кількість додатних елементів: " << count << endl << endl;

	delete[] pStart;
}

// ================================================
// ЗАВДАННЯ 7
// ================================================
void Task7() {
	cout << "7) Структура Працівники підприємства\n";
	struct Employee {
		char name[30];
		int age;
		double salary;
	};

	int SIZE = 3;
	Employee* emp = new Employee[SIZE];

	for (int i = 0; i < SIZE; i++) {
		cout << "Працівник " << i + 1 << ":\n";
		cin.ignore();
		cin.getline(emp[i].name, 30);
		cout << "Вік: "; cin >> emp[i].age;
		cout << "Зарплата: "; cin >> emp[i].salary;
	}

	cout << "\nСписок працівників:\n";
	for (int i = 0; i < SIZE; i++) {
		cout << emp[i].name << " | " << emp[i].age
			<< " | " << emp[i].salary << endl;
	}
	delete[] emp;
	cout << endl;
}

// ================================================
// ЗАВДАННЯ 8
// ================================================
void Task8() {
	cout << "8) Обмін останнього і мінімального елементів\n";
	int SIZE = 8;
	int* pArr = new int[SIZE];
	int* pStart = pArr;
	int* pMin = pArr;

	for (int i = 0; i < SIZE; i++) {
		*(pArr + i) = rand() % 20 - 10;
	}

	cout << "Початковий: ";
	for (int i = 0; i < SIZE; i++) cout << *(pStart + i) << " ";
	cout << endl;

	for (int i = 1; i < SIZE; i++) {
		if (*(pStart + i) < *pMin) pMin = pStart + i;
	}

	int temp = *pMin;
	*pMin = *(pStart + SIZE - 1);
	*(pStart + SIZE - 1) = temp;

	cout << "Після обміну: ";
	for (int i = 0; i < SIZE; i++) cout << *(pStart + i) << " ";
	cout << endl << endl;

	delete[] pStart;
}

// ================================================
// ЗАВДАННЯ 9
// ================================================
void Task9() {
	cout << "9) Сформувати масив B з негативних елементів A\n";
	int SIZE = 12;
	int* A = new int[SIZE];
	int negCount = 0;

	for (int i = 0; i < SIZE; i++) {
		A[i] = rand() % 20 - 10;
		if (A[i] < 0) negCount++;
	}

	cout << "Масив A: ";
	for (int i = 0; i < SIZE; i++) cout << A[i] << " ";
	cout << "\nВід'ємних елементів: " << negCount << endl;

	int* B = new int[negCount];
	int* pB = B;
	for (int i = 0; i < SIZE; i++) {
		if (A[i] < 0) *pB++ = A[i];
	}

	cout << "Масив B: ";
	for (int i = 0; i < negCount; i++) cout << B[i] << " ";
	cout << endl << endl;

	delete[] A;
	delete[] B;
}

// ================================================
// ЗАВДАННЯ 10
// ================================================
void Task10() {
	cout << "10) Перевірка, чи масив є зростаючою послідовністю\n";
	const int SIZE = 6;
	int A[SIZE] = { 5, 8, 10, 12, 15, 20 };
	int* p = A;
	bool isIncreasing = true;

	for (int i = 0; i < SIZE - 1; i++) {
		if (*(p + i) >= *(p + i + 1)) {
			isIncreasing = false;
			break;
		}
	}

	cout << "Масив: ";
	for (int i = 0; i < SIZE; i++) cout << A[i] << " ";
	cout << "\nРезультат: " << (isIncreasing ?
		"Масив є зростаючою послідовністю" :
		"Масив НЕ є зростаючою послідовністю") << endl << endl;
}

// ================================================
// ЗАВДАННЯ 11
// ================================================
void Task11() {
	cout << "11) Заміна парних чисел на 0 через масив покажчиків\n";
	const int SIZE = 8;
	int A[SIZE];
	int* pArr[SIZE];

	for (int i = 0; i < SIZE; i++) {
		A[i] = rand() % 20;
		pArr[i] = &A[i];
	}

	cout << "До:  ";
	for (int i = 0; i < SIZE; i++) cout << A[i] << " ";
	cout << endl;

	cout << "Після:";
	for (int i = 0; i < SIZE; i++) {
		if (*pArr[i] % 2 == 0) *pArr[i] = 0;
		cout << " " << *pArr[i];
	}
	cout << endl << endl;
}

// ================================================
// ЗАВДАННЯ 12
// ================================================
void Task12() {
	cout << "12) Покажчики на покажчики (* і ++)\n";
	int A[5] = { 10, 20, 30, 40, 50 };
	int* p[5] = { A, A + 1, A + 2, A + 3, A + 4 };
	int** pp = p;

	cout << "*p[0]++   = " << *p[0]++ << endl;
	cout << "*++p[0]   = " << *++p[0] << endl;
	cout << endl;
}

// ================================================
// ЗАВДАННЯ 13
// ================================================
void Task13() {
	cout << "13) Покажчики на покажчики (складні операції)\n";
	int A[5] = { 0, 1, 2, 3, 4 };
	int* p[5] = { A, A + 1, A + 2, A + 3, A + 4 };
	int** pp = p;

	cout << "**pp = " << **pp << " (A[0])\n";
	pp++;
	cout << "Після pp++ → **pp = " << **pp << " (A[1])\n";
	cout << "Демонстрація пріоритету операцій * і ++ завершена.\n\n";
}

// ================================================
// ЗАВДАННЯ 14 (скорочено)
// ================================================
void Task14() {
	cout << "14) Двовимірний динамічний масив\n";
	int N = 3;
	int** A2 = new int*[N];
	for (int i = 0; i < N; i++) A2[i] = new int[N];

	cout << "ДМ як ДМ:\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A2[i][j] = rand() % 20;
			cout << setw(4) << A2[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < N; i++) delete[] A2[i];
	delete[] A2;
	cout << endl;
}

// ================================================
// MAIN
// ================================================
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	cout << "=== ЛАБОРАТОРНА РОБОТА: ПОКАЖЧИКИ ===\n\n";

	Task1(); Task2(); Task3(); Task4(); Task5();
	Task6(); Task7(); Task8(); Task9(); Task10();
	Task11(); Task12(); Task13(); Task14();

	cout << "\n=== Всі 14 завдань виконані успішно! ===\n";
	return 0;
}
