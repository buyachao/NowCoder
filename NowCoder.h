#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*获取数组长度*/
template<typename T>
int GetSize(T& arr)
{
	return sizeof(arr) / sizeof(arr[0]); //return end(arr) - begin(arr);
}

//单链表结构
struct NClistNode
{
	int val; //节点值
	NClistNode* next; //指向下一个结点的指针
	NClistNode(int x) : val(x), next(NULL) {} //初始化当前结点值为x,指针为空
};

//普通二叉树结构
struct NCtreeNode
{
	int val;
	struct NCtreeNode* left;
	struct NCtreeNode* right;
	NCtreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

//平衡二叉树结构
template <typename T>
struct NCavlNode
{
	T val;
	int height; //结点所在高度
	NCavlNode<T>* left;
	NCavlNode<T>* right;
	NCavlNode<T>(const T theData) : val(theData), left(NULL), right(NULL), height(0) {}
};

//单链表
class NClinkList
{
public:
	//链表大小
	int GetSize();
	//删除链表
	void Delete(NClistNode* head);
	//链表查找
	void Show(NClistNode* head);
	//链表初始化
	NClistNode* Insert(int len, int nums[]); 
	NClistNode* Insert(NClistNode* head, int len, int nums[]);
};

//普通二叉树
class NCtree {
public:
	/*初始化*/
	NCtreeNode* InitTree(int arr[], int size);
	/*层序遍历*/
	void LevelOrder(NCtreeNode* root);
	/*前序遍历*/
	void PreOrder(NCtreeNode* root);
	/*后序遍历*/
	void PostOrder(NCtreeNode* root);
};

//平衡二叉树
template <typename T>
class NCavlTree
{
public:
	NCavlTree<T>() {}
	~NCavlTree<T>() {}
	NCavlTree<T>* root;
	//插入结点
	void Insert(NCavlNode<T>*& t, T x);
	//删除结点
	bool Delete(NCavlNode<T>*& t, T x);
	//查找是否存在给定值的结点
	bool Contains(NCavlNode<T>* t, const T x) const;
	//中序遍历
	void InorderTraversal(NCavlNode<T>* t);
	//前序遍历
	void PreorderTraversal(NCavlNode<T>* t);
	//最小值结点
	NCavlNode<T>* FindMin(NCavlNode<T>* t) const;
	//最大值结点
	NCavlNode<T>* FindMax(NCavlNode<T>* t) const;
private:
	//求树的高度
	int GetHeight(NCavlNode<T>* t);
	//单旋转，左左插入导致的不平衡
	NCavlNode<T>* LL(NCavlNode<T>* t);
	//单旋转，右右插入导致的不平衡
	NCavlNode<T>* RR(NCavlNode<T>* t);
	//双旋转，插入点位于t的左儿子的右子树
	NCavlNode<T>* LR(NCavlNode<T>* t);
	//双旋转，插入点位于t的右儿子的左子树
	NCavlNode<T>* RL(NCavlNode<T>* t);
};