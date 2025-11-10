#include<stdbool.h>

typedef struct LNode
{
	int data;
	struct LNode* next;
	struct LNode* prior;
}LNode,*LinkList;

bool SymmetryJudgment(LinkList B) 
{
	LinkList p = B->next;
	LinkList q = B->prior;
	if (B->next == B)
	{
		return true;
	}
	while (1)
	{
		if (p->data == q->data)
		{
			p = p->next;
			if (p == q)
			{
				return true;
			}
			q = q->prior;
			if (p == q)
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
}