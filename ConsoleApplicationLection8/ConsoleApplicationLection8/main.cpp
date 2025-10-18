// ConsoleApplicationLection8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

// ===== Task 1 =====
void task1()
{
	// === Задача 1 ===
	cout << "Задача 1. Ініціалізація масиву рядків:\n";
	string users[5];

	// Ініціалізація кожного елемента за індексом
	users[0] = "Іван";
	users[1] = "Марія";
	users[2] = "Олег";
	users[3] = "Світлана";
	users[4] = "Юрій";

	cout << "Масив користувачів створено!\n\n";

	cout << "Елементи масиву: ";
	for (int i = 0; i < 3; i++) {
		cout << users[i] << " ";
	}
	cout << "\n\n";

	// === Задача 2 ===
	cout << "Задача 2. Виведення всіх елементів масиву чисел:\n";
	int numbers[3];

	numbers[0] = 1;
	numbers[1] = 15;
	numbers[2] = 2;

	cout << "Елементи масиву: ";
	for (int i = 0; i < 3; i++) {
		cout << numbers[i] << " ";
	}
	cout << "\n\n";

	// === Задача 3 ===
	cout << "Задача 3. Обчислення суми всіх елементів масиву:\n";
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += numbers[i];
	}
	cout << "Сума елементів = " << sum << "\n\n";

	// === Задача 4 ===
	cout << "Задача 4. Визначення кількості елементів масиву:\n";
	int length = sizeof(numbers) / sizeof(numbers[0]);
	cout << "Кількість елементів у масиві = " << length << "\n\n";
}

// ===== Task 2 =====
void task2()
{
	int array[] = { 0, 1, 3, 4, 5, 2, 1, -4, -1, 10, 55 };
	int length = sizeof(array) / sizeof(array[0]);

	// === Блок 1: Виводить усі елементи масиву
	cout << "\nБлок 1: Усі елементи масиву\n";
	for (int i = 0; i < length; i++)
		cout << array[i] << " ";
	cout << endl;

	// === Блок 2: Виводить усі елементи масиву в зворотному порядку
	cout << "\nБлок 2: Елементи у зворотному порядку\n";
	for (int i = length - 1; i >= 0; i--)
		cout << array[i] << " ";
	cout << endl;

	// === Блок 3: Виводить парні елементи масиву
	cout << "\nБлок 3: Парні елементи масиву\n";
	for (int i = 0; i < length; i++)
		if (array[i] % 2 == 0)
			cout << array[i] << " ";
	cout << endl;

	// === Блок 4: Виводить усі елементи масиву через один
	cout << "\nБлок 4: Елементи через один\n";
	for (int i = 0; i < length; i += 2)
		cout << array[i] << " ";
	cout << endl;

	// === Блок 5: Виводить елементи до -1
	cout << "\nБлок 5: Елементи до -1\n";
	for (int i = 0; i < length; i++) {
		if (array[i] == -1)
			break;
		cout << array[i] << " ";
	}
	cout << endl;
}

// ===== Task 3 =====
void task3()
{
	int arr[] = { 0, 1, 3, 4, 5, 2, 1, -4, -1, 10, 55 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// === Блок 1: Додавання елемента в кінець
	cout << "\nБлок 1: Додавання елемента в кінець\n";
	int valueToAdd = 10;
	int larger1[20]; // запас по розміру
	for (int i = 0; i < n; i++)
		larger1[i] = arr[i];
	larger1[n] = valueToAdd;
	n++;
	for (int i = 0; i < n; i++)
		cout << larger1[i] << " ";
	cout << endl;

	// === Блок 2: Додавання елемента на початок
	cout << "\nБлок 2: Додавання елемента на початок\n";
	valueToAdd = 99;
	int larger2[20];
	larger2[0] = valueToAdd;
	for (int i = 0; i < n; i++)
		larger2[i + 1] = larger1[i];
	n++;
	for (int i = 0; i < n; i++)
		cout << larger2[i] << " ";
	cout << endl;

	// === Блок 3: Додавання елемента в позицію (наприклад, 4)
	cout << "\nБлок 3: Додавання елемента в позицію 4\n";
	valueToAdd = 77;
	int position = 4;
	int larger3[20];
	for (int i = 0, j = 0; i < n + 1; i++) {
		if (i == position) {
			larger3[i] = valueToAdd;
		}
		else {
			larger3[i] = larger2[j];
			j++;
		}
	}
	n++;
	for (int i = 0; i < n; i++)
		cout << larger3[i] << " ";
	cout << endl;

	// === Блок 4: Видалення елемента з кінця
	cout << "\nБлок 4: Видалення елемента з кінця\n";
	n--;
	for (int i = 0; i < n; i++)
		cout << larger3[i] << " ";
	cout << endl;

	// === Блок 5: Видалення елемента з початку
	cout << "\nБлок 5: Видалення елемента з початку\n";
	for (int i = 0; i < n - 1; i++)
		larger3[i] = larger3[i + 1];
	n--;
	for (int i = 0; i < n; i++)
		cout << larger3[i] << " ";
	cout << endl;

	// === Блок 6: Видалення елемента з позиції (наприклад, 5)
	cout << "\nБлок 6: Видалення елемента з позиції 5\n";
	position = 5;
	for (int i = position; i < n - 1; i++)
		larger3[i] = larger3[i + 1];
	n--;
	for (int i = 0; i < n; i++)
		cout << larger3[i] << " ";
	cout << endl;

	// === Блок 7: Об’єднання двох масивів
	cout << "\nБлок 7: Об’єднання двох масивів\n";
	int array1[] = { 1, 2, 3 };
	int array2[] = { 4, 5, 6 };
	int merged[6];
	int k = 0;

	for (int i = 0; i < 3; i++)
		merged[k++] = array1[i];
	for (int i = 0; i < 3; i++)
		merged[k++] = array2[i];

	cout << "Результат об’єднання: ";
	for (int i = 0; i < 6; i++)
		cout << merged[i] << " ";
	cout << endl;
}

// ===== Main menu =====
int main()
{
	SetConsoleOutputCP(1251);
	int choice;
	do {
		std::cout << "\nВиберіть завдання (1 - Задачі 1-4, 2 - Перебір масиву, 3 - Додавання і видалення елементів масиву, 0 = вихід): ";
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
