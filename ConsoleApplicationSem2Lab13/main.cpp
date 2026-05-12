// ConsoleApplicationSem2Lab13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

// ================================================
// ЗАВДАННЯ 1
// ================================================
void Task1() {
	cout << "\nЗавдання 1: Заміна голосних\n";
	char S[100];
	char vowels[] = "aeiouyAEIOUY";
	char c;

	cout << "Введіть речення: ";
	cin.getline(S, 100);
	cout << "Введіть символ для заміни: ";
	c = getchar(); cin.ignore();

	for (int i = 0; S[i] != '\0'; i++) {
		for (int j = 0; vowels[j] != '\0'; j++) {
			if (S[i] == vowels[j]) {
				S[i] = c;
				break;
			}
		}
	}
	cout << "Результат: " << S << endl;
}

// ================================================
// ЗАВДАННЯ 2
// ================================================
void Task2() {
	cout << "\nЗавдання 2: Розбиття рядка\n";
	char S[100], S1[100], S2[100], ch;

	cout << "Введіть рядок: ";
	cin.getline(S, 100);
	cout << "Введіть символ-роздільник: ";
	ch = getchar(); cin.ignore();

	char* p = S;
	char* p1 = S1;
	char* p2 = S2;

	while (*p != ch && *p != '\0') *p1++ = *p++;
	*p1 = '\0';
	if (*p == ch) p++;
	while (*p) *p2++ = *p++;
	*p2 = '\0';

	cout << "До символу: " << S1 << endl;
	cout << "Після символу: " << S2 << endl;
}

// ================================================
// ЗАВДАННЯ 3
// ================================================
void Task3() {
	cout << "\nЗавдання 3: Виділення підрядка\n";
	char S[100], S1[100];
	int n, dl;

	cout << "Введіть рядок: ";
	cin.getline(S, 100);
	cout << "Позиція початку: "; cin >> n;
	cout << "Довжина підрядка: "; cin >> dl;
	cin.ignore();

	strncpy_s(S1, 100, S + n, dl);
	S1[dl] = '\0';
	cout << "Підрядок: " << S1 << endl;
}

// ================================================
// ЗАВДАННЯ 4
// ================================================
void Task4() {
	cout << "\nЗавдання 4: Видалення символів\n";
	char S[100], S1[100] = "";
	int poz, kol;

	cout << "Введіть рядок: ";
	cin.getline(S, 100);
	cout << "Позиція: "; cin >> poz;
	cout << "Кількість символів для видалення: "; cin >> kol;
	cin.ignore();

	strncpy_s(S1, 100, S, poz);
	strcat_s(S1, 100, S + poz + kol);
	cout << "Результат: " << S1 << endl;
}

// ================================================
// ЗАВДАННЯ 5
// ================================================
void Task5() {
	cout << "\nЗавдання 5: Кількість слів\n";
	char S[100];
	cout << "Введіть речення: ";
	cin.getline(S, 100);

	int count = 0;
	bool inWord = false;
	for (int i = 0; S[i] != '\0'; i++) {
		if (S[i] == ' ') inWord = false;
		else if (!inWord) {
			inWord = true;
			count++;
		}
	}
	cout << "Кількість слів: " << count << endl;
}

// ================================================
// ЗАВДАННЯ 6
// ================================================
void Task6() {
	cout << "\nЗавдання 6: Перше слово\n";
	char S[100], S1[100] = "";
	cout << "Введіть речення: ";
	cin.getline(S, 100);

	int i = 0, k = 0;
	while (S[i] != ' ' && S[i] != '\0') {
		S1[k++] = S[i++];
	}
	S1[k] = '\0';

	cout << "Перше слово: " << S1 << endl;
	cout << "Довжина: " << k << endl;
}

// ================================================
// ЗАВДАННЯ 7
// ================================================
void Task7() {
	cout << "\nЗавдання 7: Позиція n-го слова\n";
	char S[100];
	int nom, pos = 0, count = 0;

	cout << "Введіть речення: ";
	cin.getline(S, 100);
	cout << "Номер слова: "; cin >> nom;

	for (int i = 0; S[i] != '\0'; i++) {
		if (count == nom - 1) {
			cout << "Позиція слова: " << pos << endl;
			return;
		}
		if (S[i] == ' ') count++;
		pos++;
	}
	cout << "Слово не знайдено!\n";
}

// ================================================
// ЗАВДАННЯ 8
// ================================================
void Task8() {
	cout << "\nЗавдання 8: Заміна за алфавітом\n";
	char S[100], S1[100] = "";
	char a1[] = "1234567890";
	char a2[] = "abcdefghij";

	cout << "Введіть рядок (цифри): ";
	cin.getline(S, 100);

	int i = 0, j;
	while (S[i]) {
		for (j = 0; a1[j]; j++) {
			if (S[i] == a1[j]) {
				S1[i] = a2[j];
				break;
			}
		}
		i++;
	}
	S1[i] = '\0';
	cout << "Результат: " << S1 << endl;
}

// ================================================
// ЗАВДАННЯ 9
// ================================================
void Task9() {
	cout << "\nЗавдання 9: Виділення k слів\n";
	char S[100], S1[100] = "";
	int nom, kol;

	cout << "Введіть речення: ";
	cin.getline(S, 100);
	cout << "Номер слова: "; cin >> nom;
	cout << "Кількість слів: "; cin >> kol;
	cin.ignore();

	int wordCount = 0, i = 0, j = 0;

	// пропускаємо до потрібного слова
	while (wordCount < nom - 1 && S[i]) {
		if (S[i++] == ' ') wordCount++;
	}

	// копіюємо потрібну кількість слів
	int copiedWords = 0;
	while (copiedWords < kol && S[i]) {
		S1[j++] = S[i];
		if (S[i++] == ' ') copiedWords++;
	}
	S1[j] = '\0';

	cout << "Результат: " << S1 << endl;
}

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

	return 0;
}
