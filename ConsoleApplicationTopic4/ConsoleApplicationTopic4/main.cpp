// ConsoleApplicationTopic4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <Windows.h>

using namespace std;

int main()
{
	//створення масиву
	const int SIZE = 15;
	vector<int> arr(SIZE);

	mt19937 gen(static_cast<unsigned>(time(nullptr)));
	uniform_int_distribution<int> dist(-4, 55);

	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = dist(gen);
	}
	//створення масиву

	SetConsoleOutputCP(1251);

	std::cout << "Блок 1: усі елементи " << endl;
	for (int value : arr) cout << value << " ";
	cout << "\n\n";

	cout << "Блок 2: у зворотному порядку" << endl;
	for (auto it = arr.rbegin(); it != arr.rend(); ++it) cout << *it << " ";
	cout << "\n\n";

	cout << "Блок 3: парні елементи" << endl;
	for (int value : arr) { if (value % 2 == 0) cout << value << " "; }
	cout << "\n\n";

	cout << "Блок 4: через один" << endl;
	for (size_t i = 0; i < arr.size(); i += 2) cout << arr[i] << " ";
	cout << "\n\n";

	cout << "Блок 5: до першого -1" << endl;
	for (int value : arr) {
		if (value == -1) break;
		cout << value << " ";
	}
	cout << "\n\n";

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
