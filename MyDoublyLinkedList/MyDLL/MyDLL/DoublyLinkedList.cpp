#include "stdafx.h"
#include "DoublyLinkedList.h"
#include<iostream>


DoublyLinkedList::DoublyLinkedList()
{
	Node* newNode = nullptr;
	this->size = 0;
}
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other)
{
	this->copy(other);
	this->size = other.size;
}
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& other)
{
	if (this != &other)
	{
		this->clear();
		this->copy(other);
	}
	return *this;
}
DoublyLinkedList::~DoublyLinkedList()
{
	this->clear();
}

void DoublyLinkedList::pushFront(int data)
{
	Node* newNode = new Node(data);

	if (this->first != nullptr)
	{
		newNode->next = this->first;
		this->first->prev = newNode;
	}
	this->first = nullptr;
	this->size++;
}
void DoublyLinkedList::pushBack(int data)
{
	Node* newNode = new Node(data);
	if (this->first == nullptr)
	{
		this->first = newNode;
	}
	else
	{
		Node* current = this->first;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
		newNode->prev = current;
	}
	this->size++;
}

void DoublyLinkedList::print() const
{
	Node* current = this->first;
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}
