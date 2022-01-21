#include "Console.h"
#include <windows.h>
#include <stdio.h>

void Console::SetCursorPosition(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void Console::SetColor(Console::Color bg, Console::Color  tx)
{
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(out_handle, (WORD)((bg << 4) | tx));
}

void Console::Cursor(bool enabled)
{
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = enabled;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}