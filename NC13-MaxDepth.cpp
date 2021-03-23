#include "NowCoder.h"

#ifdef KnowledgePoints
[NC13]��������������
ʱ��:O(n)    �ռ�:O(logn)
1���ݹ�˼·����¼���ڵ㵽��ԶҶ�ӽڵ������
2������˼·��
#endif

class Solution {
public:
	int MaxDepth(NCtreeNode* root) {
		int iNCtreeLen = 0;
		iNCtreeLen = PostOrder(root);
		return iNCtreeLen;
		//return max(PostOrder(root->left), PostOrder(root->right)) + 1; //��������
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

	int nums[] = { 1, 2, 3, 4, NULL, NULL, 5 }; //��Ҫ���սڵ���Ϊ<NULL>
	int iSize = n.GetArrLength(nums);
	NCtreeNode* root = n.InitTree(nums, iSize);
	cout << "������: ";
	n.LevelOrder(root);
	cout << "��������������: " << s.MaxDepth(root) << endl;

	system("pause");
	return 0;
}
#endif