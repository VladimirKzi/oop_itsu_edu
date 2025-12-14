// ConsoleApplicationDCW1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

class base {
public:
	int i;
	base(int x) { i = x; }
	// додайте визначення віртуальної функції
	virtual void func() { std::cout << "base = " << i << std::endl; }
};

class derived1 : public base {
public:
	derived1(int x) : base(x) { }
	// додайте визначення віртуальної функції
	void func() override { std::cout << "derived1 = " << i * i << std::endl; }
};

class derived2 : public base {
public:
	derived2(int x) : base(x) { }
	// у derived2 функція func() не перевизначається
};

void main() {
	base *p;
	base ob(10);
	derived1 d_ob1(10);
	derived2 d_ob2(10);
	p = &ob;
	p->func();
	p = &d_ob1;
	p->func();
	p = &d_ob2;
	p->func();
}

