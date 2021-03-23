#include "NowCoder.h"

#ifdef KonwledgePoints
[NC04]�ж��������Ƿ��л�
ʱ��:O(n)    �ռ�:O(1)
1������ָ��
2��ÿһ�ο�ָ������������ָ����һ�������Խ���һ�β����Ժ󣬿���ָ��֮��ľ�����t - 1���ٲ���һ����t - 2��t - 3...ֱ������t���Ժ󣬿���ָ��֮��ľ���Ϊ0��������ָ��������
3���л����������һ���ڵ�ָ���������Դ��ڵĽڵ㣬�������û�л��Ļ�������˳������Ľڵ�һֱ����ȥ��һ���������սڵ㡣��������л��Ļ�������һֱ˳������Ľڵ�����ȥ���ͻ������ѭ����
#endif 

class Solution {
public:
	bool HasCycle(NClistNode* head) {
		NClistNode* fast = head; //��ָ��
		NClistNode* slow = head; //��ָ��
		while (slow != NULL && fast->next != NULL && fast->next->next != NULL)
		{
			fast = fast->next->next; //����
			slow = slow->next; //һ��
			if (fast == slow)
			{
				return true;
			}
		}
		return false;
	}
};

#ifdef main
int main()
{
	Solution s;
	NClinkList list;
	int nums[] = { 2, -1, 1, 2, 2 };
	int isize = GetSize(nums);
	NClistNode* node = NULL;
	list.Insert(node, isize, nums);
	cout << boolalpha << s.HasCycle(node) << endl;
	list.Show(node);
	list.Delete(node);

	system("pause");
	return 0;
}
#endif