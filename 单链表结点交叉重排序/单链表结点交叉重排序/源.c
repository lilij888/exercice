#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}NODE;

NODE* CrossSort(NODE* L)
{
	if (L == NULL)
	{
		return NULL;
	}
	NODE* slow = L->next, * fast = L->next;
	while (fast!=NULL&&fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast->next != NULL)
		{
			fast = fast->next;
		}
	}
	NODE* new_head=NULL,*p=slow,*q;
	while (p!=NULL)
	{
		q = p->next;
		p->next = new_head;
		new_head = p;
		p = q;
	}
	p = L->next;
	q = new_head;
	NODE* temp1, *temp2;
	while (p->next != NULL && q->next != NULL)
	{
		temp1 = p->next;
		p->next = q;
		p = temp1;
		temp2 = q->next;
		q->next = p;
		q = temp2;
	}
	return L;
}