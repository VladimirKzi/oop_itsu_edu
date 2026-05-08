// ConsoleApplicationDKR.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

template<typename T>
class Stack
{
	std::vector<T> data;
public:
	void push(const T& item) { data.push_back(item); }
	T pop()
	{
		T top = data.back(); data.pop_back(); return top;
	}
	size_t size() { return data.size(); }
	string findLongest() {
		string longest = "";
		for (const auto& s : data) if (s.length() > longest.length()) longest = s;
		return longest;
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	Stack<string> s;
	s.push("hello"); s.push("world!");
	cout << "Найдовший: " << s.findLongest() << endl;
	return 0;
}

