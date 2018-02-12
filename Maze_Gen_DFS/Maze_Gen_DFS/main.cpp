#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <time.h>
#include "Cell.h"
#include "MyStack.h"
#include "Maze.h"

using namespace std;

bool getNeighbors(Maze* the_maze, int _x, int _y, int width, int height);
Cell* pickNeighbor(Maze* the_maze, int _x, int _y);

int main()
{
	srand(time(NULL));
	cout << "Welcome to the Maze Builder!" << endl;
	cout << "Entered desired width(odd integer >= 5): --> ";
	string width;
	getline(cin, width);
	if (stoi(width) < 5 || stoi(width) % 2 == 0)
	{
		cout << "Invalid width. exiting..." << endl;
		exit(0);
	}
	cout << "Entered desired height(odd integer >= 5): --> ";
	string height;
	getline(cin, height);
	if (stoi(height) < 5 || stoi(height) % 2 == 0)
	{
		cout << "Invalid height. exiting..." << endl;
		exit(0);
	}

	Maze the_maze = Maze(stoi(width), stoi(height));
	
	MyStack the_Stack = MyStack(0);

	Cell* current = the_maze.get_cell(1, 1);
	current->_visited = true;

	do
	{
		if (getNeighbors(&the_maze, current->_x, current->_y, stoi(width), stoi(height)))
		{
			Cell* next = pickNeighbor(&the_maze, current->_x, current->_y);
			the_Stack._push(current);
			Cell* temp = the_maze.get_cell((current->_x + next->_x) / 2, (current->_y + next->_y) / 2);
			temp->_wall = false;
			temp->_val = '.';
			current = next;
			current->_visited = true;
		}
		else if(!the_Stack._empty())
		{
			current = the_Stack._pop();
		}
	} while (!the_Stack._empty());

	Cell* temp = the_maze.get_cell(1, 1);
	temp->_val = 'o';
	temp = the_maze.get_cell(stoi(width) - 2, stoi(height) - 2);
	temp->_val = '*';
	the_maze.showMaze();
	
	return 0;
}

bool getNeighbors(Maze* the_maze, int _x, int _y, int width, int height)
{
	for (int i = 0; i < 4; i++)
	{
		the_maze->get_cell(_x, _y)->neighbors.at(i) = false;
	}
	if (_y - 2 > 0 && the_maze->get_cell(_x, _y - 2)->_visited == false)
	{
		the_maze->get_cell(_x, _y)->neighbors.at(0) = true;
	}
	if (_x - 2 > 0 && the_maze->get_cell(_x - 2, _y)->_visited == false)
	{
		the_maze->get_cell(_x, _y)->neighbors.at(1) = true;
	}
	if (_x + 2 < width && the_maze->get_cell(_x + 2, _y)->_visited == false)
	{
		the_maze->get_cell(_x, _y)->neighbors.at(2) = true;
	}
	if (_y + 2 < height && the_maze->get_cell(_x, _y + 2)->_visited == false)
	{
		the_maze->get_cell(_x, _y)->neighbors.at(3) = true;
	}

	for (int i = 0; i < 4; i++)
	{
		if (the_maze->get_cell(_x, _y)->neighbors.at(i))
		{
			return true;
		}
	}
	return false;
}

Cell* pickNeighbor(Maze* the_maze, int _x, int _y)
{
	Cell* temp = the_maze->get_cell(_x, _y);
	bool chosen = false;
	int num;
	while (!chosen)
	{
		num = floor(rand() % 4);
		if (the_maze->get_cell(_x, _y)->neighbors.at(num))
		{
			chosen = true;
			switch (num)
			{
			case 0:
				temp = the_maze->get_cell(_x, _y - 2);
				break;
			case 1:
				temp = the_maze->get_cell(_x - 2, _y);
				break;
			case 2:
				temp = the_maze->get_cell(_x + 2, _y);
				break;
			case 3:
				temp = the_maze->get_cell(_x, _y + 2);
				break;
			}
		}
	}
	return temp;
}