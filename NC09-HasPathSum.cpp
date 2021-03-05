#include "NowCoder.h"

#ifdef KonwledgePoints
[NC9]���������Ƿ���ڽڵ��Ϊָ��ֵ��·��
1��DFS��������㷨
2���������������
#endif 

class Solution
{
public:
	bool HasPathSum(NCtreeNode* root, int sum) {
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
	NCtree n;
	Solution s;
	int nums[] = {1,2,4,6,8};
	int len = n.GetArrLength(nums);

	NCtreeNode* root = n.InitTree(nums, len);
	cout << boolalpha << s.HasPathSum(root, 0) << endl;
	system("pause");
	return 0;
}
#endif