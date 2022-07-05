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


//˼·һ����������
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
//˼·��
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// ������Ҷ�ӽڵ����
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
	//��������k-1��+��������k-1��
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{ 
	//root==NULL return NULL
	//root�ڵ㲻������Ҫ�ҵģ��ȵ�����ȥ�ң��������û�У��ٵ�����ȥ��
	//���Ҷ�û�У���ǰ��û���ҵ�����NULL
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
// ������ǰ�����
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
// �������������
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
// �������������
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