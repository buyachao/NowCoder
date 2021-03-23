#ifdef KnowledgePoints
[NC22]合并两个有序的数组
时间:O(m+n)    空间:O(1)
//归并排序的思想，只不过这里按照题目的意思不要申请额外的空间。
//把A后面剩余的空间当额外空间。
//这里和剑指offer上的面试题5，替换空格思想一样，从后面开始往前放就可以避免大量移动
//那后面从哪里开始呢？A长m，B长n，两个合并完之后必定长m+n，所在A的A[m+n-1]开始往前放
#endif

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        /*int iA = m - 1;
        int iB = n - 1;
        int iCur = m + n - 1;

        while (iA >= 0 && iB >= 0)
        {
            A[iCur--] = A[iA] > B[iB] ? A[iA--] : B[iB--];
        }

        while (iB >= 0)
        {
            A[iCur--] = B[iB]--;
        }
        */

        int i = m - 1, j = n - 1, index = m + n - 1;
        while (i >= 0 && j >= 0)
            A[index--] = A[i] > B[j] ? A[i--] : B[j--]; //倒序填充元素
        while (j >= 0)
            A[index--] = B[j--]; //A数组元素循环结束，循环B数组
        
        /*
        int *p = &A[m-1], *q = &B[n-1], *r = &A[m+n-1]; //合并至A数组
        while(m + n > 0)
        {
            if(m > 0 && n > 0)
            {
                if(*p > *q) //比较A和B两个数组元素
                {
                    *r = *p; //A数组元素较大
                    --m; //A数组长度
                    --r; 
                    --p; //A数组元素下标
                }
                else
                {
                    *r = *q; //B数组元素较大
                    --n; //B数组长度
                    --r; 
                    --q; //B数组元素下标
                }
            }
            else
            {
                while(m--) //A数组元素非空
                {
                    *r = *p;
                    --r;
                    --p;
                }
                while(n--) //B数组元素非空
                {
                    *r = *q;
                    --r;
                    --q;
                }
            }
        }
        */
    }
};