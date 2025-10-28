// ConsoleApplicationTopic11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

// ===== Variant 1 =====
int square(int x) {
	cout<<"Виклик square(int)"<<endl;
	return x * x;
}

double square(double x) {
	cout<<"Виклик square(double)"<<endl;
	return x * x;
}

void variant1()
{
	int a = 5;
	double b = 3.2;

	cout<<"Квадрат цілого числа "<<a<<" = "<<square(a)<<endl;
	cout<<"Квадрат дійсного числа "<<b<<" = "<<square(b)<<endl;
}

// ===== Variant 2 =====
double area(double a, double b) {
	cout<<"Виклик area(double, double)"<<endl;
	return a * b;
}

double area(double a) {
	cout<<"Виклик area(double)"<<endl;
	return a * a;
}

void variant2()
{
	double x = 4.0, y = 5.0;

	cout<<"Площа квадрата зі стороною "<<x<< " = " << area(x)<<endl;
	cout<<"Площа прямокутника зі сторонами "<<x<< " і "<<y<< " = "<<area(x, y)<<endl;
}

// ===== Main menu =====
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	do {
		std::cout << "\nВиберіть варіант (1, 2, 0 = вихід): ";
		std::cin >> choice;
		switch (choice) {
		case 1: variant1(); break;
		case 2: variant2(); break;
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
