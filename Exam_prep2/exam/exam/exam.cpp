#include "stdafx.h"
#include<iostream>
#include<cmath>
#include<algorithm>

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
void print(Node* &first)
{
	Node* current = first;
	while (current != nullptr)
	{
		std::cout << current->data << ' ';
		current = current->next;
	}
	std::cout << std::endl;
}
void swap(Node* first, int element)
{
	if (first == nullptr || first->next == nullptr || first->next->next == nullptr)
	{
		std::cout << "Cannot swap elements\n";
		return;
	}

	bool found = false;
	int temp;
	Node* current = first;

	while (current != nullptr)
	{
		if (current->data == element && current->prev->prev != nullptr)
		{
			found = true;
			temp = current->data;
			current->data = current->prev->prev->data;
			current->prev->prev->data = temp;
		}
		current = current->next;
	}

	if (!found)
	{
		std::cout << "Cannot swap elements\n";
	}
}

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
// 1. Нмира дължината на даден възел
int findHeight(TreeNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	int leftHeight = findHeight(root->left);
	int rightHeight = findHeight(root->right);

	return 1 + std::max(leftHeight, rightHeight);
}
// 2. Намира нивото на даден възел
int findLevel(TreeNode* &root, TreeNode* &nodeToFind, int level)
{
	if (root == nullptr)
	{
		return 0;
	}

	if (root == nodeToFind)
	{
		return level;
	}
	int leftLevel = findLevel(root->left, nodeToFind, level + 1);
	if (leftLevel != 0)
	{
		return leftLevel;
	}
	return findLevel(root->right, nodeToFind, level + 1);
}
// 3. Намира сумата на всички корени
int findSum(TreeNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return root->data + findSum(root->left) + findSum(root->right);
}
// 4. Намира броя на всички възли
int findCount(TreeNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return 1 + findCount(root->left) + findCount(root->right);
}
// 5. Намиране на броя на всички вътрешни възли
int findInternalNodesCount(TreeNode* root)
{
	if (root == nullptr || (root->left == nullptr && root->right == nullptr))
	{
		return 0;
	}

	return 1 + findInternalNodesCount(root->left) + findInternalNodesCount(root->right);
}
// 1. Всички възможни пътища
void printArrPath(int* paths, int count)
{
	for (size_t i = 0; i < count; i++)
	{
		for (int i = 0; i < count; i++)
		{
			std::cout << paths[i] << " ";
		}
		std::cout << "\n";
	}
}
void printAllPathsHelp(TreeNode* &root, int* paths, int count)
{
	if (root == nullptr)
	{
		return;
	}
	paths[count++] = root->data;

	if (root->left == nullptr && root->right == nullptr)
	{
		printArrPath(paths, count);
		return;
	}

	printAllPathsHelp(root->left, paths, count);
	printAllPathsHelp(root->right, paths, count);
}
void printAllPaths(TreeNode* &root)
{
	int path[1000];
	printAllPathsHelp(root, path, 0);
}
// 2. Пътя от корена на дървото до даден възел
bool pathFromRootToNode(TreeNode* &root, TreeNode* &node, int* arr, int index)
{
	if (root == nullptr)
	{
		return false;
	}

	arr[index++] = root->data;

	if (root == node)
	{
		printArrPath(arr, index);
		return true;
	}

	if (pathFromRootToNode(root->left, node, arr, index) ||
		pathFromRootToNode(root->right, node, arr, index))
	{
		return true;
	}
	return false;
}
bool findPath(TreeNode* &root, TreeNode* &node)
{
	int arr[1000];
	return pathFromRootToNode(root, node, arr, 0);
}
// Сумата на най-дългия път
void findSumHelp(TreeNode* &root, int sum, int length, int &maxSum, int &maxLength)
{
	if (root == nullptr)
	{
		if (length > maxLength)
		{
			maxLength = length;
		}
		else if (length == maxLength && sum > maxSum) 
		{
			maxSum = sum;
		}
		return;
	}

	sum += root->data;

	findSumHelp(root->left, sum, length + 1, maxSum, maxLength);
	findSumHelp(root->right, sum, length + 1, maxSum, maxLength);
}
int findLongestSum(TreeNode* &root)
{
	if (root == nullptr)
	{
		return 0;
	}

	int maxSum = INT_MIN, maxLength = 0;
	findSumHelp(root, 0, 1, maxSum, maxLength);
	return maxSum;
}
// Напишете функция, която изтрива елемент от двоично наредено дърво по подадена стойност.
void insert(TreeNode* &root, int data)
{
	if (root == nullptr)
	{
		root = new TreeNode(data);
		return;
	}

	if (data < root->data)
	{
		insert(root->left, data);
	}
	else
	{
		insert(root->right, data);
	}
}
int main()
{
	//-------------------DLL

	/*Node* first = nullptr;
	pushBack(first, 8);
	pushBack(first, 9);
	pushBack(first, 1);
	pushBack(first, 2);
	print(first);
	swap(first, 1);
	print(first);*/

	//-------------------trees

	TreeNode* root = new TreeNode(8);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(9);
	root->left->right = new TreeNode(6);
	root->left->right->left = new TreeNode(4);
	root->left->right->right = new TreeNode(7);
	root->right = new TreeNode(2);
	root->right->right = new TreeNode(5);
	root->right->left = new TreeNode(7);

	//      8
	//	  /   \
	//	 3     2
	//	/ \   / \
	// 9   6 7   5
	//	  / \
	//	 4   7

	//std::cout << findHeight(root) << "\n";
	//std::cout << findLevel(root, root->left->right, 1) << "\n";
	//std::cout << findSum(root) << "\n";
	//std::cout << findCount(root) << "\n";
	//std::cout << findInternalNodesCount(root) << "\n";

	TreeNode* root2 = new TreeNode(8);
	root2->left = new TreeNode(3);
	root2->left->left = new TreeNode(9);
	root2->left->right = new TreeNode(6);
	root2->left->right->left = new TreeNode(4);
	root2->left->right->left->left = new TreeNode(10);
	root2->left->right->right = new TreeNode(7);
	root2->right = new TreeNode(2);
	root2->right->right = new TreeNode(5);
	root2->right->left = new TreeNode(1);

	//			 8
	//			/ \
	//		  3     2
	//		 / \   / \
	//		9   6 1   5
	//		   / \
	//		  4   7
	//	     /
	//	    10

	//printAllPaths(root2);
	//findPath(root, root->left->right->right);
	//std::cout << findLongestSum(root) << "\n";


	TreeNode* root3 = nullptr;
	insert(root3, 10);
	insert(root3, 4);
	insert(root3, 2);
	insert(root3, 7);
	insert(root3, 6);
	insert(root3, 9);
	insert(root3, 15);
	insert(root3, 13);
	insert(root3, 18);
	insert(root3, 14);

	//root = removeByData(root, 4);

	//          10
	//	    /        \
	//     4         15
	//	  / \      /    \
	//	 2   7    13    18
	//		/ \
	//	   6   9

    return 0;
}

