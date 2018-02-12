#pragma once
#ifndef CELL_H
#define CELL_H

#include <cstdlib>

using namespace std;
class Cell
{
public:
	int _x;
	int _y;
	bool _wall;
	bool _visited;
	char _val;
	vector<bool> neighbors;

	Cell()
	{
		_x = -1;
		_y = -1;
		_val = '#';
		for (int i = 0; i < 4; i++)
		{
			neighbors.push_back(false);
		}
		_visited = false;
	}

	Cell(char val, int x, int y)
	{
		_x = x;
		_y = y;
		_val = val;
		for (int i = 0; i < 4; i++)
		{
			neighbors.push_back(false);
		}
		_visited = false;
	}

};

#endif // !CELL_H