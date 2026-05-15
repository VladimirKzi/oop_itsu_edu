// ConsoleApplicationSem2Lab14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h>

using namespace std;

// ================================================
// ЗАВДАННЯ 1
// ================================================
void Task1() {
	cout << "\nЗавдання 1 \n";
	FILE* f = nullptr;
	fopen_s(&f, "t1.txt", "w");
	if (!f) { cout << "Помилка створення файлу!\n"; return; }

	cout << "Вводьте текст (закінчити символом #):\n";
	char ch;
	while ((ch = getchar()) != '#') {
		fputc(ch, f);
	}
	fclose(f);

	// Читання з файлу
	fopen_s(&f, "t1.txt", "r");
	cout << "\nЗміст файлу:\n";
	while ((ch = fgetc(f)) != EOF) putchar(ch);
	fclose(f);
}

// ================================================
// ЗАВДАННЯ 2
// ================================================
void Task2() {
	cout << "\nЗавдання 2 \n";
	int n;
	cout << "Введіть кількість рядків: ";
	cin >> n;
	cin.ignore();

	FILE* f = nullptr;
	fopen_s(&f, "t2.txt", "w");
	if (!f) return;

	char s[100];
	for (int i = 0; i < n; i++) {
		cout << "Рядок " << i + 1 << ": ";
		cin.getline(s, 100);
		fputs(s, f);
		fputs("\n", f);
	}
	fclose(f);
	cout << "Дані записано у t2.txt\n";
}

// ================================================
// ЗАВДАННЯ 3
// ================================================
void Task3() {
	cout << "\nЗавдання 3 \n";
	FILE *f1 = nullptr, *f2 = nullptr;
	fopen_s(&f1, "t3_1.txt", "w");
	int x, sum = 0, k = 0;

	for (int i = 0; i < 20; i++) {
		x = rand() % 20 + 1;  // позитивні
		fprintf(f1, "%2d ", x);
		sum += x;
		k++;
	}
	fclose(f1);

	// Копіювання у другий файл
	fopen_s(&f1, "t3_1.txt", "r");
	fopen_s(&f2, "t3_2.txt", "w");
	for (int i = 0; i < k; i++) {
		fscanf_s(f1, "%d", &x);
		fprintf(f2, "%2d ", x);
	}
	fclose(f1); fclose(f2);

	cout << "Середнє арифметичне: " << (double)sum / k << endl;
}

// ================================================
// ЗАВДАННЯ 4
// ================================================
void Task4() {
	cout << "\nЗавдання 4 \n";
	char name[30];
	cout << "Введіть ім'я файлу: ";
	cin.getline(name, 30);

	FILE* f = nullptr;
	fopen_s(&f, name, "wb");
	int x, max_val = 0;
	for (int i = 0; i < 10; i++) {
		x = rand() % 50;
		fwrite(&x, sizeof(int), 1, f);
	}
	fclose(f);

	fopen_s(&f, name, "rb");
	cout << "Числа з файлу: ";
	for (int i = 0; i < 10; i++) {
		fread(&x, sizeof(int), 1, f);
		cout << x << " ";
		if (x > max_val) max_val = x;
	}
	fclose(f);
	cout << "\nМаксимальне: " << max_val << endl;
}

// ================================================
// ЗАВДАННЯ 5
// ================================================
void Task5() {
	cout << "\nЗавдання 5 \n";
	FILE* f = nullptr;
	fopen_s(&f, "mas.dat", "wb");
	int mas[5] = { 10, 20, 30, 40, 50 };
	fwrite(mas, sizeof(int), 5, f);
	fclose(f);

	fopen_s(&f, "mas.dat", "rb");
	int mas2[5];
	cout << "Масив з файлу: ";
	for (int i = 0; i < 5; i++) {
		fread(&mas2[i], sizeof(int), 1, f);
		cout << mas2[i] << " ";
	}
	fclose(f);
	cout << endl;
}

// ================================================
// ЗАВДАННЯ 6
// ================================================
void Task6() {
	cout << "\nЗавдання 6 \n";
	FILE* f = nullptr;
	fopen_s(&f, "t6.dat", "wb");
	int mas[11] = { 0,11,22,33,44,55,66,77,88,99,100 };
	fwrite(mas, sizeof(int), 11, f);
	fclose(f);

	fopen_s(&f, "t6.dat", "rb");
	int x;
	fseek(f, 5 * sizeof(int), SEEK_SET);
	fread(&x, sizeof(int), 1, f);
	cout << "5-й елемент: " << x << endl;
	fclose(f);
}

