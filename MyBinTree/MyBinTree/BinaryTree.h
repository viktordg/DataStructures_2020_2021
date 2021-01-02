#pragma once
#include<string.h>
#include<iostream>
class BinaryTree
{
private:
	struct TreeNode
	{
		int data;
		TreeNode* left;
		TreeNode* right;

		TreeNode(int data, TreeNode* left = nullptr, TreeNode* right = nullptr)
		{
			this->data = data;
			this->left = left;
			this->right = right;
		}
	};

	TreeNode* root;

	TreeNode* copy(TreeNode* otherRoot)
	{
		if (otherRoot == nullptr)
		{
			return nullptr;
		}

		TreeNode* copyRoot = new TreeNode(otherRoot->data);
		copyRoot->left = this->copy(otherRoot->left);
		copyRoot->right = this->copy(otherRoot->right);
		return copyRoot;
	}
	void clear(TreeNode* &treeRoot)
	{
		if (treeRoot = nullptr)
		{
			return;
		}
		this->clear(treeRoot->left);
		this->clear(treeRoot->right);
		delete treeRoot;
	}
	int get_countHelp(TreeNode* treeRoot) const
	{
		if (treeRoot == nullptr)
		{
			return 0;
		}
		return 1 + get_countHelp(treeRoot->left) + get_countHelp(treeRoot->right);
	}
public:
	BinaryTree();
	BinaryTree(const BinaryTree& other);
	BinaryTree& operator=(const BinaryTree& other);
	~BinaryTree();

	void add_Element(int data, const std::string &path);
	int get_rootData();
	int get_count() const;
	bool isEmpty() const;
};

