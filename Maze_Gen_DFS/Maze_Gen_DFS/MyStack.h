#pragma once
#ifndef MYSTACK_H
#define MYSTACK_H

#include <vector>
#include "Cell.h"
#include <cstdlib>

using namespace std;

class MyStack
{
public:
	vector<Cell*> _stack;
	int _size;

	MyStack(int size)
	{
		_size = size;
	}

	void _push(Cell* toAdd)
	{
		_stack.push_back(toAdd);
		_size++;
	}

	Cell* _pop()
	{
		_size--;
		Cell* _temp = _stack[_size];
		_stack.pop_back();
		return _temp;
	}

	bool _empty()
	{
		return (_size == 0);
	}

};


#endif // !MYSTACK_H