#include "NowCoder.h"
#include <functional>
//ʱ��:O(n)    �ռ�:O(n)

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
	/**
	 *
	 * @param root TreeNode�� the root of binary tree
	 * @return int����vector<vector<>>
	 */
	vector<vector<int> > threeOrders(TreeNode* root) {
		if (root != nullptr)
		{
			Preorder(root);
			Inorder(root);
			Postorder(root);
		}
		return { pre, mid, post };
	}
private:
	vector<int> pre, mid, post;
	//(VLR)
	void Preorder(TreeNode* node)
	{
		if (node == nullptr)
			return;
		pre.push_back(node->val);
		Preorder(node->left);
		Preorder(node->right);
	}
	//(LDR)
	void Inorder(TreeNode* node)
	{
		if (node == nullptr)
			return;
		Inorder(node->left);
		mid.push_back(node->val);
		Inorder(node->right);
	}
	//(LRD)
	void Postorder(TreeNode* node)
	{
		if (node == nullptr)
			return;
		Postorder(node->left);
		Postorder(node->right);
		post.push_back(node->val);
	}
};

/*
ǰ�򣺳ɹ�
���򣺳�ʱ
�������δ���
*/
#ifdef Morris
// ������ת���·���ϵ����н��
static void visit_reverse(TreeNode* from, TreeNode* to, std::function< void(const TreeNode*) >& visit) {
	TreeNode* p = to;
	reverse(from, to);
	while (true) {
		visit(p);
		if (p == from)
			break;
		p = p->right;
	}
	reverse(to, from);
};
//(VLR)
void Preorder(TreeNode* node)
{
	vector<int> pre;
	TreeNode* cur = node, * prev = nullptr;
	while (cur != nullptr)
	{
		if (cur->left == nullptr)
		{
			pre.push_back(cur->val);
			prev = cur; //cur �շ��ʹ�
			cur = cur->right;
		}
		else
		{
			//����ǰ��
			TreeNode* root = cur->left;
			while (root->right != nullptr && root->right != cur)
			{
				root = root->right;
			}

			if (root->right == nullptr)
			{
				//��û�н�������
				pre.push_back(cur->val); //�����к��и�������ͬ
				root->right = cur;
				prev = cur; //�շ��ʹ�
				cur = cur->left;
			}
			else
			{
				//����������ɾ������
				root->right = nullptr;
				/* prev = cur ��������䣬cur�Ѿ�������*/
				cur = cur->right;
			}
		}
	}
}
//(LDR)
void Inorder(TreeNode* node)
{
	vector<int> mid;
	TreeNode* cur = node, * prev = nullptr;
	while (cur != nullptr)
	{
		if (cur->left == nullptr)
		{
			mid.push_back(cur->val);
			prev = cur;
			cur = cur->right;
		}
		else
		{
			//����ǰ��
			TreeNode* root = cur->left;
			while (root->right != nullptr && root->right != cur)
			{
				root = root->left;
			}

			if (root->left == nullptr)
			{
				root->right = cur;
				/*  prev = cur ��������䣬cur��û�б����� */
				cur = cur->left;
			}
			else
			{
				//�Ѿ������������ʽڵ㣬��ɾ������
				mid.push_back(cur->val);
				root->right = nullptr;
				prev = cur;
				cur = cur->right;
			}
		}
	}
}
//(LRD)
void Postorder(TreeNode* node)
{
	vector<int> result;
	TreeNode dummy(-1);
	TreeNode* cur = node, * prev = nullptr;

	std::function <void(const TreeNode*)> visit = [&result](const TreeNode* root)
	{
		result.push_back(root->val);
	};

	dummy.left = node;
	cur = &dummy;
	while (cur != nullptr)
	{
		if (cur->left == nullptr)
		{
			prev = cur; //������
			cur = cur->right;
		}
		else
		{
			TreeNode* root = cur->left;
			while (root->right != nullptr && root->right != cur)
			{
				root = root->right;
			}

			if (root->right == nullptr)
			{
				//��û�н�����������������
				root->right = cur;
				prev = cur; //����Ҫ��
				cur = cur->left;
			}
			else
			{
				visit_reverse(cur->left, prev, visit);
				prev->right = nullptr;
				prev = cur; //����Ҫ��
				cur = cur->right;
			}
		}
	}
}

#endif