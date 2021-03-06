#include "stdafx.h"
#include<iostream>

struct Node
{
	int data;
	Node* next;
	Node* prev;

	Node(int data, Node* next = nullptr, Node* prev = nullptr)
	{
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};

void pushBack(Node* &first, int data)
{
	Node* newNode = new Node(data);
	if (first == nullptr)
	{
		first = newNode;
	}
	else
	{
		Node* current = first;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
		newNode->prev = current;
	}
}

void print(Node* first)
{
	while (first != nullptr)
	{
		std::cout << first->data << " ";
		first = first->next;
	}
	std::cout << "\n";
}

void reverseAfter(Node* first, int k)
{
	int countAll = 1;
	if (first == nullptr)
	{
		return;
	}

	int count = 1;
	Node* current = first;
	while (count < k)
	{
		if (current->next == nullptr)
		{
			return;
		}
		current = current->next;
		count++;
		countAll++;
	}

	if (current->next == nullptr || current->next->next == nullptr)
	{
		return;
	}

	Node* holder = current;
	Node* secondCurrent = current;
	while (secondCurrent->next != nullptr)
	{
		secondCurrent = secondCurrent->next;
		countAll++;
	}

	std::cout << countAll << std::endl;

	/*Node* temp = nullptr;
	int secondCount = 1;
	while ((countAll - count) >= secondCount)
	{
		temp = secondCurrent->prev;
		current->next = secondCurrent;
		secondCurrent->prev = current;
		current = secondCurrent;
		secondCurrent = temp;

		secondCount++;
	}
	current->next = nullptr;*/

	Node* temp = nullptr;
	while (holder != temp)
	{
		temp = secondCurrent->prev;
		current->next = secondCurrent;
		secondCurrent->prev = current;
		current = secondCurrent;
		secondCurrent = temp;
	}
	current->next = nullptr;

}

int main()
{
	Node* first = nullptr;

	pushBack(first, 1);
	pushBack(first, 2);
	pushBack(first, 3);
	pushBack(first, 4);
	pushBack(first, 5);
	pushBack(first, 6);
	pushBack(first, 7);

	print(first);
	reverseAfter(first, 3);
	print(first);
    return 0;
}

