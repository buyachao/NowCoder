#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#ifdef knowledgePoint
[NC9]二叉树中是否存在节点和为指定值的路径
1、DFS广度优先算法
2、二叉树先序遍历
#endif 

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	template<class T>
	int length(T& arr)
	{
		return sizeof(arr) / sizeof(arr[0]);
		//return end(arr) - begin(arr);
	}

	TreeNode* InitTree(int arr[], int size)
	{
		if (size < 1)
		{
			return NULL;
		}

		TreeNode** nodes = new TreeNode * [size];
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == 0)
			{
				nodes[i] = NULL;
			}
			else
			{
				nodes[i] = new TreeNode(arr[i]);
			}
		}

		queue<TreeNode*> nodeQueue;
		nodeQueue.push(nodes[0]);

		TreeNode* node;
		int index = 1;
		while (index < size)
		{
			node = nodeQueue.front();
			nodeQueue.pop();
			nodeQueue.push(nodes[index++]);
			node->left = nodeQueue.back();
			nodeQueue.push(nodes[index++]);
			node->right = nodeQueue.back();
		}
		return nodes[0];
	}
	bool HasPathSum(TreeNode* root, int sum) {
		if (!root)
			return false;
		else if (!root->left && !root->right && root->val == sum)
			return true;
		else
			return HasPathSum(root->left, sum - root->val) || HasPathSum(root->right, sum - root->val);
	}
};
#ifdef main
int main()
{
	Solution s;
	int nums[] = {1,2,4,6,8};
	int len = s.length(nums);

	TreeNode* root = s.InitTree(nums, len);
	cout << boolalpha << s.HasPathSum(root, 0) << endl;
	system("pause");
	return 0;
}
#endif