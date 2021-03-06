#include "stdafx.h"
#include<iostream>
#include<algorithm>

struct TreeNode {
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
//1. Височината му - Височина на дърво наричаме дължината(в брой върхове) на най - дългия път от корена до кое да е листо на дървото
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
//2. Нивото на което се намира даден възел от дървото
int findLevelHelper(TreeNode* &root, TreeNode* &goal, int level = 1)
{
	if (root == nullptr)
	{
		return 0;
	}

	if (root->data == goal->data)
	{
		return level;
	}

	int leftLevel = findLevelHelper(root->left, goal, level + 1);
	if (leftLevel != 0)
	{
		return leftLevel;
	}
	return findLevelHelper(root->right, goal, level + 1);
}
int findLevel(TreeNode* &root, TreeNode* &goal)
{
	return findLevelHelper(root, goal, 1);
}
//3. Сумата на всички възли
int findSum(TreeNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return root->data + findSum(root->left) + findSum(root->right);
}
//4. Броя на всички възли
int findCount(TreeNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return 1 + findCount(root->left) + findCount(root->right);
}
//5. Броя на всички вътрешни възли - Вътрешни възли наричаме възли, които не са листа
int findInternalNodesCount(TreeNode* &root)
{
	if (root == nullptr || (root->left == nullptr && root->right == nullptr))
	{
		return 0;
	}

	return 1 + findInternalNodesCount(root->left) + findInternalNodesCount(root->right);
}
//6.Всички възможни пътища
void printArray(int path[], int len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << path[i] << " ";
	}
	std::cout << std::endl;
}
void printHelp(TreeNode* root, int path[], int pathLen)
{
	if (root == nullptr)
	{
		return;
	}

	path[pathLen] = root->data;
	pathLen++;

	if (root->left == nullptr && root->right == nullptr)
	{
		printArray(path, pathLen);
	}
	else
	{
		printHelp(root->left, path, pathLen);
		printHelp(root->right, path, pathLen);
	}
}
void printAllPaths(TreeNode* root)
{
	int path[1000];
	printHelp(root, path, 0);
}
//7.Пътя от корена на дървото до даден възел
void printCertainHelp(TreeNode* root,int goal, int path[], int pathLen)
{
	if (root == nullptr)
	{
		return;
	}

	path[pathLen] = root->data;
	pathLen++;

	if (root->data == goal)
	{
		printArray(path, pathLen);
	}
	else
	{
		printCertainHelp(root->left, goal, path, pathLen);
		printCertainHelp(root->right, goal, path, pathLen);
	}
}
void printCertainPath(TreeNode* root, int goal)
{
	int path[1000];
	printCertainHelp(root, goal, path, 0);
}
//8.Сумата на най - дългия път
int main()
{
	TreeNode* root = new TreeNode(8);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(9);
	root->left->right = new TreeNode(6);
	root->left->right->left = new TreeNode(4);
	root->left->right->left->left = new TreeNode(10);
	root->left->right->right = new TreeNode(7);
	root->right = new TreeNode(2);
	root->right->right = new TreeNode(5);
	root->right->left = new TreeNode(7);

//   		8
//		   / \
//		 3     2
//		/ \   / \
//	   9   6 7   5
//		  / \
//		 4   7
//      /
//     10
//1. findHeight(root) -> 4
	std::cout << findHeight(root) << std::endl;
//2. findLevel(root, root->left->right, 1) -> 3
	std::cout << findLevel(root, root->left->right) << std::endl;
//3. findSum(root) -> 51
	std::cout << findSum(root) << std::endl;
//4. findCount(root) -> 9
	std::cout << findCount(root) << std::endl;
//5. findInternalNodesCount(root) -> 4
	std::cout << findInternalNodesCount(root) << std::endl;
//6. printAllPaths(root) -> 8 3 9
//                          8 3 6 4 10
//							8 3 6 7
//							8 2 1
//							8 2 5
	printAllPaths(root);
//7. findPath(root, 4) -> 8 3 6 4
	printCertainPath(root, 4);
//8. findLongestSum(root) -> 31
    return 0;
}

