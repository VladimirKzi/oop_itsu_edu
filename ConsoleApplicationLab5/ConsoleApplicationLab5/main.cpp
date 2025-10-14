// ConsoleApplicationLab5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <Windows.h>

using namespace std;

// ===== Task 1 =====
struct Fridge {
	string name;
	double price;
	double volume;
	string manufacturer;
};

static void task1()
{
	try {
		const int N = 5;
		Fridge fridges[N];

		cout << "Введіть інформацію про холодильники:\n";
		for (int i = 0; i < N; i++) {
			cout << "\nХолодильник #" << i + 1 << endl;

			cout << "Назва: ";
			cin >> fridges[i].name;
			if (fridges[i].name.empty())
				throw runtime_error("Назва холодильника не може бути порожньою!");

			cout << "Вартість (грн): ";
			if (!(cin >> fridges[i].price))
				throw runtime_error("Помилка: введіть числове значення для вартості!");
			if (fridges[i].price <= 0)
				throw runtime_error("Помилка: вартість має бути більшою за нуль!");

			cout << "Об'єм холодильної камери (л): ";
			if (!(cin >> fridges[i].volume))
				throw runtime_error("Помилка: введіть числове значення для об'єму!");
			if (fridges[i].volume <= 0)
				throw runtime_error("Помилка: об'єм має бути більшим за нуль!");

			cout << "Завод-виробник: ";
			cin >> fridges[i].manufacturer;
			if (fridges[i].manufacturer.empty())
				throw runtime_error("Назва виробника не може бути порожньою!");
		}

		ofstream fout("fridges.txt");
		if (!fout.is_open())
			throw runtime_error("Не вдалося відкрити файл для запису!");

		for (int i = 0; i < N; i++) {
			fout << fridges[i].name << " "
				<< fridges[i].price << " "
				<< fridges[i].volume << " "
				<< fridges[i].manufacturer << endl;
		}
		fout.close();

		ifstream fin("fridges.txt");
		if (!fin.is_open())
			throw runtime_error("Не вдалося відкрити файл для читання!");

		cout << "\nХолодильники з вартістю понад 55000 грн:\n";
		Fridge f;
		bool found = false;
		while (fin >> f.name >> f.price >> f.volume >> f.manufacturer) {
			if (f.price > 55000) {
				cout << left << setw(12) << f.name
					<< setw(12) << f.price
					<< setw(10) << f.volume
					<< f.manufacturer << endl;
				found = true;
			}
		}
		fin.close();

		if (!found)
			cout << "Немає холодильників із вартістю понад 55000 грн.\n";
	}
	catch (const exception &e) {
		cerr << "\n Помилка: " << e.what() << endl;
	}
}

// ===== Task 2 =====
struct Train {
	int number;
	string name;
	double time;
};


static void task2()
{
	try {
		const int N = 5;
		Train trains[N];

		cout << "Введіть інформацію про потяги:\n";
		for (int i = 0; i < N; i++) {
			cout << "\nПотяг #" << i + 1 << endl;

			cout << "Номер потяга: ";
			if (!(cin >> trains[i].number))
				throw runtime_error("Помилка: номер повинен бути числом!");
			if (trains[i].number <= 0)
				throw runtime_error("Помилка: номер потяга має бути додатнім!");

			cout << "Назва потяга: ";
			cin.ignore();
			getline(cin, trains[i].name);
			if (trains[i].name.empty())
				throw runtime_error("Назва потяга не може бути порожньою!");

			cout << "Час у дорозі (год): ";
			if (!(cin >> trains[i].time))
				throw runtime_error("Помилка: введіть числове значення часу!");
			if (trains[i].time < 0)
				throw runtime_error("Помилка: час у дорозі не може бути від’ємним!");
		}

		ofstream fout("trains.txt");
		if (!fout.is_open())
			throw runtime_error("Не вдалося відкрити файл для запису!");
		for (int i = 0; i < N; i++) {
			fout << trains[i].number << " "
				<< trains[i].name << " "
				<< trains[i].time << endl;
		}
		fout.close();

		ifstream fin("trains.txt");
		if (!fin.is_open())
			throw runtime_error("Не вдалося відкрити файл для читання!");

		cout << "\nПотяги до Києва з часом у дорозі < 6 год:\n";
		Train t;
		bool found = false;
		while (fin >> t.number >> ws) {
			getline(fin, t.name, ' ');
			fin >> t.time;
			if (fin.fail())
				throw runtime_error("Помилка читання з файлу!");

			if (t.time <= 6) {
				cout << left << setw(8) << t.number
					<< setw(30) << t.name
					<< t.time << " год" << endl;
				found = true;
			}
		}
		fin.close();

		if (!found)
			cout << "Немає потягів з часом у дорозі < 6 год.\n";
	}
	catch (const exception &e) {
		cerr << "\n Помилка: " << e.what() << endl;
	}
}

// ===== Main menu =====
int main()
{
	SetConsoleCP(1251);
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
