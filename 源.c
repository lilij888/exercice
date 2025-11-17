#include<stdlib.h>

typedef struct{
	int data;
	struct LNode* next;
}LNode;

LNode* move(LNode* L, int n,int k)
{
	LNode*q,*j,* p = L;

	//找到无需移动的最后一个结点
	if (k == 0)
	{
		return p;
	}
	for (int i = 0; i < n-k-1; i++)
	{
		L = L->next;
	}
	j=q = L->next;
	L->next = NULL;
	while (q->next != NULL)
	{
		q = q->next;
	}
	q->next = p;

	return j;
}