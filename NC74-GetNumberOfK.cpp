#include "NowCoder.h"

#ifdef KnowledgePoints
[NC74]���������������г��ֵĴ���
ʱ��:O(logn)    �ռ�:O(1)
1���������
2�����ֲ���
3���⺯��
#endif

class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        int lbound = 0, rbound = 0;
        //Ѱ���Ͻ�
        int l = 0, r = data.size();
        while(l < r)
        {
            int mid = l + (r - l) / 2; //��ȡ�����м��±�
            if(data[mid] < k)
            {
                l = mid + 1; //�м�Ԫ��С��Ŀ��ֵ���±����
            }
            else
            {
                r = mid; //�м�Ԫ�ش��ڵ���Ŀ��ֵ
            }
        }
        lbound = l;

        //Ѱ���½�
        l = 0, r = data.size();
        while(l < r)
        {
            int mid = l + (r - l) / 2; //��ȡ�����м��±�
            if(data[mid] <= k)
            {
                l = mid + 1; //�м�Ԫ��С��Ŀ��ֵ���±����
            }
            else
            {
                r = mid; //�м�Ԫ�ش��ڵ���Ŀ��ֵ
            }
        }
        rbound = l;

        return rbound - lbound;
        
        //return upper_bound(data.begin(), data.end(), k) - lower_bound(data.begin(), data.end(), k);
    }
};