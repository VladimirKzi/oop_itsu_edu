// ConsoleApplicationLab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <Windows.h>

using namespace std;

// ===== Task 1 =====
class Figura {
protected:
	double x, y;
public:
	Figura() : x(0), y(0) {}
	Figura(double X, double Y) : x(X), y(Y) {}
	virtual ~Figura() { cout << "Об'єкт ФІГУРА знищено\n"; }

	virtual void showInfo() const {
		cout << "Фігура з координатами вершини (" << x << ", " << y << ")\n";
	}

	virtual string getType() const { return "Figura"; }

	virtual void edit() {
		cout << "Введіть нові координати x і y: ";
		cin >> x >> y;
	}
};

class Konus : public Figura {
private:
	double radius, height;
public:
	Konus() : Figura(), radius(0), height(0) {}
	Konus(double X, double Y, double R, double H)
		: Figura(X, Y), radius(R), height(H) {}
	~Konus() override { cout << "Об'єкт КОНУС знищено\n"; }

	void showInfo() const override {
		cout << "Конус: вершина (" << x << ", " << y
			<< "), радіус = " << radius
			<< ", висота = " << height << endl;
	}

	string getType() const override { return "Konus"; }

	void edit() override {
		cout << "Редагування КОНУСА:\n";
		cout << "Введіть нові координати x, y, радіус і висоту: ";
		cin >> x >> y >> radius >> height;
	}
};

class Tsylindr : public Figura {
private:
	double radius, height;
public:
	Tsylindr() : Figura(), radius(0), height(0) {}
	Tsylindr(double X, double Y, double R, double H)
		: Figura(X, Y), radius(R), height(H) {}
	~Tsylindr() override { cout << "Об'єкт ЦИЛІНДР знищено\n"; }

	void showInfo() const override {
		cout << "Циліндр: вершина (" << x << ", " << y
			<< "), радіус = " << radius
			<< ", висота = " << height << endl;
	}

	string getType() const override { return "Tsylindr"; }

	void edit() override {
		cout << "Редагування ЦИЛІНДРА:\n";
		cout << "Введіть нові координати x, y, радіус і висоту: ";
		cin >> x >> y >> radius >> height;
	}
};

class Kulya : public Figura {
private:
	double radius;
public:
	Kulya() : Figura(), radius(0) {}
	Kulya(double X, double Y, double R)
		: Figura(X, Y), radius(R) {}
	~Kulya() override { cout << "Об'єкт КУЛЯ знищено\n"; }

	void showInfo() const override {
		cout << "Куля: центр (" << x << ", " << y
			<< "), радіус = " << radius << endl;
	}

	string getType() const override { return "Kulya"; }

	void edit() override {
		cout << "Редагування КУЛІ:\n";
		cout << "Введіть нові координати x, y та радіус: ";
		cin >> x >> y >> radius;
	}
};

void task1()
{
	vector<Figura*> figures;
	int choice;

	do {
		cout << "1. Додати конус\n";
		cout << "2. Додати циліндр\n";
		cout << "3. Додати кулю\n";
		cout << "4. Вивести всі фігури\n";
		cout << "5. Знайти фігуру за типом\n";
		cout << "6. Редагувати фігуру\n";
		cout << "0. Вихід\n";
		cout << "Ваш вибір: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			double x, y, r, h;
			cout << "Введіть x, y, радіус, висоту: ";
			cin >> x >> y >> r >> h;
			figures.push_back(new Konus(x, y, r, h));
			break;
		}
		case 2: {
			double x, y, r, h;
			cout << "Введіть x, y, радіус, висоту: ";
			cin >> x >> y >> r >> h;
			figures.push_back(new Tsylindr(x, y, r, h));
			break;
		}
		case 3: {
			double x, y, r;
			cout << "Введіть x, y, радіус: ";
			cin >> x >> y >> r;
			figures.push_back(new Kulya(x, y, r));
			break;
		}
		case 4: {
			cout << "\n=== Усі фігури ===\n";
			for (auto f : figures)
				f->showInfo();
			break;
		}
		case 5: {
			string type;
			cout << "Введіть тип фігури (Konus / Tsylindr / Kulya): ";
			cin >> type;
			bool found = false;
			for (auto f : figures) {
				if (f->getType() == type) {
					f->showInfo();
					found = true;
				}
			}
			if (!found)
				cout << "Фігури з типом '" << type << "' не знайдено!\n";
			break;
		}
		case 6: {
			int index;
			cout << "Введіть номер фігури для редагування (починаючи з 0): ";
			cin >> index;
			if (index >= 0 && index < figures.size())
				figures[index]->edit();
			else
				cout << "Невірний номер!\n";
			break;
		}
		case 0:
			cout << "Вихід з програми.\n";
			break;
		default:
			cout << "Невірний вибір!\n";
		}
	} while (choice != 0);

	for (auto f : figures)
		delete f;
}

