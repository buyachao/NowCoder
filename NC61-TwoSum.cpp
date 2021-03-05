#include <unordered_map>
#include <random>
#include "NowCoder.h"

#ifdef KnowledgePoints
[NC61]����֮��
1��������ⷨ��ʹ��˫��ѭ��������ָ��ֱ�ָ������������Ȼ������б��Ƿ����Ŀ��ֵ��
2����ϣ�����жϹ�ϣ����(target - x)�Ƿ���ڣ���������(x)�Ͷ�Ӧ�±�(i)�����ϣ��
//unorder_map �� map �ڲ�ʵ�ֻ���ͬ
map���ڲ�ʵ����һ���������������Ƿ��ϸ�ƽ���������������AVL���ϸ�ƽ�������������������������Զ�����Ĺ��ܣ����map�ڲ�������Ԫ�ض�������ģ��������ÿһ���ڵ㶼������map��һ��Ԫ�ء���ˣ�����map���еĲ��ң�ɾ������ӵ�һϵ�еĲ������൱���ǶԺ�������еĲ�����map�е�Ԫ���ǰ��ն���������������������������������������ص���������������нڵ�ļ�ֵ��С�ڸ��ڵ�ļ�ֵ�����������нڵ�ļ�ֵ�����ڸ��ڵ�ļ�ֵ���洢�ģ�ʹ�á�����������ɽ���ֵ���մ�С�������������
unordered_map���ڲ�ʵ����һ����ϣ��Ҳ��ɢ�б�ͨ���ѹؼ���ֵӳ�䵽Hash����һ��λ�������ʼ�¼�����ҵ�ʱ�临�ӶȿɴﵽO(1)�����ں������ݴ��������Ź㷺Ӧ�ã�����ˣ���Ԫ�ص�����˳��������ġ���ϣ����ϸ����

//map��ȱ�㣺
map�ŵ㣺1�������ԣ�����map�ṹ�����ŵ㣬��Ԫ�ص��������ںܶ�Ӧ���ж���򻯺ܶ�Ĳ�����2����������ڲ�ʵ��һ�������ʹ��map�ĺܶ������lgn��ʱ�临�Ӷ��¾Ϳ���ʵ�֣����Ч�ʷǳ��ĸߡ�
mapȱ�㣺�ռ�ռ���ʸߣ���Ϊmap�ڲ�ʵ���˺��������Ȼ���������Ч�ʣ�������Ϊÿһ���ڵ㶼��Ҫ���Ᵽ�游�ڵ㡢���ӽڵ�ͺ� / �����ʣ�ʹ��ÿһ���ڵ㶼ռ�ô����Ŀռ䡣
���ô���������Щ��˳��Ҫ������⣬��map�����ЧһЩ��

//unordered_map��ȱ�㣺
unordered_map�ŵ㣺��Ϊ�ڲ�ʵ���˹�ϣ�����������ٶȷǳ��Ŀ�
unordered_mapȱ�㣺��ϣ��Ľ����ȽϺķ�ʱ��
���ô� : ���ڲ������⣬unordered_map����Ӹ�ЧһЩ����������������⣬���ῼ��һ����unordered_map

//�ܽ�:
1���ڴ�ռ���ʵ������ת���ɺ���� VS hash��, ����unorder_mapռ�õ��ڴ�Ҫ�ߣ�����unordered_mapִ��Ч��Ҫ��map�ߺܶࡣ
2������unordered_map��unordered_set�����������˳���봴��������ʱ�����˳��һ����ͬ����Ϊ�����ǰ��չ�ϣ���ǰ�������α�����
3��map��unordered_map��ʹ�ã�unordered_map���÷���map��һ���ģ��ṩ�� insert��size��count�Ȳ��������������Ԫ��Ҳ����pair�����������ġ���ײ�ʵ������ȫ��ͬ�ģ��Ϸ��Ѿ������ˣ����Ǿ��ⲿʹ����˵ȴ��һ�µġ�
#endif

class Solution
{
public:
	vector<int> TwoSum(vector<int>& nums, int target)
	{
		int iSize = nums.size();
		vector<int> result;
		//1��������ⷨ
		/*for (int i = 0; i < iSize; i++)
		{
			for (int j = i + 1; j < iSize - 1; j++)
			{
				if (nums[i] + nums[j] == target)
				{
					result.push_back(i + 1);
					result.push_back(j + 1);
				}
			}
		}
		return result;*/

		//2����ϣ��
		unordered_map<int, int> map;
		for (int i = 0; i < iSize; i++)
		{
			auto it = map.find(target - nums[i]);
			if (it != map.end())
			{
				result.push_back(it->second + 1);
				result.push_back(i + 1);
			}
			map[nums[i]] = i;
		}
		return result;
	}
};

#ifdef main
int main(int argc, char* argv[])
{
	Solution s;
	vector<int> nums;
	vector<int> result;
	//���ݳ�ʼ��
	int arr[] = { 3, 2, 4 };
	for (int i = 0; i < GetSize(arr); i++)
	{
		nums.push_back(arr[i]);
	}

	//����֮��
	result = s.TwoSum(nums, 6);
	if (result.size() == 0 || result.empty() == true)
	{
		cout << "Element not found" << endl;
	}
	else
	{
		cout << "[" << result[0] << ", " << result[1] << "]" << endl;
	}

	system("pause");
	return 0;
}
#endif