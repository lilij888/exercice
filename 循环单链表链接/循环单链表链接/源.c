#include<stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode, * LinkList;

void CirLinked(LinkList* h1, LinkList* h2)
{
	LinkList p = ( * h1)->next, q = ( * h2)->next;

	if (q == *h2)
	{
		free(*h2);
		*h2 = NULL;
		return;
	}
	while (p->next != *h1)
	{
		p = p->next;
	}
	while (q->next != *h2)
	{
		q = q->next;
	}
	p->next = (*h2)->next;
	q->next = h1;
	free(*h2);
	*h2 = NULL;
}