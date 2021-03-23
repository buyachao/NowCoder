#include "NowCoder.h"

#ifdef KonwledgePoints
[NC11]��������ת��Ϊ����ƽ����
ʱ��:O(n)    �ռ�:O(logn)
1��ƽ���������Balanced Binary Tree���ֱ���ΪAVL�����б���AVL�㷨�����Ҿ����������ʣ�����һ�ÿ����������������������ĸ߶Ȳ�ľ���ֵ������1����������������������һ��ƽ�����������������ܺõĽ���˶���������˻�����������⣬�Ѳ��룬���ң�ɾ����ʱ�临�Ӷ���������������ά����O(logN)������Ƶ����ת��ʹ�����ɾ��������O(logN)���ҵ�ʱ�䣬������Զ����������˵��ʱ�����ȶ��˺ܶࡣ
2��������������Binary Search Tree���ֱ���Ϊ��������������������������������һ�ÿ����������Ǿ����������ʵĶ������� ���������������գ��������������н���ֵ��С�����ĸ�����ֵ�� ���������������գ��������������н���ֵ���������ĸ�����ֵ��
#endif 

class Solution {
public:
	NCtreeNode* SortedArrayToBST(vector<int>& num) {
		int iSize = num.size();
		if (iSize == 0)
		{
			return NULL;
		}
		return bst(num, 0, iSize - 1);
	}
private:
	NCtreeNode* bst(vector<int>& num, int begin, int end)
	{
		if (begin > end)
			return NULL;

		int iMid = (begin + end + 1) / 2;
		NCtreeNode* root = new NCtreeNode(num[iMid]);
		root->left = bst(num, begin, iMid - 1); //�ݹ鹹��������
		root->right = bst(num, iMid + 1, end); //�ݹ鹹��������
		return root;
	}
};

#ifdef main
int main(int argc, char* argv[])
{
	NCtree n;
	Solution s;
	vector<int> num = { -1,0,1,2 };
	NCtreeNode* root = s.SortedArrayToBST(num);
	n.LevelOrder(root);

	system("pause");
	return 0;
}
#endif