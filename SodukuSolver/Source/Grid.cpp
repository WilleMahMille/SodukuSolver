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

void Grid::UpdatePossible() {
	Node* current;
	for (int i = 0; i < 9; i++) {
		current = topLeft;
		for (int j = 0; j < i; j++) {
			current = topLeft->down;
		}
		for (int j = 0; j < 9; j++) {
			//check everything
			current->CheckRows();
			current->CheckSquare();

			current = current->right;
		}
	}


}

void Grid::PrintGrid() {
	Node* current;
	for (int i = 0; i < 3; i++) {
		std::cout << "███████████████████████████████\n";
		for (int h = 0; h < 3; h++) {
			current = topLeft;
			for (int j = 0; j < i; j++) {
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


void Node::CheckRows() {
	Node* current = this;
	for (int i = 0; i < x; i++) {
		current = current->left;
		possible[current->value] = 0;
	}
	current = this;
	for (int i = 0; i < 9 - x; i++) {
		current = current->right;
		possible[current->value] = 0;
	}
	current = this;
	for (int i = 0; i < y; i++) {
		current = current->up;
		possible[current->value] = 0;
	}
	current = this;
	for (int i = 0; i < 9 - y; i++) {
		current = current->down;
		possible[current->value] = 0;
	}

}

void Node::CheckSquare() {

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

