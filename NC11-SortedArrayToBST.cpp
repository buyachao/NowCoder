#include <vector>
#include "NowCoder.h" //将类声明头文件包含进来

#ifdef knowledgePoint
[NC11]有序数组转化为二叉平衡树
1、平衡二叉树（Balanced Binary Tree）又被称为AVL树（有别于AVL算法），且具有以下性质：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。这个方案很好的解决了二叉查找树退化成链表的问题，把插入，查找，删除的时间复杂度最好情况和最坏情况都维持在O(logN)。但是频繁旋转会使插入和删除牺牲掉O(logN)左右的时间，不过相对二叉查找树来说，时间上稳定了很多。
2、二叉搜索树（Binary Search Tree）又被称为二叉搜索树（二叉排序树）它或者是一棵空树，或者是具有下列性质的二叉树： 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值。
#endif 

class Solution {
public:
	TreeNode* SortedArrayToBST(vector<int>& num) {
		int iSize = num.size();
		if (iSize == 0)
		{
			return NULL;
		}
		return bst(num, 0, iSize - 1);
	}
private:
	TreeNode* bst(vector<int>& num, int begin, int end)
	{
		if (begin > end)
			return NULL;

		int iMid = (begin + end + 1) / 2;
		TreeNode* root = new TreeNode(num[iMid]);
		root->left = bst(num, begin, iMid - 1); //递归构造左子树
		root->right = bst(num, iMid + 1, end); //递归构造右子树
		return root;
	}
};

#ifdef main
int main(int argc, char* argv[])
{
	NowCoder n;
	Solution s;
	vector<int> num = { -1,0,1,2 };
	TreeNode* root = s.SortedArrayToBST(num);
	n.LevelOrder(root);

	system("pause");
	return 0;
}
#endif