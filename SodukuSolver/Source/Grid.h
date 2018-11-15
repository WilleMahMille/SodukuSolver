#pragma once
#include <iostream>


class Node {
public:
	Node(int _x, int _y);
	~Node();

	Node* left;
	Node* right;
	Node* up;
	Node* down;

	int possible[10];

	void WriteCoords();

	void CheckRows();
	void CheckSquare();

private:
	int x;
	int y;
	int value;

};

class Grid {
public:
	Grid();
	~Grid();
	Node* topLeft;

	void CreateGrid();

	void SetNodeValue(int x, int y, int number);
	
	void UpdatePossible();
	void CheckPossible();



private:


};



