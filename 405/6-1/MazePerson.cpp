#include "MazeMap.h"
#include <iostream>

void MazePerson::gotoxy(int x, int y)
{
	COORD cd;
	cd.X = x;
	cd.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDEL);
	SetConsoleCursorPosition(handle,cd);
}