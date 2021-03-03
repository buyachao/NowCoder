#include "NowCoder.h"

void NowCoder::LevelOrder(TreeNode* root) {
	if (root == NULL)
	{
		cout << "空的二叉树" << endl;
	}
	queue<TreeNode*> queue;					/*创建二叉树队列*/
	queue.push(root);						/*根节点入队*/

	while (!queue.empty())					/*队列不空循环 */
	{
		TreeNode* front = queue.front();	/*头元素出队列*/
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

void NowCoder::PreOrder(TreeNode* root)
{
	if (root)
	{
		cout << root->val << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}