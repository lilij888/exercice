#include<stdlib.h>

typedef struct BiTNode {
	int data;
	BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

void PreOrder(BiTree T, int k,int *i,int*data,int* tag)
{
	if (T == NULL || *tag == 1)
	{
		return;
	}
	(*i)++;
	if (*i == k)
	{
		*data=T->data;
		*tag = 1;;
	}
	PreOrder(T->lchild, k,i,data,tag);
	PreOrder(T->rchild, k,i,data,tag);
	
}

