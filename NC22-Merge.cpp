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
            A[index--] = A[i] > B[j] ? A[i--] : B[j--]; //�������Ԫ��
        while (j >= 0)
            A[index--] = B[j--]; //A����Ԫ��ѭ��������ѭ��B����
        
        /*
        int *p = &A[m-1], *q = &B[n-1], *r = &A[m+n-1]; //�ϲ���A����
        while(m + n > 0)
        {
            if(m > 0 && n > 0)
            {
                if(*p > *q) //�Ƚ�A��B��������Ԫ��
                {
                    *r = *p; //A����Ԫ�ؽϴ�
                    --m; //A���鳤��
                    --r; 
                    --p; //A����Ԫ���±�
                }
                else
                {
                    *r = *q; //B����Ԫ�ؽϴ�
                    --n; //B���鳤��
                    --r; 
                    --q; //B����Ԫ���±�
                }
            }
            else
            {
                while(m--) //A����Ԫ�طǿ�
                {
                    *r = *p;
                    --r;
                    --p;
                }
                while(n--) //B����Ԫ�طǿ�
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