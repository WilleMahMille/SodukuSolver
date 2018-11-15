#include "Grid.h"
#include <Windows.h>
#include <WinUser.h>
#include <stdio.h>
#include <conio.h>

Grid grid;



void updateSodoku(int x, int y) {
	COORD mousePos = { x * 3 + 2 + (x / 3), y + 1 + (y / 3) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mousePos);
}

void GetInput() {
	int x = 0, y = 0;

	bool done = false;
	short keysDown = 0;
	updateSodoku(x, y);
	while (!done) {
		//a
		if (GetAsyncKeyState('A') < 0 && keysDown & 1) {
			keysDown ^= 1;
			if (x != 0) {
				x--;
			}
			updateSodoku(x, y);
		}
		if (!(GetAsyncKeyState('A') < 0) && !(keysDown & 1)) {
			keysDown |= 1;
		}
		//d
		if (GetAsyncKeyState('D') < 0 && keysDown & 2) {
			keysDown ^= 2;

			if (x != 8) {
				x++;
			}
			updateSodoku(x, y);
		}
		if (!(GetAsyncKeyState('D') < 0) && !(keysDown & 2)) {
			keysDown |= 2;
		}
		//w
		if (GetAsyncKeyState('W') < 0 && keysDown & 4) {
			keysDown ^= 4;
			if (y != 0) {
				y--;
			}
			updateSodoku(x, y);
		}
		if (!(GetAsyncKeyState('W') < 0) && !(keysDown & 4)) {
			keysDown |= 4;
		}
		//s
		if (GetAsyncKeyState('S') < 0 && keysDown & 8) {
			keysDown ^= 8;
			if (y != 8) {
				y++;
			}
			updateSodoku(x, y);
		}
		if (!(GetAsyncKeyState('S') < 0) && !(keysDown & 8)) {
			keysDown |= 8;
		}

	}


}



int main() {
	SetConsoleOutputCP(65001);
	grid.CreateGrid();
	grid.PrintGrid();

	AddNumbers();

}
