#include "NowCoder.h"

#ifdef KnowledgePoints
[NC78]��ת����
ʱ��:O(n)    �ռ�:O(1)
ͨ����������ָ��ﵽ��ת����
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
		NClistNode* pre = nullptr; //preָ��ָ���Ѿ���ת�õ���������һ���ڵ㣬�ʼû�з�ת������ָ��nullptr
		NClistNode* cur = pHead; //curָ��ָ�����ת����ĵ�һ���ڵ㣬�ʼ��һ���ڵ����ת������ָ��head
		NClistNode* nex = nullptr; //nexָ��ָ�����ת����ĵڶ����ڵ㣬Ŀ���Ǳ���������Ϊcur�ı�ָ��󣬺����������ʧЧ�ˣ�������Ҫ����

		//����Ϊ�գ�curΪnullptr�����Է���pre����Ϊ��ת���ͷ���
		while (cur)
		{
			nex = cur->next; //�������ת������һ���ڵ�
			cur->next = pre; //δ��ת����ĵ�һ���ڵ���¸�ָ��ָ���ѷ�ת��������һ���ڵ�
			pre = cur; //ָ�����
			cur = nex; //������һ��δ��ת����ĵ�һ���ڵ�
		}
		return pre;
	}
};