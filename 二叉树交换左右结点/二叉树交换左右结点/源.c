#include<stdlib.h>

typedef struct BiTNode {
	int data;
	BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

void ExchangeSon(BiTree* T)
{
	if ((*T) == NULL)
	{
		return;
	}


	BiTNode* temp;
	temp = (*T)->lchild;
	(*T)->lchild = (*T)->rchild;
	(*T)->rchild = temp;
	ExchangeSon(&(*T)->lchild);
	ExchangeSon(&(*T)->rchild);
}