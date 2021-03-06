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

void addAfter(Node* &first, int afterElement, int addElement)
{
	if (first == nullptr)
	{
		return;
	}

	Node* newNode = new Node(addElement);
	Node* current = first;

	while (current != nullptr && current->data != afterElement)
	{
		current = current->next;
	}

	if (current->next == nullptr)
	{
		current->next = newNode;
		newNode->prev = current;
	}
	else
	{
		newNode->next = current->next;
		newNode->prev = current;
		current->next = newNode;
		current->next->prev = newNode;
	}
}
void moveLast(Node* &first)
{
	if (first == nullptr)
	{
		return;
	}

	Node* current = first;
	while (current->next != nullptr)
	{
		current = current->next;
	}

	current->prev->next = nullptr;
	current->prev = nullptr;
	current->next = first;
	first->prev = current;
	first = current;
}
void addElement(Node* &first, int N, int element)
{
	if (first == nullptr)
	{
		return;
	}

	int count = 0;
	Node* current = first;
	while (current != nullptr)
	{
		
		if (count == 3)
		{
			Node* newNode = new Node(element);
			if (current->next == nullptr)
			{
				current->next = newNode;
				newNode->prev = current;
			}
			else
			{
				newNode->prev = current;
				newNode->next = current->next;
				current->next->prev = newNode;
				current->next = newNode;
			}
			count == 0;
		}

		count++;
		current = current->next;
	}
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
	addAfter(first, 3, 9);
	addAfter(first, 5, 9);
	moveLast(first);
	print(first);

	return 0;
}

