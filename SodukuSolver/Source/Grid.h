#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <WinUser.h>
#include <WinBase.h>

class Node {
public:
	Node(int _x, int _y);
	~Node();

	Node* left;
	Node* right;
	Node* up;
	Node* down;

	int possible[10];

	void ClearPossible();

	void CheckRows();
	void CheckSquare();
	void CheckValue();
	bool CheckSquareForNumber(int number, Node* topLeftSquare);

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
	void Solve();

	void SetNodeValue(int x, int y, int number);
	
	bool CheckDone();
	void UpdatePossible();
	void CheckPossible();



private:


};



