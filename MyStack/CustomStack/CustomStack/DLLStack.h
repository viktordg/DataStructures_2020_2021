#pragma once
#include<iostream>

class DLLStack
{
private:
	struct Node
	{
		int data;
		Node* prev;
		Node* next;

		Node(int data, Node* prev = nullptr, Node* next = nullptr)
		{
			this->data = data;
			this->prev = prev;
			this->next = next;
		}
	};

	Node* tos;
	size_t size;

	void copy(const DLLStack& other)
	{
		this->size = other.size;
		this->tos = new Node(other.tos->data);

		Node* otherCurrent = other.tos;
		Node* copyCurrent = this->tos;

		while (otherCurrent->next != nullptr)
		{
			Node* holder = new Node(otherCurrent->next->data);
			copyCurrent->next = holder;
			copyCurrent = copyCurrent->next;
			otherCurrent = otherCurrent->next;
		}
	}
	void clear()
	{
		while (tos != nullptr)
		{
			Node* holder = nullptr;
			while (this->tos != nullptr)
			{
				holder = this->tos->next;
				delete this->tos;
				this->tos = holder;
			}
			this->size = 0;
		}
	}
public:
	DLLStack();
	DLLStack(const DLLStack& other);
	DLLStack& operator=(const DLLStack& other);
	~DLLStack();

	void push(int data);
	int pop();
	bool isEmpty() const;

	int get_Top() const;
	size_t get_Size() const;
};