// ===== Task 2 =====
class Rivnyannya {
protected:
	double x;
public:
	Rivnyannya() : x(0) {}
	virtual ~Rivnyannya() { cout << "Об'єкт РІВНЯННЯ знищено.\n"; }

	virtual void solve() = 0;
	virtual void showInfo() const = 0;
	virtual void edit() = 0;
	virtual string getType() const = 0;
};

// === (ax + b = 0) ===
class Linear : public Rivnyannya {
private:
	double a, b;
public:
	Linear() : a(0), b(0) {}
	Linear(double A, double B) : a(A), b(B) {}
	~Linear() override { cout << "Об'єкт ЛІНІЙНЕ РІВНЯННЯ знищено.\n"; }

	void solve() override {
		cout << "\nРозв'язок лінійного рівняння: " << a << "x + " << b << " = 0\n";
		if (a == 0 && b == 0)
			cout << "Безліч розв’язків.\n";
		else if (a == 0)
			cout << "Розв’язків немає.\n";
		else {
			x = -b / a;
			cout << "x = " << x << endl;
		}
	}

	void showInfo() const override {
		cout << "Лінійне рівняння: " << a << "x + " << b << " = 0\n";
	}

	void edit() override {
		cout << "Редагування коефіцієнтів a і b: ";
		cin >> a >> b;
	}

	string getType() const override { return "Linear"; }
};

// ===  (cx² + ax + b = 0) ===
class Quadratic : public Rivnyannya {
private:
	double a, b, c;
public:
	Quadratic() : a(0), b(0), c(0) {}
	Quadratic(double A, double B, double C) : a(A), b(B), c(C) {}
	~Quadratic() override { cout << "Об'єкт КВАДРАТНЕ РІВНЯННЯ знищено.\n"; }

	void solve() override {
		cout << "\nРозв'язок квадратного рівняння: "
			<< c << "x^2 + " << a << "x + " << b << " = 0\n";
		double D = a * a - 4 * c * b;
		if (c == 0) {
			cout << "Це не квадратне рівняння!\n";
			return;
		}
		if (D < 0)
			cout << "Розв’язків немає (D < 0).\n";
		else if (D == 0) {
			x = -a / (2 * c);
			cout << "Один корінь: x = " << x << endl;
		}
		else {
			double x1 = (-a + sqrt(D)) / (2 * c);
			double x2 = (-a - sqrt(D)) / (2 * c);
			cout << "Два корені: x1 = " << x1 << ", x2 = " << x2 << endl;
		}
	}

	void showInfo() const override {
		cout << "Квадратне рівняння: "
			<< c << "x^2 + " << a << "x + " << b << " = 0\n";
	}

	void edit() override {
		cout << "Редагування коефіцієнтів c, a, b: ";
		cin >> c >> a >> b;
	}

	string getType() const override { return "Quadratic"; }
};

void task2()
{
	vector<Rivnyannya*> equations;
	int choice;

	do {
		cout << "1. Додати лінійне рівняння\n";
		cout << "2. Додати квадратне рівняння\n";
		cout << "3. Вивести усі рівняння\n";
		cout << "4. Розв’язати усі рівняння\n";
		cout << "5. Знайти рівняння за типом\n";
		cout << "6. Редагувати рівняння\n";
		cout << "0. Вихід\n";
		cout << "Ваш вибір: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			double a, b;
			cout << "Введіть коефіцієнти a та b: ";
			cin >> a >> b;
			equations.push_back(new Linear(a, b));
			break;
		}
		case 2: {
			double c, a, b;
			cout << "Введіть коефіцієнти c, a, b: ";
			cin >> c >> a >> b;
			equations.push_back(new Quadratic(a, b, c));
			break;
		}
		case 3: {
			cout << "\n=== Список рівнянь ===\n";
			for (auto e : equations)
				e->showInfo();
			break;
		}
		case 4: {
			for (auto e : equations)
				e->solve();
			break;
		}
		case 5: {
			string type;
			cout << "Введіть тип рівняння (Linear / Quadratic): ";
			cin >> type;
			bool found = false;
			for (auto e : equations) {
				if (e->getType() == type) {
					e->showInfo();
					found = true;
				}
			}
			if (!found)
				cout << "Рівнянь з типом '" << type << "' не знайдено!\n";
			break;
		}
		case 6: {
			int index;
			cout << "Введіть номер рівняння для редагування (0.." << equations.size() - 1 << "): ";
			cin >> index;
			if (index >= 0 && index < equations.size())
				equations[index]->edit();
			else
				cout << "Невірний індекс!\n";
			break;
		}
		case 0:
			cout << "Вихід з програми.\n";
			break;
		default:
			cout << "Невірний вибір!\n";
		}
	} while (choice != 0);

	for (auto e : equations)
		delete e;
}

// ===== Main menu =====
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	do {
		std::cout << "\nВиберіть завдання (1, 2, 0 = вихід): ";
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
