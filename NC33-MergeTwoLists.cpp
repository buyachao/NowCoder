#include "NowCoder.h"

#ifdef KnowledgePoints
[NC33]�ϲ���������
ʱ�� : O(n)    �ռ� : O(1)
ͨ����������ָ��ﵽ��ת����
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
         * @param l1 NClistNode��
         * @param l2 NClistNode��
         * @return NClistNode��
         */
        NClistNode* MergeTwoLists(NClistNode* l1, NClistNode* l2) {
            if (l1 == NULL && l2 == NULL)
            {
                return NULL;
            }
            else if (l1 == NULL && l2 != NULL)
            {
                return l2; //����l1Ϊ�գ�ֱ�ӷ���l2
            }
            else if (l1 != NULL && l2 == NULL)
            {
                return l1; //����l2Ϊ�գ�ֱ�ӷ���l1
            }
            else
            {
                NClistNode* head = (l1->val <= l2->val) ? l1 : l2; //ͷ�ڵ�ָ���С��λ��
                NClistNode* tail = head; //��λָ���ʼ��
                l1 = (head == l1) ? l1->next : l1; //��ʼ��l1��һ�ڵ�
                l2 = (head == l2) ? l2->next : l2; //��ʼ��l2��һ�ڵ�
                while (l1 != NULL && l2 != NULL)
                {
                    if (l1->val <= l2->val) //����
                    {
                        tail->next = l1; //��ȡ��������һ�ڵ�
                        l1 = l1->next;
                    }
                    else
                    {
                        tail->next = l2; //��ȡ��������һ�ڵ�
                        l2 = l2->next;
                    }
                    tail = tail->next; //����β���
                }
                tail->next = (l1 == NULL) ? l2 : l1;
                return head;
            }
        }
};