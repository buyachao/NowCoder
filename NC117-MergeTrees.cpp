#include "NowCoder.h"

#ifdef KnowledgePoints
[NC117]合并二叉树
时间:O(n)    空间:O(n)

//1、递归前序遍历
//2、迭代
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
     * @param t1 NCtreeNode类
     * @param t2 NCtreeNode类
     * @return NCtreeNode类
     */
    NCtreeNode* mergeTrees(NCtreeNode* t1, NCtreeNode* t2) {
        //参数非空判断
        if (t1 == nullptr && t2 == nullptr)
        {
            return nullptr;
        }
        if (t1 == nullptr)
        {
            return t2; //如果t1为空，合并后为t2
        }
        if (t2 == nullptr)
        {
            return t1; //如果t2为空，合并后为t1
        }
        else
        {
            //前序遍历
            t1->val += t2->val; //节点值合并
            t1->left = mergeTrees(t1->left, t2->left); //递归左子树
            t1->right = mergeTrees(t1->right, t2->right); //递归右边子树
        }

        //2、迭代
        /*
        if (t1 == NULL) return t2;
        if (t2 == NULL) return t1;
        queue<NCtreeNode*> que;
        que.push(t1);
        que.push(t2);

        while (!que.empty()) 
        {
            NCtreeNode* n1 = que.front(); //指向队列头
            que.pop();
            NCtreeNode* n2 = que.front();
            que.pop();
            n1->val += n2->val;

            //如果两棵树的左子树都不为空，加入队列
            if (t1->left != nullptr && t2->left != nullptr) 
            {
                que.push(t1->left);
                que.push(t2->left);
            }

            //如果两棵树的右子树都不为空，加入队列
            if(t1->right != nullptr && t2->right != nullptr)
            {
                que.push(t1->right);
                que.push(t2->right);
            }

            //如果t1左节点为空，t2的非空
            if(t1->left == nullptr && t2->left != nullptr)
            {
                t1->left = t2->left;
            }

            //如果t1右节点为空，t2的非空
            if (t1->right == nullptr && t2->right != nullptr)
            {
                t1->right = t2->right;
            }
        }
        return t1;
        */
    }
};