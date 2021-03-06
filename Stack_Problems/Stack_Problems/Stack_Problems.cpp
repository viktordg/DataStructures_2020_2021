#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<stack>

bool isPalidrome(std::stack<char>& stack)
{
	int stackSize = stack.size();

	std::vector<char> inputVect;
	for (size_t i = 0; i < stackSize; i++)
	{
		inputVect.push_back(stack.top());
		stack.pop();
	}

	int mid = stackSize / 2;

	std::stack<char> half;
	int i;
	for (i = 0; i < mid; i++) 
	{
		half.push(inputVect[i]);
	}

	if (stackSize % 2 != 0)
	{
		i++;
	}

	while (i <= stackSize)
	{
		char ele = half.top();

		if (ele != inputVect[i])
		{
			return 0;
		}

		i++;
	}

	return 1;
}

int main()
{
	std::stack<char> stack;
	stack.push('A');
	stack.push('G');
	stack.push('C');
	stack.push('B');
	stack.push('A');

	std::cout << isPalidrome(stack) << std::endl;
    return 0;
}

