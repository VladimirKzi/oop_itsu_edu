// ConsoleApplicationTopic5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>

using namespace std;

// ===== Block A =====
void blockA()
{
	const int SIZE = 12;
	vector<int> arr(SIZE);

	mt19937 gen(static_cast<unsigned>(time(nullptr)));
	uniform_int_distribution<int> dist(-15, 15);

	//arr = { -5, 3, 12, 15, -7, 15, 0, 4, -3, 8, 15, -2 };

	cout<<"\n\nArray: " << endl;
	for (int i = 0; i < SIZE; ++i) {
		arr[i] = dist(gen);
		cout << arr[i] << " ";
	}
	cout << "\n\n";

	int maxVal = arr[0];
	int lastIndex = 0;

	for (int i = 0; i < SIZE; ++i)
	{
		if (arr[i] > maxVal)
		{
			maxVal = arr[i];
			lastIndex = i;
		}
		else if (arr[i] == maxVal)
		{
			lastIndex = i;
		}
	}

	cout << "Max. value: " << maxVal << endl;
	cout << "Last index: " << lastIndex << endl;
}

// ===== Block B =====
void blockB()
{
	const int ROWS = 8;
	const int COLS = 5;

	/*int arr[ROWS][COLS] = {
		{10, 11, 12, 13, 14},
		{15, 16, 17, 18, 19},
		{20, 21, 22, 23, 24},
		{85, 86, 87, 88, 89},
		{25, 26, 27, 28, 29},
		{30, 31, 32, 33, 34},
		{35, 36, 37, 38, 39},
		{91, 93, 95, 97, 99}
	};*/
	int arr[ROWS][COLS];
	mt19937 gen(static_cast<unsigned>(time(nullptr)));
	uniform_int_distribution<int> dist(10, 99);

	cout << "\nMulti Array:\n";
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			arr[i][j] = dist(gen);
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
}

// ===== Main menu =====
int main()
{
	char choice;

	do {
		std::cout << "\nChoice the block (a, b, 0 = exit): ";
		std::cin>>choice;
		switch (choice)
		{
			case 'a':
				blockA();
				break;
			case 'b':
				blockB();
				break;
		}
	} while (choice != '0');

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
