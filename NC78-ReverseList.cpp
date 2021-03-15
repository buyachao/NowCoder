#include "NowCoder.h"

#ifdef KnowledgePoints
[NC78]反转链表
时间:O(n)    空间:O(1)
通过调整链表指针达到反转链表
#endif

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {
	}
};*/


class Solution {
public:	
	NClistNode* ReverseList(NClistNode* pHead) {
		NClistNode* pre = nullptr; //pre指针指向已经反转好的链表的最后一个节点，最开始没有反转，所以指向nullptr
		NClistNode* cur = pHead; //cur指针指向待反转链表的第一个节点，最开始第一个节点待反转，所以指向head
		NClistNode* nex = nullptr; //nex指针指向待反转链表的第二个节点，目的是保存链表，因为cur改变指向后，后面的链表则失效了，所以需要保存

		//链表不为空，cur为nullptr，所以返回pre，即为反转后的头结点
		while (cur)
		{
			nex = cur->next; //保存待反转链表下一个节点
			cur->next = pre; //未反转链表的第一个节点的下个指针指向已反转链表的最后一个节点
			pre = cur; //指针后移
			cur = nex; //操作下一个未反转链表的第一个节点
		}
		return pre;
	}
};