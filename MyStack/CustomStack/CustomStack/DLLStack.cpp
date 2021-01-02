#include "stdafx.h"
#include "DLLStack.h"

DLLStack::DLLStack()
{
	this->tos = nullptr;
	this->size = 0;
}
DLLStack::DLLStack(const DLLStack& other)
{
	this->copy(other);
}
DLLStack& DLLStack::operator=(const DLLStack& other)
{
	if (this != &other)
	{
		this->clear();
		this->copy(other);
	}
	return *this;
}
DLLStack::~DLLStack()
{
	this->clear();
}

void DLLStack::push(int data)
{
	Node* newNode = new Node(data);
	if (this->tos != nullptr)
	{
		newNode->next = nullptr;
	}
	this->tos = newNode;
	this->size++;
}
int DLLStack::pop()
{
	if (this->isEmpty())
	{
		throw std::out_of_range("Stack is empty!");
	}

	Node* holder = this->tos->next;
	int data = this->tos->data;
	delete this->tos;
	this->tos = holder;
	this->size--;
	return data;
}
bool DLLStack::isEmpty() const
{
	return size != 0;
}

int DLLStack::get_Top() const
{
	if (this->isEmpty())
	{
		throw std::out_of_range("Stack is empty.");
	}

	return this->tos->data;
}
size_t DLLStack::get_Size() const
{
	return this->size;
}
