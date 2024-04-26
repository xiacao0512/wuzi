// Wuzi chess game
// program by ET-16G, Apr. 5 2024
// Follwing code comes from Ghdgtdgu

#include <stdarg.h>
#include <stdio.h>
#include <windows.h>
#include "..\include\console.h"

void gotoXY(Coord sCoord)
{
	COORD stCoord;
	HANDLE hConsole;
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	stCoord.X = sCoord.x;
	stCoord.Y = sCoord.y;
	
	SetConsoleCursorPosition(hConsole, stCoord);
	return;
}

#define STRING_LENGTH   2048
void printf_ex(Coord sCoord, int color, const char *str, ...)
{
	char buf0[STRING_LENGTH];
	HANDLE hConsole;
	
	va_list arg0;
	va_start(arg0, str);
	vsprintf(buf0, str, arg0);
	va_end(arg0);
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoXY(sCoord);
	SetConsoleTextAttribute(hConsole, color);
	WriteConsole(hConsole, buf0, strlen(buf0), NULL, 0);
	
	return;
}

void putchar_ex(Coord sCoord, int color, const char c)
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    gotoXY(sCoord);
	SetConsoleTextAttribute(hConsole, color);
	putchar(c);
	
	return;
}
