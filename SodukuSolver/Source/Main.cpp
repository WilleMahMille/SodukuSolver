#include "Grid.h"

Grid grid;



void updateSodoku(int x, int y) {
	COORD mousePos = { x * 3 + 2 + (x / 3), y + 1 + (y / 3) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mousePos);
}

void ManageInput() {
	int x = 0, y = 0;

	bool done = false;
	int keysDown = 0;
	updateSodoku(x, y);
	while (!done) {
		//a
		if ((GetAsyncKeyState('A') < 0 || GetAsyncKeyState(VK_LEFT) < 0) && keysDown & 1) {
			keysDown ^= 1;
			if (x != 0) {
				x--;
			}
			updateSodoku(x, y);
		}
		if ((!(GetAsyncKeyState('A') < 0) && !(GetAsyncKeyState(VK_LEFT) < 0)) && !(keysDown & 1)) {
			keysDown |= 1;
		}
		//d
		if ((GetAsyncKeyState('D') < 0 || GetAsyncKeyState(VK_RIGHT) < 0) && keysDown & 2) {
			keysDown ^= 2;
			if (x != 8) {
				x++;
			}
			updateSodoku(x, y);
		}
		if ((!(GetAsyncKeyState('D') < 0) && !(GetAsyncKeyState(VK_RIGHT) < 0)) && !(keysDown & 2)) {
			keysDown |= 2;
		}
		//w
		if ((GetAsyncKeyState('W') < 0 || GetAsyncKeyState(VK_UP) < 0) && keysDown & 4) {
			keysDown ^= 4;
			if (y != 0) {
				y--;
			}
			updateSodoku(x, y);
		}
		if ((!(GetAsyncKeyState('W') < 0) && !(GetAsyncKeyState(VK_UP) < 0)) && !(keysDown & 4)) {
			keysDown |= 4;
		}
		//s
		if ((GetAsyncKeyState('S') < 0 || GetAsyncKeyState(VK_DOWN) < 0) && keysDown & 8) {
			keysDown ^= 8;
			if (y != 8) {
				y++;
			}
			updateSodoku(x, y);
		}
		if ((!(GetAsyncKeyState('S') < 0) && !(GetAsyncKeyState(VK_DOWN) < 0)) && !(keysDown & 8)) {
			keysDown |= 8;
		}

		for (int i = 0; i <= 9; i++) {
			if (GetAsyncKeyState(std::to_string(i)[0]) < 0 || GetAsyncKeyState(0x60 + i) < 0) {
				grid.SetNodeValue(x, y, i);
				updateSodoku(x, y);

			}
		}
		if (GetAsyncKeyState(VK_RETURN)) {
			return;
		}
		

	}


}


void SeePossible() {
	Node* current;
	std::cout << "Which coordinate do you want to get the possible numbers from? (x, enter, y, enter)";
	while (true) {

		int x;
		std::cin >> x;
		int y;
		std::cin >> y;
		current = grid.topLeft;
		for (int i = 0; i < x; i++) {
			current = current->right;
		}
		for (int i = 0; i < y; i++) {
			current = current->down;
		}
		for (int i = 0; i < 10; i++) {
			std::cout << "(" << i << ": " << current->possible[i] << ") ";
		}
		std::cout << "\n";
	}
}


int main() {
	SetConsoleOutputCP(65001);
	grid.CreateGrid();
	grid.PrintGrid();
	ManageInput();
	grid.Solve();
	SeePossible();

}


