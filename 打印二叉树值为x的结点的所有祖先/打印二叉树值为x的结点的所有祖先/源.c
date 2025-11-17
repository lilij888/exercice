#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode {
	int data;
	BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

int PrintPath(BiTree T,int x)
{
	if (T == NULL)
	{
		return 0;
	}
	if (PrintPath(T->lchild, x))
	{
		printf("%d",T->data);
		return 1;
	}
	if (PrintPath(T->rchild, x))
	{
		printf("%d",T->data);
		return 1;
	}
	if (T->data == x)
	{
		return 1;
	}
	return 0;
}