// ================================================
// ЗАВДАННЯ 7
// ================================================
void Task7() {
	cout << "\nЗавдання 7 \n";
	FILE* f = nullptr;
	fopen_s(&f, "t7.dat", "wb");
	int mas[10], max_val = 0, max_idx = 0;
	for (int i = 0; i < 10; i++) {
		mas[i] = rand() % 50;
		cout << mas[i] << " ";
	}
	fwrite(mas, sizeof(int), 10, f);
	fclose(f);

	fopen_s(&f, "t7.dat", "r+b");
	for (int i = 0; i < 10; i++) {
		fread(&mas[i], sizeof(int), 1, f);
		if (mas[i] > max_val) {
			max_val = mas[i];
			max_idx = i;
		}
	}

	fseek(f, max_idx * sizeof(int), SEEK_SET);
	int zero = 0;
	fwrite(&zero, sizeof(int), 1, f);
	fclose(f);

	cout << "\nМаксимальне " << max_val << " замінено на 0.\n";
}

// ================================================
// ЗАВДАННЯ 8 — Кролики
// ================================================
struct Rabbit {
	int id, old, massa;
};

void Task8() {
	cout << "\nЗавдання 8: Кролики \n";
	FILE* f = nullptr;
	fopen_s(&f, "rabbits.dat", "wb");

	int n;
	cout << "Кількість кроликів: "; cin >> n;

	Rabbit dat, best = { 0,0,0 };
	for (int i = 0; i < n; i++) {
		cout << "id вік маса: ";
		cin >> dat.id >> dat.old >> dat.massa;
		fwrite(&dat, sizeof(Rabbit), 1, f);
	}
	fclose(f);

	fopen_s(&f, "rabbits.dat", "rb");
	fread(&best, sizeof(Rabbit), 1, f);
	while (fread(&dat, sizeof(Rabbit), 1, f) == 1) {
		if (dat.old > best.old ||
			(dat.old == best.old && dat.massa > best.massa))
			best = dat;
	}
	fclose(f);

	cout << "Найкращий кролик → ID: " << best.id
		<< ", Вік: " << best.old
		<< ", Маса: " << best.massa << endl;
}

// ================================================
// ЗАВДАННЯ 9
// ================================================
void Task9() {
	cout << "\nЗавдання 9: Дописування структури \n";
	struct Point { int x, y; };
	FILE* f = nullptr;

	fopen_s(&f, "points.dat", "wb");
	Point p;
	for (int i = 0; i < 3; i++) {
		cout << "x y: "; cin >> p.x >> p.y;
		fwrite(&p, sizeof(Point), 1, f);
	}
	fclose(f);

	// Дописування
	fopen_s(&f, "points.dat", "ab");
	p.x = 99; p.y = 99;
	fwrite(&p, sizeof(Point), 1, f);
	fclose(f);

	cout << "Додано точку (99,99) в кінець файлу.\n";
}

// ================================================
// ЗАВДАННЯ 10
// ================================================
void Task10() {
	cout << "\nЗавдання 10 \n";
	const int n = 5;
	int mas[n];
	cout << "Масив: ";
	for (int i = 0; i < n; i++) {
		mas[i] = rand() % 10 - 4;
		cout << mas[i] << " ";
	}
	cout << endl;

	FILE* f = nullptr;
	fopen_s(&f, "mas10.dat", "wb");
	fwrite(mas, sizeof(int), n, f);
	fclose(f);

	// Читання та обчислення
	fopen_s(&f, "mas10.dat", "rb");
	int sum_neg = 0, prod_pos = 1, x;
	for (int i = 0; i < n; i++) {
		fread(&x, sizeof(int), 1, f);
		if (x > 0) prod_pos *= x;
		else sum_neg += x;
	}
	fclose(f);

	cout << "Сума від'ємних: " << sum_neg << endl;
	cout << "Добуток додатних: " << prod_pos << endl;
}

// ================================================
// MAIN
// ================================================

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Task1();
	Task2();
	Task3();
	Task4();
	Task5();
	Task6();
	Task7();
	Task8();
	Task9();
	Task10();

	return 0;
}
