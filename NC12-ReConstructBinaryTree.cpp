#include "NowCoder.h"

#ifdef KonwledgePoints
[NC12]重建二叉树
1、已知前序和中序遍历，可以确定一棵二叉树。已知中序和后序遍历，可以确定一棵二叉树。但是，已知前序和后序遍历，不能确定一棵二叉树。
2、(pre_left + (i - vin_left)) 原二叉树左子树范围(右边界)
3、(pre_left + (i - vin_left)) + 1 原二叉树的右子树范围(左边界)
#endif

class Solution
{
public:
	NCtreeNode* ReConstructBinaryTree(vector<int> pre, vector<int> vin) {
		return rebuild(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}
private:
	NCtreeNode* rebuild(vector<int>& pre, int pre_left, int pre_right, vector<int>& vin, int vin_left, int vin_right)
	{
		NCtreeNode* root = new NCtreeNode(pre[pre_left]); //获取节点值
		root->left = NULL;
		root->right = NULL;

		//记录中序遍历中等于前序遍历的第一位的下标
		int vin_FirstMatch = 0;
		for (vin_FirstMatch = vin_left; vin_FirstMatch < vin_right; vin_FirstMatch++) {
			if (vin[vin_FirstMatch] == pre[pre_left]) {
				break;
			}
		}
		//左子树的深度
		int lTreeLength = vin_FirstMatch - vin_left;
		//右子数的深度
		int rTreeLength = vin_right - vin_FirstMatch;

		if (lTreeLength > 0)
		{
			root->left = rebuild(pre, pre_left + 1, pre_left + lTreeLength, vin, vin_left, vin_FirstMatch - 1);
		}
		if (rTreeLength > 0)
		{
			root->right = rebuild(pre, pre_left + lTreeLength + 1, pre_right, vin, vin_FirstMatch + 1, vin_right);
		}

		return root;
	}
};

#ifdef main
int main(int argc, char* argv[])
{
	NCtree n;
	Solution s;
	vector<int> pre = { 1,2,3,4,5,6,7 };
	vector<int> vin = { 3,2,4,1,6,5,7 };
	NCtreeNode* root = s.ReConstructBinaryTree(pre, vin);
	n.LevelOrder(root);
	
	system("pause");
	return 0;
}
#endif