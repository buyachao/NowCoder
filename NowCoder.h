#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*��ȡ���鳤��*/
template<typename T>
int GetSize(T& arr)
{
	return sizeof(arr) / sizeof(arr[0]); //return end(arr) - begin(arr);
}

//������ṹ
struct NClistNode
{
	int val; //�ڵ�ֵ
	NClistNode* next; //ָ����һ������ָ��
	NClistNode(int x) : val(x), next(NULL) {} //��ʼ����ǰ���ֵΪx,ָ��Ϊ��
};

//��ͨ�������ṹ
struct NCtreeNode
{
	int val;
	struct NCtreeNode* left;
	struct NCtreeNode* right;
	NCtreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

//ƽ��������ṹ
template <typename T>
struct NCavlNode
{
	T val;
	int height; //������ڸ߶�
	NCavlNode<T>* left;
	NCavlNode<T>* right;
	NCavlNode<T>(const T theData) : val(theData), left(NULL), right(NULL), height(0) {}
};

//������
class NClinkList
{
public:
	//�����С
	int GetSize();
	//ɾ������
	void Delete(NClistNode* head);
	//�������
	void Show(NClistNode* head);
	//�����ʼ��
	NClistNode* Insert(int len, int nums[]); 
	NClistNode* Insert(NClistNode* head, int len, int nums[]);
};

//��ͨ������
class NCtree {
public:
	/*��ʼ��*/
	NCtreeNode* InitTree(int arr[], int size);
	/*�������*/
	void LevelOrder(NCtreeNode* root);
	/*ǰ�����*/
	void PreOrder(NCtreeNode* root);
	/*�������*/
	void PostOrder(NCtreeNode* root);
};

//ƽ�������
template <typename T>
class NCavlTree
{
public:
	NCavlTree<T>() {}
	~NCavlTree<T>() {}
	NCavlTree<T>* root;
	//������
	void Insert(NCavlNode<T>*& t, T x);
	//ɾ�����
	bool Delete(NCavlNode<T>*& t, T x);
	//�����Ƿ���ڸ���ֵ�Ľ��
	bool Contains(NCavlNode<T>* t, const T x) const;
	//�������
	void InorderTraversal(NCavlNode<T>* t);
	//ǰ�����
	void PreorderTraversal(NCavlNode<T>* t);
	//��Сֵ���
	NCavlNode<T>* FindMin(NCavlNode<T>* t) const;
	//���ֵ���
	NCavlNode<T>* FindMax(NCavlNode<T>* t) const;
private:
	//�����ĸ߶�
	int GetHeight(NCavlNode<T>* t);
	//����ת��������뵼�µĲ�ƽ��
	NCavlNode<T>* LL(NCavlNode<T>* t);
	//����ת�����Ҳ��뵼�µĲ�ƽ��
	NCavlNode<T>* RR(NCavlNode<T>* t);
	//˫��ת�������λ��t������ӵ�������
	NCavlNode<T>* LR(NCavlNode<T>* t);
	//˫��ת�������λ��t���Ҷ��ӵ�������
	NCavlNode<T>* RL(NCavlNode<T>* t);
};