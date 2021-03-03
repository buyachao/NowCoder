#pragma once
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class NowCoder {
public:
	void LevelOrder(TreeNode* root);	/*二叉树层序遍历声明*/
	void PreOrder(TreeNode* root);		/*二叉树前序遍历声明*/
};