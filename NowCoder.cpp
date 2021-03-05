#include "NowCoder.h"

/*单链表*/
NClistNode* NClinkList::Insert(int len, int nums[])
{
	//头插入法
	NClistNode* tail = NULL, * head;

	tail = (NClistNode*)malloc(sizeof(NClistNode));
	int length = 1;
	if (tail == NULL)
	{
		cout << "链表初始化失败" << endl;
		return NULL;
	}
	head = tail;

	tail->next = NULL;

	for (int i = 0; i < len; i++)
	{
		//追加新节点
		NClistNode* n = (NClistNode*)malloc(sizeof(NClistNode)); //创建新节点
		length++;
		if (n == NULL)
		{
			cout << "新节点内存申请失败" << endl;
			return NULL;
		}

		//若原链表为非空，则将新建节点添加到表尾
		while (tail->next != NULL)	//若未到表尾，则移动tail直到tail指向表尾
		{
			tail = tail->next;		//让tail指向下一个节点
		}
		tail->next = n;				//将尾节点指针指向新节点
		n->val = nums[i];		    //将单个数组元素赋值给新节点的节点值
		n->next = NULL;				//将新节点置为表尾
	}
	tail->next = head->next;      //形成环链表

	return head->next;			//返回添加节点后的链表的头指针
}

void NClinkList::Show(NClistNode* head)
{
	NClistNode* n;
	n = head;
	do
	{
		cout << n->val << " ";
		n = n->next;

	} while (n != head);

	cout << n->val << endl;
}
void NClinkList::Delete(NClistNode* head)
{
	int length = 0;
	NClistNode* q, * p = head->next;
	while (p != head)
	{
		q = p->next;
		free(p);
		length++;
		p = q;
	}
	free(head);
	head = NULL;
}
/*普通二叉树*/
void NCtree::LevelOrder(NCtreeNode* root) {
	if (root == NULL)
	{
		cout << "空的二叉树" << endl;
	}
	queue<NCtreeNode*> queue;				/*创建二叉树队列*/
	queue.push(root);						/*根节点入队*/

	while (!queue.empty())					/*队列不空循环 */
	{
		NCtreeNode* front = queue.front();	/*头元素出队列*/
		queue.pop();						/*退出队列*/

		cout << front->val << " ";			/*访问指向node的节点*/

		if (front->left)
		{
			queue.push(front->left);		/*左子树不为空，将左子树入队*/
		}

		if (front->right)
		{
			queue.push(front->right);		/*右子树不为空，将右子树入队*/
		}
	}

	cout << endl;
}
void NCtree::PreOrder(NCtreeNode* root)
{
	if (root)
	{
		cout << root->val << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
void NCtree::PostOrder(NCtreeNode* root)
{
	if (root)
	{
		PreOrder(root->left);
		PreOrder(root->right);
		cout << root->val << " ";
	}
}
NCtreeNode* NCtree::InitTree(int arr[], int size)
{
	if (size < 1)
	{
		return NULL;
	}

	NCtreeNode** nodes = new NCtreeNode * [size];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 0)
		{
			nodes[i] = NULL;
		}
		else
		{
			nodes[i] = new NCtreeNode(arr[i]);
		}
	}

	queue<NCtreeNode*> nodeQueue;
	nodeQueue.push(nodes[0]);

	NCtreeNode* node;
	int index = 1;
	while (index < size)
	{
		node = nodeQueue.front();
		nodeQueue.pop();
		nodeQueue.push(nodes[index++]);
		node->left = nodeQueue.back();
		nodeQueue.push(nodes[index++]);
		node->right = nodeQueue.back();
	}
	return nodes[0];
}

/*平衡二叉树*/
template <typename T>
NCavlNode<T>* NCavlTree<T>::FindMax(NCavlNode<T>* t) const
{
	if (t == NULL)
		return NULL;
	else if (t->right == NULL)
		return t;
	else
		return FindMax(t->right);
}
template <typename T>
NCavlNode<T>* NCavlTree<T>::FindMin(NCavlNode<T>* t) const
{
	if (t == NULL)
		return NULL;
	else if (t->left == NULL)
		return t;
	else
		return FindMin(t->left);
}
template <typename T>
int NCavlTree<T>::GetHeight(NCavlNode<T>* t)
{
	if (t == NULL)
	{
		return -1;
	}
	else
	{
		return t->height;
	}
}
template <typename T>
void NCavlTree<T>::Insert(NCavlNode<T>*& t, T x)
{
	if (t == NULL)
		t = new NCavlNode<T>(x);
	else if (x < t->data)
	{
		Insert(t->left, x);
		//判断平衡情况
		if (GetHeight(t->left) - GetHeight(t->right) > 1)
		{
			//存在两种情况，左左或左右
			if (x < t->left->data)
			{
				t = LL(t);
			}
			else
			{
				t = LR(t);
			}
		}
	}
	else if (x > t->data)
	{
		Insert(t->right, x);
		if (GetHeight(t->right) - GetHeight(t->left) > 1)
		{
			//存在两种情况，右右或右左
			if (x > t->right->data)
			{
				t = RR(t);
			}
			else
			{
				t = RL(t);
			}
		}
	}
	else
	{
		; //数据重复
	}

	t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;
}
template <typename T>
NCavlNode<T>* NCavlTree<T>::LL(NCavlNode<T>* t)
{
	NCavlNode<T>* q = t->left; //q 为 t 的左子树
	t->left = q->right;
	q->right = t;
	t = q;
	t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;
	q->height = max(GetHeight(q->left), GetHeight(q->right)) + 1;

	return q;
}
template <typename T>
NCavlNode<T>* NCavlTree<T>::RR(NCavlNode<T>* t)
{
	NCavlNode<T>* q = t->right; //q 为 t 的右子树
	t->right = q->left;
	q->left = t;
	t = q;
	t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;
	q->height = max(GetHeight(q->left), GetHeight(q->right)) + 1;

	return q;
}
template <typename T>
NCavlNode<T>* NCavlTree<T>::LR(NCavlNode<T>* t)
{
	//双旋转可以通过两次单旋转实现，对t的左结点进行RR旋转，再对根节点进行LL旋转
	RR(t->left);
	return LL(t);
}
template <typename T>
NCavlNode<T>* NCavlTree<T>::RL(NCavlNode<T>* t)
{
	//对t的右结点进行LL旋转，再对根节点进行RR旋转
	LL(t->right);
	return RR(t);
}