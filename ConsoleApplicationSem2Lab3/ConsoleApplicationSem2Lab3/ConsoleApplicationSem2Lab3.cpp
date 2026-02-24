// ConsoleApplicationSem2Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

class Worker
{
public:
	virtual double salary() = 0;
	virtual ~Worker() {}
};

class HourlyWorker : public Worker
{
	double hours, rate;
public:
	HourlyWorker(double h, double r) : hours(h), rate(r) {}
	double salary() override {
		return hours * rate;
	}
};

class FixedWorker : public Worker
{
	double monthly;
public:
	FixedWorker(double m) : monthly(m) {}
	double salary() override {
		return monthly;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Worker* staff[5];

	staff[0] = new HourlyWorker(160, 10);
	staff[1] = new HourlyWorker(160, 8);
	staff[2] = new FixedWorker(1500);
	staff[3] = new FixedWorker(1700);
	staff[4] = new FixedWorker(1900);

	for (int i = 0; i <= 4; i++)
	{
		cout << "#: " << i <<  ", Зарплата: " << staff[i]->salary() << endl;
	}

	for (int i = 0; i <= 4; i++)
	{
		delete staff[i];
	}

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
