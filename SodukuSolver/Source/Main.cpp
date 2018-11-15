#include "Grid.h"
#include <Windows.h>
#include <WinUser.h>

Grid grid;

void AddNumbers() {
	int x = 0, y = 0;
	Node* current = grid.topLeft;
	short keysDown;
	bool done = false;

	while (!done) {

		if (GetAsyncKeyState('A') < 0 && keysDown & 1) {
			keysDown--;
			if (x != 0) {
				x--;
			}
		}
		if (GetAsyncKeyState('A') > 0 && !(keysDown & 1)) {
			keysDown++;
		}

		if (GetAsyncKeyState('D') < 0 && keysDown & 2) {
			keysDown -= 2;
			if (x != 8) {
				x++;
			}
		}
		if (GetAsyncKeyState('D') > 0 && !(keysDown & 2)) {
			keysDown += 2;
		}

		if (GetAsyncKeyState('W') < 0 && keysDown & 4) {
			keysDown -= 4;
			if (y != 0) {
				y--;
			}
		}
		if (GetAsyncKeyState('W') > 0 && !(keysDown & 4)) {
			keysDown += 4;
		}

		if (GetAsyncKeyState('S') < 0 && keysDown & 8) {
			keysDown += 8;
			if (y != 8) {
				y++;
			}
		}
		if (GetAsyncKeyState('A') > 0 && !(keysDown & 8)) {
			keysDown -= 8;
		}


	}


}


void main() {

	grid.CreateGrid();
	AddNumbers();

}
