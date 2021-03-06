#include "stdafx.h"
#include<iostream>

template <class T>
struct TernTreeNode
{
	T data;
	TernTreeNode<T>* left;
	TernTreeNode<T>* middle;
	TernTreeNode<T>* right;

	TernTreeNode(T data, 
		TernTreeNode<T>* left = nullptr, 
		TernTreeNode<T>* middle = nullptr, 
		TernTreeNode<T>* right = nullptr)
	{
		this->data = data;
		this->left = left;
		this->middle = middle;
		this->right = right;
	}
};

template <class T>
TernTreeNode<T>* createTree(unsigned int h)
{
	if (h == 0)
	{
		return nullptr;
	}

	TernTreeNode<T>* node = new TernTreeNode<T>(h);
	node->left = createTree<T>(h - 1);
	node->middle = createTree<T>(h - 1);
	node->right = createTree<T>(h - 1);
}
int main()
{
	TernTreeNode<unsigned int>* result = createTree<unsigned int>(3);
    return 0;
}

