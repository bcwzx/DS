#define _CRT_SECURE_NO_WARNINGS 1
#include"tree.h"
BTNode* BinaryTreeCreate(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}


//思路一：遍历计数
//int BinaryTreeSize(BTNode* root,int*psize)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	++(*psize);
//	BinaryTreeSize(root->left,psize);
//	BinaryTreeSize(root->right,psize);
//}
//思路二
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left)+ BinaryTreeLeafSize(root->right);
}
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	//左子树的k-1层+右子树的k-1层
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{ 
	//root==NULL return NULL
	//root节点不是我们要找的，先到左树去找，左树如果没有，再到右树去找
	//左右都没有，当前树没有找到返回NULL
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* left = BinaryTreeFind(root->left , x);
	if (left)
		return left;
	BTNode* right = BinaryTreeFind(root->right, x);
	if(right)
		return right;

	return NULL;

}
// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root==NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);

}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}
void BinaryTreePostOrder(BTNode* root)
{

}
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
	root = NULL;
}