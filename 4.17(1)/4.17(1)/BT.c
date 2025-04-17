#define _CRT_SECURE_NO_WARNINGS 1
#include"BT.h"
#include"queue.h"
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* buyNode(BTDataType x)
{
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = x;
	root->_left = root->_right = NULL;
}
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	BTNode* nodeA = buyNode('A');
	BTNode* nodeB = buyNode('B');
	BTNode* nodeC = buyNode('C');
	BTNode* nodeD = buyNode('D');
	BTNode* nodeE = buyNode('E');
	BTNode* nodeF = buyNode('F');
	BTNode* nodeH = buyNode('H');
	BTNode* nodeG = buyNode('G');
	nodeA->_left = nodeB;
	nodeA->_right = nodeC;
	nodeB->_left = nodeD;
	nodeB->_right = nodeE;
	nodeE->_right = nodeH;
	nodeC->_left = nodeF;
	nodeC->_right = nodeG;
	return nodeA;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return;
	BinaryTreeDestory((*root)->_left);
	BinaryTreeDestory((*root)->_right);
	free(*root);
	*root = NULL;
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 0)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);

}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	if(BinaryTreeFind(root->_left, x) != NULL)
		return BinaryTreeFind(root->_left, x);
	if (BinaryTreeFind(root->_right, x) != NULL)
	return BinaryTreeFind(root->_right, x);
	return NULL;
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
		return;
	Queue* pq;
	QueueInit(pq);
	QueuePush(pq, root);
	while (!QueueEmpty(pq))
	{
		BTNode* top = QueueFront(pq);
		printf("%c ", top->_data);
		QueuePop(pq);
		if (top->_left)
			QueuePush(pq, top->_left);
		if (top->_right)
			QueuePush(pq, top->_right);

	}
	QueueDestroy(pq);
}
// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
		return;
	Queue* pq;
	QueueInit(pq);
	QueuePush(pq, root);
	while (!QueueEmpty(pq))
	{
		BTNode* top = QueueFront(pq);
		QueuePop(pq);
		if (top == NULL)
		{
			break;
		}
		QueuePush(pq, top->_left);
		QueuePush(pq, top->_right);
	}
	while (!QueueEmpty(pq))
	{
		BTNode* top = QueueFront(pq);
		QueuePop(pq);
		if (top != NULL)
			return false;
	}
	return true;
	QueueDestroy(pq);
}