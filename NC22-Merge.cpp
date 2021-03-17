#ifdef KnowledgePoints
[NC22]�ϲ��������������
ʱ��:O(m+n)    �ռ�:O(1)
//�鲢�����˼�룬ֻ�������ﰴ����Ŀ����˼��Ҫ�������Ŀռ䡣
//��A����ʣ��Ŀռ䵱����ռ䡣
//����ͽ�ָoffer�ϵ�������5���滻�ո�˼��һ�����Ӻ��濪ʼ��ǰ�žͿ��Ա�������ƶ�
//�Ǻ�������￪ʼ�أ�A��m��B��n�������ϲ���֮��ض���m+n������A��A[m+n-1]��ʼ��ǰ��
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