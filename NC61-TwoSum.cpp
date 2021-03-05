#include <unordered_map>
#include <random>
#include "NowCoder.h"

#ifdef KnowledgePoints
[NC61]两数之和
1、暴力求解法，使用双重循环的两个指针分别指向两个加数，然后相加判别是否等于目标值。
2、哈希表法，判断哈希表中(target - x)是否存在，不存在则将(x)和对应下标(i)存入哈希表。
//unorder_map 和 map 内部实现机理不同
map：内部实现了一个红黑树（红黑树是非严格平衡二叉搜索树，而AVL是严格平衡二叉搜索树），红黑树具有自动排序的功能，因此map内部的所有元素都是有序的，红黑树的每一个节点都代表着map的一个元素。因此，对于map进行的查找，删除，添加等一系列的操作都相当于是对红黑树进行的操作。map中的元素是按照二叉搜索树（又名二叉查找树、二叉排序树，特点就是左子树上所有节点的键值都小于根节点的键值，右子树所有节点的键值都大于根节点的键值）存储的，使用“中序遍历”可将键值按照从小到大遍历出来。
unordered_map：内部实现了一个哈希表（也叫散列表，通过把关键码值映射到Hash表中一个位置来访问记录，查找的时间复杂度可达到O(1)，其在海量数据处理中有着广泛应用）。因此，其元素的排列顺序是无序的。哈希表详细介绍

//map优缺点：
map优点：1、有序性，这是map结构最大的优点，其元素的有序性在很多应用中都会简化很多的操作；2、红黑树，内部实现一个红黑书使得map的很多操作在lgn的时间复杂度下就可以实现，因此效率非常的高。
map缺点：空间占用率高，因为map内部实现了红黑树，虽然提高了运行效率，但是因为每一个节点都需要额外保存父节点、孩子节点和红 / 黑性质，使得每一个节点都占用大量的空间。
适用处：对于那些有顺序要求的问题，用map会更高效一些。

//unordered_map优缺点：
unordered_map优点：因为内部实现了哈希表，因此其查找速度非常的快
unordered_map缺点：哈希表的建立比较耗费时间
适用处 : 对于查找问题，unordered_map会更加高效一些，因此遇到查找问题，常会考虑一下用unordered_map

//总结:
1、内存占有率的问题就转化成红黑树 VS hash表, 还是unorder_map占用的内存要高；但是unordered_map执行效率要比map高很多。
2、对于unordered_map或unordered_set容器，其遍历顺序与创建该容器时输入的顺序不一定相同，因为遍历是按照哈希表从前往后依次遍历的
3、map和unordered_map的使用，unordered_map的用法和map是一样的，提供了 insert，size，count等操作，并且里面的元素也是以pair类型来存贮的。其底层实现是完全不同的，上方已经解释了，但是就外部使用来说却是一致的。
#endif

class Solution
{
public:
	vector<int> TwoSum(vector<int>& nums, int target)
	{
		int iSize = nums.size();
		vector<int> result;
		//1、暴力求解法
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

		//2、哈希表法
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
	//数据初始化
	int arr[] = { 3, 2, 4 };
	for (int i = 0; i < GetSize(arr); i++)
	{
		nums.push_back(arr[i]);
	}

	//两数之和
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