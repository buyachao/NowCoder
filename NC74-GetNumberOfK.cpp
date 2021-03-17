#include "NowCoder.h"

#ifdef KnowledgePoints
[NC74]数字在升序数组中出现的次数
时间:O(logn)    空间:O(1)
1、暴力求解
2、二分查找
3、库函数
#endif

class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        int lbound = 0, rbound = 0;
        //寻找上界
        int l = 0, r = data.size();
        while(l < r)
        {
            int mid = l + (r - l) / 2; //获取数组中间下标
            if(data[mid] < k)
            {
                l = mid + 1; //中间元素小于目标值，下标递增
            }
            else
            {
                r = mid; //中间元素大于等于目标值
            }
        }
        lbound = l;

        //寻找下界
        l = 0, r = data.size();
        while(l < r)
        {
            int mid = l + (r - l) / 2; //获取数组中间下标
            if(data[mid] <= k)
            {
                l = mid + 1; //中间元素小于目标值，下标递增
            }
            else
            {
                r = mid; //中间元素大于等于目标值
            }
        }
        rbound = l;

        return rbound - lbound;
        
        //return upper_bound(data.begin(), data.end(), k) - lower_bound(data.begin(), data.end(), k);
    }
};