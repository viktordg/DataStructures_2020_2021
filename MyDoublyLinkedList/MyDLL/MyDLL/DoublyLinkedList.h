#pragma once
class DoublyLinkedList
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

	Node* first;
	size_t size;

	void copy(const DoublyLinkedList& other)
	{
		this->size = other.size;

		Node* copyFirst = new Node(other.first->data);
		this->first = copyFirst;

		Node* otherCurrent = other.first;
		Node* copyCurrent = this->first; 
		Node* newNode = nullptr;

		while (otherCurrent->next != nullptr)
		{
			newNode = new Node(otherCurrent->next->data);
			copyCurrent->next = newNode;
			newNode->prev = copyCurrent;

			otherCurrent = otherCurrent->next;
			copyCurrent = copyCurrent->next;
		}
	}
	void clear()
	{
		Node* holder = nullptr;
		while (this->first != nullptr)
		{
			holder = this->first->next;
			delete this->first;
			this->first = holder;
		}
		this->size = 0;
	}
public:

	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& other);
	DoublyLinkedList& operator=(const DoublyLinkedList& other);
	~DoublyLinkedList();

	void pushFront(int data);
	void pushBack(int data);

	void print() const;
};

