#include<stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;

int MaxTwinSum(LNode* L)
{
	LNode* slow=L,*fast = L->next;
	while(fast!=NULL&&fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	LNode* new_head=NULL,*q=slow->next,*temp;
	while (q != NULL)
	{
		temp = q->next;
		q->next = new_head;
		new_head = q;
		q = temp;
	}
	q = new_head;
	LNode* p = L;
	int max=0,num_temp;
	while (q != NULL)
	{
		num_temp = p->data + q->data;
		if (num_temp > max)
		{
			max = num_temp;
		}
		p = p->next;
		q = q->next;
	}
	return max;
}