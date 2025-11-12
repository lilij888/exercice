#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode* link;
}LNode,*LinkList;

LNode* CheckCountdown(LinkList* L,int k)
{
	LinkList p = *L;
	int count=0;
	if (p == NULL)
	{
		return NULL;
	}
	while (p->link != NULL)
	{
		p = p->link;
		count++;
	}
	if (k > count + 1)
	{
		return NULL;
	}
	p = *L;
	for (int i = 0; i < count - k+1; i++)
	{
		p = p->link;
	}
	return p;
}

LNode* BetterCheckCountdown(LinkList* L, int k)
{
	LinkList p = *L, q = *L;
	if (*L == NULL)
	{
		return NULL;
	}
	for (int i = 0; i < k; i++)
	{
		if (q->link == NULL)
		{
			return NULL;
		}
		q = q->link;
	}
	while (q != NULL)
	{
		q = q->link;
		p = p->link;
	}
	return p;
}