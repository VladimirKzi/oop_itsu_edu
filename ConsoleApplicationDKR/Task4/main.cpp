// ConsoleApplicationDKR.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

class Base {
protected:
	long fact(int n) {
		if (n <= 1) return 1;
		return n * fact(n - 1);
	}
public:
	virtual void compute() = 0;
	virtual ~Base() = default;
};

class Derived : public Base {
	int arr[5] = { 5, 3, 7, 2, 4 };
public:
	void compute() override {
		for (int i : arr) {
			std::cout << i << "! = " << fact(i) << std::endl;
		}
	}
};

int main() {
	Base* b = new Derived();
	b->compute();
	delete b;
	return 0;
}

