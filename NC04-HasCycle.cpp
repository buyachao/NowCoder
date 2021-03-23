#include "NowCoder.h"

#ifdef KonwledgePoints
[NC04]判断链表中是否有环
时间:O(n)    空间:O(1)
1、快慢指针
2、每一次快指针走两步，慢指针走一步，所以进行一次操作以后，快慢指针之间的距离是t - 1，再操作一次是t - 2、t - 3...直到操作t次以后，快慢指针之间的距离为0，即两个指针相遇。
3、有环的链表会有一个节点指向链表中以存在的节点，链表如果没有环的话，我们顺着链表的节点一直走下去，一定会遇到空节点。但是如果有环的话，我们一直顺着链表的节点走下去，就会造成死循环。
#endif 

class Solution {
public:
	bool HasCycle(NClistNode* head) {
		NClistNode* fast = head; //快指针
		NClistNode* slow = head; //慢指针
		while (slow != NULL && fast->next != NULL && fast->next->next != NULL)
		{
			fast = fast->next->next; //两步
			slow = slow->next; //一步
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