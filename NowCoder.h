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
	void LevelOrder(TreeNode* root);	/*�����������������*/
	void PreOrder(TreeNode* root);		/*������ǰ���������*/
};