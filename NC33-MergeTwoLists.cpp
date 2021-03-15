#include "NowCoder.h"

#ifdef KnowledgePoints
[NC33]合并有序链表
时间 : O(n)    空间 : O(1)
通过调整链表指针达到反转链表
#endif

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

    class Solution {
    public:
        /**
         *
         * @param l1 NClistNode类
         * @param l2 NClistNode类
         * @return NClistNode类
         */
        NClistNode* MergeTwoLists(NClistNode* l1, NClistNode* l2) {
            if (l1 == NULL && l2 == NULL)
            {
                return NULL;
            }
            else if (l1 == NULL && l2 != NULL)
            {
                return l2; //链表l1为空，直接返回l2
            }
            else if (l1 != NULL && l2 == NULL)
            {
                return l1; //链表l2为空，直接返回l1
            }
            else
            {
                NClistNode* head = (l1->val <= l2->val) ? l1 : l2; //头节点指向较小的位置
                NClistNode* tail = head; //首位指针初始化
                l1 = (head == l1) ? l1->next : l1; //初始化l1下一节点
                l2 = (head == l2) ? l2->next : l2; //初始化l2下一节点
                while (l1 != NULL && l2 != NULL)
                {
                    if (l1->val <= l2->val) //排序
                    {
                        tail->next = l1; //获取新链表下一节点
                        l1 = l1->next;
                    }
                    else
                    {
                        tail->next = l2; //获取新链表下一节点
                        l2 = l2->next;
                    }
                    tail = tail->next; //更新尾结点
                }
                tail->next = (l1 == NULL) ? l2 : l1;
                return head;
            }
        }
};