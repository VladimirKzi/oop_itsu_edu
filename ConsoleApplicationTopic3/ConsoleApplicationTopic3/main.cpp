// ConsoleApplicationTopic3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ===== Task 3 =====
void task3() {
	const int n = 5;
	int a[n] = { 1, 2, 7, 4, 5 };
	int x = 7;
	int i = 1;

	while (i < n && a[i] != x) {
		++i;
	}

	if (i < n) std::cout << "Found x = " << x << " at index " << i << std::endl;
	else std::cout << "Not found" << std::endl;
}

// ===== Task 4 =====
void P()
{
	std::cout << "Tis is P?!" << std::endl;
}

void Q()
{
	std::cout << "Tis is Q?!" << std::endl;
}

void task4() {
	bool F = true;
	bool G = false;//true;
	while (F)
	{
		P();
		if (!G) Q();
	}
}

// ===== Task 46 =====
class Pair {
public:
	string key;
	string value;

	Pair(string k, string v) : key(k), value(v) {}
};

class Dictionary {
	vector<Pair> data;
public:
	void add(const string& k, const string& v) {
		data.emplace_back(k, v);
	}
	string find(const string& k) {
		for (auto &p : data) {
			if (p.key == k) return p.value;
		}
		return "Not found";
	}
};

void task46() {
	Dictionary dict;
	dict.add("apple", "Apples");
	dict.add("dog", "Dogs");
	dict.add("car", "Cars");

	std::cout << "EEnter the key for Search (apple, dog, car): ";
	string key;
	std::cin >> key;

	std::cout << "Value: " << dict.find(key) << std::endl;
}

// ===== Task 47 =====
class Searcher 
{
public:
	static vector<int> findAll(const vector<int>& a, const vector<int>& b)
	{
		vector<int> result;
		for (int x : b) 
		{
			for (int y : a)
			{
				if (x == y) 
				{
					result.push_back(x);
					break;
				}
			}
		}
		return result;
	}
};

void task47()
{
	vector<int> a = { 1, 2, 3, 4, 5, 6 };
	vector<int> b = { 2, 5, 7 };

	vector<int> found = Searcher::findAll(a, b);

	std::cout << "Common elements: ";
	for (int x : found) std::cout << x << " ";
	std::cout << std::endl;
}

// ===== Main menu =====
int main()
{
    //std::cout << "Hello World!\n"; 
	int choice;
	do {
		std::cout<< "\nChoice the task (3, 4, 46, 47, 0 = exit): ";
		std::cin>>choice;
		switch (choice) {
		case 3: task3(); break;
		case 4: task4(); break;
		case 46: task46(); break;
		case 47: task47(); break;
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
