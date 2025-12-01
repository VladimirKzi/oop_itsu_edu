// ConsoleApplicationTopic15.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Building {
protected:
	string address;
	int floors;

public:
	Building(string addr = "Невідомо", int f = 1)
		: address(addr), floors(f) {}

	virtual void show() {
		cout << "Будинок:\n";
		cout << "Адреса: " << address << endl;
		cout << "Кількість поверхів: " << floors << endl;
	}

	virtual ~Building() {}
};

class UniversityBuilding : public Building {
	int auditoriums;

public:
	UniversityBuilding(string addr = "Невідомо", int f = 1, int aud = 0)
		: Building(addr, f), auditoriums(aud) {}

	void show() override {
		cout << "Навчальний корпус:\n";
		cout << "Адреса: " << address << endl;
		cout << "Поверхів: " << floors << endl;
		cout << "Аудиторій: " << auditoriums << endl;
	}
};

class DigitalDevice {
protected:
	string brand;
	double weight;

public:
	DigitalDevice(string b = "Unknown", double w = 0)
		: brand(b), weight(w) {}

	virtual void show() {
		cout << "Цифровий пристрій:\n";
		cout << "Бренд: " << brand << endl;
		cout << "Вага: " << weight << " г\n";
	}

	virtual ~DigitalDevice() {}
};

class MobilePhone : public DigitalDevice {
	double screenSize;

public:
	MobilePhone(string b = "Unknown", double w = 0, double scr = 5.0)
		: DigitalDevice(b, w), screenSize(scr) {}

	void show() override {
		cout << "Мобільний телефон:\n";
		cout << "Бренд: " << brand << endl;
		cout << "Вага: " << weight << " г\n";
		cout << "Діагональ екрану: " << screenSize << "\"" << endl;
	}
};

template <typename T>
void findInRange(T arr[], int size, T minVal, T maxVal) {
	cout << "Значення у діапазоні [" << minVal << ", " << maxVal << "]: ";
	for (int i = 0; i < size; i++) {
		if (arr[i] >= minVal && arr[i] <= maxVal)
			cout << arr[i] << " ";
	}
	cout << endl;
}

template <typename T1, typename T2>
class Pair {
	T1 first;
	T2 second;

public:
	Pair(T1 a, T2 b) : first(a), second(b) {}

	void show() {
		cout << "Пара: (" << first << ", " << second << ")" << endl;
	}
};


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	cout << "Завдання 1:\n";

	Building* buildings[2];
	buildings[0] = new Building("Проспект Миру, 5", 9);
	buildings[1] = new UniversityBuilding("Університетська, 12", 4, 30);
	buildings[1] = new UniversityBuilding("Херсонський провулок, 3", 4, 35);

	for (int i = 0; i < 2; i++) {
		buildings[i]->show();
		cout << endl;
	}

	cout << "Завдання 2:\n";

	DigitalDevice* devices[2];
	devices[0] = new DigitalDevice("Samsung", 500);
	devices[1] = new MobilePhone("Xiaomi", 178, 6.4);
	devices[1] = new MobilePhone("Oppo", 185, 7.3);

	for (int i = 0; i < 2; i++) {
		devices[i]->show();
		cout << endl;
	}

	cout << "Завдання 3:\n";

	int arrInt[6] = { 1, 5, 12, -4, 7, 9 };
	double arrDouble[5] = { 1.2, 3.8, 10.5, -1.3, 4.4 };

	findInRange(arrInt, 6, 0, 10);
	findInRange(arrDouble, 5, -2.0, 5.0);

	cout << "\nЗавдання 4:\n";

	Pair<int, double> p1(5, 3.14);
	Pair<string, int> p2("Age", 21);

	p1.show();
	p2.show();

	delete buildings[0];
	delete buildings[1];
	delete devices[0];
	delete devices[1];

	return 0;
}

