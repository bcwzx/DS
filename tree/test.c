#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Queue.h"
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType x);
// ����������
void BinaryTreeDestory(BTNode** root);
// �������ڵ����
int BinaryTreeSize(BTNode* root);
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root);
// �������������
void BinaryTreeInOrder(BTNode* root);
// �������������
void BinaryTreePostOrder(BTNode* root);
// �������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root);
#define _CRT_SECURE_NO_WARNINGS 1

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
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
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
	BTNode* left = BinaryTreeFind(root->left, x);
	if (left)
		return left;
	BTNode* right = BinaryTreeFind(root->right, x);
	if (right)
		return right;

	return NULL;

}
// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
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
//�������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);
		if (front->left)
		{
			QueuePush(&q,front->left);
		}
		if (front->right)
		{
			QueuePush(&q,front->right);
		}
	}
	QueueDestory(&q);
	printf("\n");
}
bool BinaryTreeComplete(BTNode* root)
{
	//��������ߣ��ڵ���������
	//��ȫ�������������ߣ��ڵ��������ģ��������˿��Ժ󣬺���ȫ�վ�����ȫ����������������зǿգ���ô
	//�Ͳ��ǣ���Ϊ��ȫ�������������ߣ��ڵ��������ģ��������Ժ���������зǿգ�˵����������
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			break;
		}
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
			return false;
	}
	QueueDestory(&q);
	return true;
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
int main()
{

	BTNode* A = BinaryTreeCreate('A');
	BTNode* B = BinaryTreeCreate('B');
	BTNode* C = BinaryTreeCreate('C');
	BTNode* D = BinaryTreeCreate('D');
	BTNode* E = BinaryTreeCreate('E');
	BTNode* F = BinaryTreeCreate('F');
	BTNode* G = BinaryTreeCreate('G');
	
	A->left = B;
	A->right = C;
	B->left = D;
	B->right = G;
	C->left = E;
	C->right = F;


	BinaryTreePrevOrder(A);
	printf("\n");

	BinaryTreeInOrder(A);
	printf("\n");

	BinaryTreePostOrder(A);
	printf("\n");


	/*int size = 0;
	BinaryTreeSize(A, &size);
	printf("BinaryTreeSize:%d\n", size);

	size = 0;
	BinaryTreeSize(A, &size);
	printf("BinaryTreeSize:%d\n", size);*/

	printf("BinaryTreeSize:%d\n", BinaryTreeSize (A));
	printf("BinaryTreeSize:%d\n", BinaryTreeSize (A));

	printf("BinaryTreeLevelKSize:%d\n", BinaryTreeLevelKSize(A,3));

	printf("BinaryTreeFind:%p\n", BinaryTreeFind(A, 'E'));
	printf("BinaryTreeFind:%p\n", BinaryTreeFind(A, 'X'));

	BinaryTreeLevelOrder(A);

	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(A, 'X'));
	

	return 0;
}



