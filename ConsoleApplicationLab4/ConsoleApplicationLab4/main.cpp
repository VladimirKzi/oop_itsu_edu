// ConsoleApplicationLab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <Windows.h>

using namespace std;

// ===== Task 1 =====
struct Student {
	string name;
	int inf, math, phys, prog;
};

void task1()
{
	Student group[10] = {
		{"Іванчук С.О.", 4,3,3,4},
		{"Панченко І.А.", 5,4,4,5},
		{"Заєць О.М.", 3,4,4,4},
		{"Вельбицький П.О.", 4,3,3,3},
		{"Сидоренко В.Р.", 2,3,3,2},
		{"Кравченко З.І.", 3,5,4,5},
		{"Якубів Р.Н.", 5,4,4,3},
		{"Зоренко П.М.", 4,2,3,3},
		{"Берестяк Г.С.", 4,5,5,5},
		{"Дячик Н.С.", 5,5,4,4}
	};

	cout << left << setw(3) << "№" << setw(20) << "Прізвище"
		<< setw(5) << "Інф" << setw(5) << "Матем"
		<< setw(5) << "Фіз" << setw(8) << "Прог"
		<< "Середній\n";
	cout << string(60, '-') << endl;

	int count = 0;
	for (int i = 0; i < 10; i++) {
		double avg = (group[i].inf + group[i].math + group[i].phys + group[i].prog) / 4.0;
		if (avg > 4.0) {
			count++;
			cout << setw(3) << (i + 1) << setw(20) << group[i].name
				<< setw(5) << group[i].inf
				<< setw(5) << group[i].math
				<< setw(5) << group[i].phys
				<< setw(8) << group[i].prog
				<< avg << endl;
		}
	}

	cout << "\nКількість студентів з середнім балом > 4: " << count << endl;
}

// ===== Task 2 =====
void task2()
{
	const int ARRAY_SIZE = 10;
	std::vector<std::string> A(ARRAY_SIZE);

	std::cout << "Будь ласка, введіть " << ARRAY_SIZE << " текстових елементів (рядків)." << std::endl;
	std::cout << "---------------------------------------" << std::endl;

	for (int i = 0; i < ARRAY_SIZE; ++i) {
		std::cout << "Введіть елемент A[" << i + 1 << "]: ";
		//std::getline(std::cin, A[i]).
		std::cin >> A[i];
	}

	int min_length = A[0].length();
	int min_index = 0;
	std::string shortest_element = A[0];

	for (int i = 0; i < 10; ++i) {
		int current_length = A[i].length();

		if (current_length < min_length) {
			min_length = current_length;
			min_index = i;
			shortest_element = A[i];
		}
	}

	std::cout << "Знайдено елемент найменшої довжини:" << std::endl;
	std::cout << "Елемент:          " << shortest_element << std::endl;
	std::cout << "Порядковий номер: " << min_index + 1 << " (індекс " << min_index << ")" << std::endl;
	std::cout << "Довжина:          " << min_length << " символів" << std::endl;
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
