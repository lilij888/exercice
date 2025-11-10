#include<stdlib.h>

typedef struct DLNode
{
	int data;
	int freq;
	struct DLNode* next;
	struct DLNode* pre;

}DLNode, * DLinkList;

DLinkList Locate(DLinkList* L, int x)
{
	DLinkList p = (*L)->next;
	DLinkList q;
	while (p!=NULL)
	{
		if (p->data == x)
		{
			p->freq++;
			while (1)
			{
				if (p->pre == *L)
				{
					break;
				}
				else if (p->freq >= p->pre->freq)
				{
					q = p->pre;
					p->pre = q->pre;
					q->pre = p;
					q->next = p->next;
					p->next = q;
					p->pre->next = p;
					if (q->next != NULL)
					{
						q->next->pre = q;
					}
				}
				else
				{
					break;
				}
			}
			break;
		}
		else
		{
			p = p->next;
		}
	}
	return *L;
}