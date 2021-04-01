#include "NowCoder.h"

#ifdef KnowledgePoints
[NC117]�ϲ�������
ʱ��:O(n)    �ռ�:O(n)

//1���ݹ�ǰ�����
//2������
#endif

/**
 * struct NCtreeNode {
 *	int val;
 *	struct NCtreeNode *left;
 *	struct NCtreeNode *right;
 * };
 */

class Solution {
public:
    /**
     *
     * @param t1 NCtreeNode��
     * @param t2 NCtreeNode��
     * @return NCtreeNode��
     */
    NCtreeNode* mergeTrees(NCtreeNode* t1, NCtreeNode* t2) {
        //�����ǿ��ж�
        if (t1 == nullptr && t2 == nullptr)
        {
            return nullptr;
        }
        if (t1 == nullptr)
        {
            return t2; //���t1Ϊ�գ��ϲ���Ϊt2
        }
        if (t2 == nullptr)
        {
            return t1; //���t2Ϊ�գ��ϲ���Ϊt1
        }
        else
        {
            //ǰ�����
            t1->val += t2->val; //�ڵ�ֵ�ϲ�
            t1->left = mergeTrees(t1->left, t2->left); //�ݹ�������
            t1->right = mergeTrees(t1->right, t2->right); //�ݹ��ұ�����
        }

        //2������
        /*
        if (t1 == NULL) return t2;
        if (t2 == NULL) return t1;
        queue<NCtreeNode*> que;
        que.push(t1);
        que.push(t2);

        while (!que.empty()) 
        {
            NCtreeNode* n1 = que.front(); //ָ�����ͷ
            que.pop();
            NCtreeNode* n2 = que.front();
            que.pop();
            n1->val += n2->val;

            //���������������������Ϊ�գ��������
            if (t1->left != nullptr && t2->left != nullptr) 
            {
                que.push(t1->left);
                que.push(t2->left);
            }

            //���������������������Ϊ�գ��������
            if(t1->right != nullptr && t2->right != nullptr)
            {
                que.push(t1->right);
                que.push(t2->right);
            }

            //���t1��ڵ�Ϊ�գ�t2�ķǿ�
            if(t1->left == nullptr && t2->left != nullptr)
            {
                t1->left = t2->left;
            }

            //���t1�ҽڵ�Ϊ�գ�t2�ķǿ�
            if (t1->right == nullptr && t2->right != nullptr)
            {
                t1->right = t2->right;
            }
        }
        return t1;
        */
    }
};