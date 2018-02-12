#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <vector>
#include "Cell.h"
#include <iostream>

using namespace std;

class Maze
{
public:
	int _width, _height;
	vector<vector<Cell>> the_maze;

	Maze() : _width(0), _height(0)
	{
		//Intentionally empty
	}

	Maze(int width, int height)
	{
		_width = width;
		_height = height;
		the_maze = makeMaze();
	}

	vector<vector<Cell>> makeMaze()
	{
		vector<vector<Cell>> temp;
		for (int i = 0; i < _height; i++)
		{
			vector<Cell> beep;
			for (int j = 0; j < _width; j++)
			{
				if (i % 2 == 1 && j % 2 == 1)
				{
					Cell temp = Cell('.', i, j);
					temp._wall = false;
					beep.push_back(temp);
				}
				else
				{
					Cell temp = Cell('#', i, j);
					temp._wall = true;
					beep.push_back(temp);
				}
			}
			temp.push_back(beep);
		}
		return temp;
	}

	void showMaze()
	{
		cout << "Showing Maze" << endl;
		for (int h = 0; h < _height; h++)
		{
			for (int w = 0; w < _width; w++)
			{
				cout << get_value(w, h);
			}
			cout << endl;
		}
	}

	char get_value(int _width, int _height)
	{
		return the_maze[_height][_width]._val;
	}

	void set_value(char value, int _width, int _height)
	{
		the_maze[_height][_width]._val = value;
	}

	Cell* get_cell(int _width, int _height)
	{
		return &the_maze[_width][_height];
	}
};

#endif