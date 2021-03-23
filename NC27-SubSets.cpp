#include <vector>
#include <algorithm>
using namespace std;

#ifdef KnowledgePoints
[NC27]集合的所有子集
时间:O(2^n)	    空间:O(n)
//回溯法(递归)
#endif

class Solution {
public:
	void dfs(const vector<int>& nums, /*原数组*/
		vector<vector<int>>& res,     /*子集集合*/
		vector<int>& sub,             /*子集*/
		size_t len,                   /*数组长度*/
		size_t idx)                   /*索引*/
	{
		//子集集合
		if (len == 0) 
		{
			res.push_back(sub); /*各个子集，从空集开始*/
			return;
		}

		//子集
		for (size_t i = idx; i < nums.size(); ++i) 
		{
			sub.push_back(nums[i]);
			dfs(nums, res, sub, len - 1, i + 1); //子集递归
			sub.pop_back();
		}
	}
	vector<vector<int> > subsets(vector<int>& S) {
		vector<vector<int>> res;
		vector<int> sub;
		for (size_t i = 0; i <= S.size(); ++i) 
		{
			dfs(S, res, sub, i, 0);
		}

		return res;
	}
};