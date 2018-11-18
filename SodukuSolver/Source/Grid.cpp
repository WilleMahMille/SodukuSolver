#include "Grid.h"


Grid::Grid() {

}

Grid::~Grid() {

}

void Grid::CreateGrid() {
	topLeft = new Node(0, 0);

	Node* top = topLeft;
	Node* current = topLeft;

	for (int i = 0; i < 8; i++) {
		current->right = new Node(i + 1, 0);
		current->right->left = current;
		current = current->right;
	}

	for (int i = 0; i < 8; i++) {
		current = topLeft;
		top = topLeft;
		for (int j = 0; j < i; j++) {
			current = current->down;
			top = top->down;
		}

		current->down = new Node(0, i + 1);
		current = current->down;
		current->up = top;
		for (int j = 0; j < 8; j++) {
			current->right = new Node(j + 1, i + 1);
			current->right->left = current;
			current = current->right;
			top = top->right;
			current->up = top;
			top->down = current;
		}
	}
}

void Grid::SetNodeValue(int x, int y, int value) {
	Node* current = topLeft;
	if (value == 0) {
		std::cout << " ";
	}
	else {
		std::cout << value;
	}
	for (int i = 0; i < x; i++) {
		current = current->right;
	}
	for (int i = 0; i < y; i++) {
		current = current->down;
	}
	current->value = value;
	if (value != 0) {
		current->ClearPossible();
	}
	else {
		for (int i = 0; i < 10; i++) {
			current->possible[i] = i;
		}
	
	}
}

void Grid::PrintGrid() {
	Node* current;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	

	for (int i = 0; i < 3; i++) {
		std::cout << "███████████████████████████████\n";
		for (int h = 0; h < 3; h++) {
			current = topLeft;
			for (int j = 0; j < i * 3 + h; j++) {
				current = current->down;
			}
			for (int j = 0; j < 3; j++) {
				std::cout << "█";
				for (int k = 0; k < 3; k++) {
					std::cout << "[";
					if (current->value == 0) {
						std::cout << " ";
					}
					else {
						std::cout << current->value;
					}
					std::cout << "]";
					current = current->right;
				}
			}
			std::cout << "█\n";
		}
	}
	std::cout << "███████████████████████████████\n";
}


void Grid::Solve() {
	int times = 0;
	while (!CheckDone()) {

		times++;
		PrintGrid();
		UpdatePossible();
		
		
		if (times == 100) {
			std::cout << "Sodoku not solvable (according to the available algorithms\n";
			system("pause");
			return;
		}
		system("pause");
	}
	PrintGrid();
	system("pause");
}

bool Grid::CheckDone() {
	Node* current;
	for (int i = 0; i < 9; i++) {
		current = topLeft;
		for (int j = 0; j < i; j++) {
			current = current->down;
		}
		for (int j = 0; j < 9; j++) {
			if (current->value == 0) {
				return false;
			}
			current = current->right;
		}
	}
	return true;
}

void Grid::UpdatePossible() {
	Node* current;
	for (int i = 0; i < 9; i++) {
		current = topLeft;
		for (int j = 0; j < i; j++) {
			current = current->down;
		}
		for (int j = 0; j < 9; j++) {
			if (current->value == 0) {
				//check everything
				current->CheckRows();
				current->CheckSquare();
				current->CheckValue();
			}

			current = current->right;
			

		}
	}
}

void Node::CheckRows() {
	Node* current = this;
	for (int i = 0; i < x; i++) {
		current = current->left;
		possible[current->value] = 0;
	}
	current = this;
	for (int i = 0; i < 8 - x; i++) {
		current = current->right;
		possible[current->value] = 0;
	}
	current = this;
	for (int i = 0; i < y; i++) {
		current = current->up;
		possible[current->value] = 0;
	}
	current = this;
	for (int i = 0; i < 8 - y; i++) {
		current = current->down;
		possible[current->value] = 0;
	}

}

void Node::CheckSquare() {
	Node* current = this;
	Node* topLeftSquare;
	for (int i = 0; i < x % 3; i++) {
		current = current->left;
	}
	for (int i = 0; i < y % 3; i++) {
		current = current->up;
	}
	topLeftSquare = current;
	for (int i = 0; i < 3; i++) {
		current = topLeftSquare;
		for (int j = 0; j < i; j++) {
			current = current->down;
		}
		for (int j = 0; j < 3; j++) {
			possible[current->value] = 0;
			current = current->right;
		}
	}

	//check if there are no possible squares for a specific number
	
	for (int i = 1; i <= 9; i++) {
		if (CheckSquareForNumber(i, topLeftSquare)) {
			value = i;
			ClearPossible();
		}
	}


}

bool Node::CheckSquareForNumber(int number, Node* topLeftSquare) {
	Node* nCurrent;

	for (int j = 0; j < 3; j++) {
		nCurrent = topLeftSquare;
		for (int k = 0; k < j; k++) {
			nCurrent = nCurrent->down;
		}
		for (int k = 0; k < 3; k++) {
			if ((nCurrent->possible[number] == number || nCurrent->value == number) && nCurrent != this) {
				return false;
			}
			nCurrent = nCurrent->right;
		}
	}
	return true;
}




void Node::CheckValue() {
	int possibleValues = 0;
	for (int i = 1; i <= 9; i++) {
		if (possible[i] != 0) {
			possibleValues++;
		}
	}
	if (possibleValues == 1) {
		for (int i = 1; i <= 9; i++) {
			if (possible[i] != 0) {
				value = possible[i];
				ClearPossible();
			}
		}
	}

}

void Node::ClearPossible() {
	for (int i = 0; i < 10; i++) {
		possible[i] = 0;
	}
}

Node::Node(int _x, int _y) {
	x = _x;
	y = _y;
	for (int i = 0; i < 10; i++) {
		possible[i] = i;
	}
	value = 0;
}

Node::~Node() {

}

