#include "stdafx.h"
#include<iostream>

struct Node
{
	int data;
	Node* next;

	Node(int data, Node* next = nullptr)
	{
		this->data = data;
		this->next = next;
	}
};

void push(Node* &first, int data)
{
	Node* newElem = new Node(data);
	if (first == nullptr)
	{
		first = newElem;
	}
	else
	{
		Node* holder = first;
		while (first->next != nullptr)
		{
			first = first->next;
		}
		first->next = newElem;
		first = holder;
	}
}

void print(Node* &first)
{
	Node* holder = first;
	while (first != nullptr)
	{
		std::cout << first->data << ' ';
		first = first->next;
	}
	std::cout << std::endl;
	first = holder;
}

void fillGaps(Node* &first)
{
	Node* firstHolder = first;

	if (first == nullptr)
	{
		std::cout << "List is empty!" << std::endl;
	}

	Node* current = first;
	Node* nextHolder = nullptr;
	while (current->next != nullptr)
	{
		int currentData = current->data;
		int nextData = current->next->data;
		if ((currentData + 1) != nextData)
		{
			nextHolder = current->next;
			Node* newNode = new Node(current->data + 1);
			newNode->next = nextHolder;
			current->next = newNode;
			current = newNode;
		}
		else
		{
			current = current->next;
		}
	}

	first = firstHolder;
}

int main()
{
	Node* first = nullptr;

	push(first, 1);
	push(first, 3);
	push(first, 4);
	push(first, 8);
	print(first);
	fillGaps(first);
	print(first);
    return 0;
}

