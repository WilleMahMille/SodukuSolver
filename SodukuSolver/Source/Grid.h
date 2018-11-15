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

	int value;

private:
	int x;
	int y;

};

class Grid {
public:
	Grid();
	~Grid();
	Node* topLeft;

	void CreateGrid();
	void PrintGrid();


	void SetNodeValue(int x, int y, int number);
	
	void UpdatePossible();
	void CheckPossible();



private:


};



