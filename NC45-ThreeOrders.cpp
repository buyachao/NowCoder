#include "NowCoder.h"
#include <functional>
//时间:O(n)    空间:O(n)

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
	 * @param root TreeNode类 the root of binary tree
	 * @return int整型vector<vector<>>
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
前序：成功
中序：超时
后续：段错误
*/
#ifdef Morris
// 访问逆转后的路径上的所有结点
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
			prev = cur; //cur 刚访问过
			cur = cur->right;
		}
		else
		{
			//查找前驱
			TreeNode* root = cur->left;
			while (root->right != nullptr && root->right != cur)
			{
				root = root->right;
			}

			if (root->right == nullptr)
			{
				//还没有建立索引
				pre.push_back(cur->val); //仅此行和中跟遍历不同
				root->right = cur;
				prev = cur; //刚访问过
				cur = cur->left;
			}
			else
			{
				//已线索化，删除线索
				root->right = nullptr;
				/* prev = cur 不能有这句，cur已经被访问*/
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
			//查找前驱
			TreeNode* root = cur->left;
			while (root->right != nullptr && root->right != cur)
			{
				root = root->left;
			}

			if (root->left == nullptr)
			{
				root->right = cur;
				/*  prev = cur 不能有这句，cur还没有被访问 */
				cur = cur->left;
			}
			else
			{
				//已经线索化，访问节点，并删除索引
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
			prev = cur; //必须有
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
				//还没有建立索引，则建立索引
				root->right = cur;
				prev = cur; //必须要有
				cur = cur->left;
			}
			else
			{
				visit_reverse(cur->left, prev, visit);
				prev->right = nullptr;
				prev = cur; //必须要有
				cur = cur->right;
			}
		}
	}
}

#endif