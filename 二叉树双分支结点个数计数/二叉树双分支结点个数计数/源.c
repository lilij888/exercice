#include<stdlib.h>

typedef struct BiTNode {
	int data;
	BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

void Count(BiTree T,int *num)
{
	if (T == NULL)
	{
		return;
	}

	if (T->lchild != NULL && T->rchild != NULL)
	{
		(* num)++;
	}
	Count(T->lchild,num);
	Count(T->rchild, num);
}