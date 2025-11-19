#include<stdlib.h>
#include<stdio.h>

typedef struct BiTNoded
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;


void BiTreeToExpress(BiTree T,BiTree root)
{
	
	if (T == NULL)
	{
		return;
	}
	
	if (T->lchild == NULL && T->rchild == NULL)
	{
		printf("%s", T->data);
		return;
	}
	else
	{
		if (T != root)
		{
			printf("(");
		}
	}

	BiTreeToExpress(T->lchild,root);
	printf("%s", T->data);
	BiTreeToExpress(T->rchild,root);
	if (T != root)
	{
		printf(")");
	}
	return;
}