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
        int iA = m - 1;
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
    }
};