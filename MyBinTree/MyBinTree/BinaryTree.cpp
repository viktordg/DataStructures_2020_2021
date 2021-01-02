#include "stdafx.h"
#include "BinaryTree.h"


BinaryTree::BinaryTree()
{
	this->root = nullptr;
}
BinaryTree::BinaryTree(const BinaryTree& other)
{
	this->root = this->copy(other.root);
}
BinaryTree& BinaryTree::operator=(const BinaryTree& other)
{
	if (this != &other)
	{
		this->clear(this->root);
		this->root = this->copy(other.root);
	}
	return *this;
}
BinaryTree::~BinaryTree()
{
	this->clear(this->root);
}

void BinaryTree::add_Element(int data, const std::string &path)
{
	if (this->root == nullptr)
	{
		this->root = new TreeNode(data);
		return;
	}

	TreeNode* currentRoot = root;

	for (size_t i = 0; i < path.size() - 1; i++)
	{
		if (path[i] == 'L')
		{
			currentRoot = currentRoot->left;
		}
		else if(path[i] == 'R')
		{
			currentRoot = currentRoot->right;
		}

		if (currentRoot == nullptr)
		{
			return;
		}
	}

	if (path[path.size()] == 'L')
	{
		currentRoot->left = new TreeNode(data);
	}
	else if (path[path.size()] == 'R')
	{
		currentRoot->right = new TreeNode(data);
	}
}
int BinaryTree::get_rootData()
{
	if (this->root == nullptr)
	{
		throw new std::invalid_argument("Root empty.");
	}
	return this->root->data;
}
int BinaryTree::get_count() const
{
	return this->get_countHelp(this->root);
}
bool BinaryTree::isEmpty() const
{
	return this->root == nullptr;
}

