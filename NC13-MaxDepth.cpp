#include "NowCoder.h"

#ifdef KnowledgePoints
[NC13]二叉树的最大深度
时间:O(n)    空间:O(logn)
1、递归思路，记录根节点到最远叶子节点的数量
2、队列思路，
#endif

class Solution {
public:
	int MaxDepth(NCtreeNode* root) {
		int iNCtreeLen = 0;
		iNCtreeLen = PostOrder(root);
		return iNCtreeLen;
		//return max(PostOrder(root->left), PostOrder(root->right)) + 1; //后续遍历
	}
private:
	int PostOrder(NCtreeNode* root)
	{
		if (!root)
		{
			return 0;
		}

		int left = 1 + PostOrder(root->left);
		int right = 1 + PostOrder(root->right);
		return left > right ? left : right;
	}
};

#ifdef main
int main(int argc, char* argv[])
{
	NCtree n;
	Solution s;

	int nums[] = { 1, 2, 3, 4, NULL, NULL, 5 }; //需要将空节点置为<NULL>
	int iSize = n.GetArrLength(nums);
	NCtreeNode* root = n.InitTree(nums, iSize);
	cout << "二叉树: ";
	n.LevelOrder(root);
	cout << "二叉树的最大深度: " << s.MaxDepth(root) << endl;

	system("pause");
	return 0;
}
#endif