#include <vector>
#include <algorithm>
using namespace std;

#ifdef KnowledgePoints
[NC27]���ϵ������Ӽ�
ʱ��:O(2^n)	    �ռ�:O(n)
//���ݷ�(�ݹ�)
#endif

class Solution {
public:
	void dfs(const vector<int>& nums, /*ԭ����*/
		vector<vector<int>>& res,     /*�Ӽ�����*/
		vector<int>& sub,             /*�Ӽ�*/
		size_t len,                   /*���鳤��*/
		size_t idx)                   /*����*/
	{
		//�Ӽ�����
		if (len == 0) 
		{
			res.push_back(sub); /*�����Ӽ����ӿռ���ʼ*/
			return;
		}

		//�Ӽ�
		for (size_t i = idx; i < nums.size(); ++i) 
		{
			sub.push_back(nums[i]);
			dfs(nums, res, sub, len - 1, i + 1); //�Ӽ��ݹ�
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