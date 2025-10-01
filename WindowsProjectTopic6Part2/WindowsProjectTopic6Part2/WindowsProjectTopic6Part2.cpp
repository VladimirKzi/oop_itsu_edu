// WindowsProjectTopic6.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "WindowsProjectTopic6Part2.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <oleidl.h>
#include <Mshtml.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

using namespace Gdiplus;

#define MAX_LOADSTRING 100

enum Light { RED, YELLOW, GREEN };
Light current = RED;

//Глобальные переменные
HINSTANCE hInst;                               // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

//объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

void DrawTraffic(Graphics& g);

// *** GUI ***
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	CoInitialize(NULL);
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, 100);
	LoadStringW(hInstance, IDC_WINDOWSPROJECTTOPIC6PART2, szWindowClass, 100);

	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECTTOPIC6PART2));

	MSG msg;

	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	GdiplusShutdown(gdiplusToken);

	return (int)msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECTTOPIC6PART2));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	//wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECTTOPIC6PART2);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; 

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN: {
		int y = HIWORD(lParam);
		if (y < 120) current = RED;
		else if (y < 240) current = YELLOW;
		else current = GREEN;
		InvalidateRect(hWnd, NULL, TRUE);
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		Graphics g(hdc);
		RECT rc; GetClientRect(hWnd, &rc);
		DrawTraffic(g);
		EndPaint(hWnd, &ps);
	}
	break;
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void DrawTraffic(Graphics& g) {
	SolidBrush black(Color(255, 30, 30, 30));
	g.FillRectangle(&black, 50, 30, 100, 300);

	Color off(255, 60, 60, 60);
	SolidBrush red(current == RED ? Color(255, 255, 0, 0) : off);
	SolidBrush yellow(current == YELLOW ? Color(255, 255, 255, 0) : off);
	SolidBrush green(current == GREEN ? Color(255, 0, 255, 0) : off);

	g.FillEllipse(&red, 65, 40, 70, 70);
	g.FillEllipse(&yellow, 65, 160, 70, 70);
	g.FillEllipse(&green, 65, 280, 70, 70);
}