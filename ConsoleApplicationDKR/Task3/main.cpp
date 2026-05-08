// ConsoleApplicationDKR.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

class Equation {
public:
	virtual void roots() = 0;
	virtual ~Equation() = default;
};

class Linear : public Equation {
	double a, b;
public:
	Linear(double a1, double b1) : a(a1), b(b1) {}
	void roots() override {
		if (a != 0) std::cout << "x = " << -b / a << std::endl;
		else std::cout << "No solution" << std::endl;
	}
};

class Quadratic : public Equation {
	double a, b, c;
public:
	Quadratic(double a1, double b1, double c1) : a(a1), b(b1), c(c1) {}
	void roots() override {
		double d = b * b - 4 * a*c;
		if (d > 0) std::cout << "Two roots" << std::endl;
		else if (d == 0) std::cout << "One root" << std::endl;
		else std::cout << "No real roots" << std::endl;
	}
};

int main() {
	Equation* eqs[] = { new Linear(2, -4), new Quadratic(1, 3, 2) };
	for (auto eq : eqs) {
		eq->roots();  // пізнє зв'язування
		delete eq;
	}
	return 0;
}
