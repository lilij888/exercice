#include<stdlib.h>
#include<stdbool.h>

typedef struct LinkedQueue
{
	int data;
	int tag;
	struct LinkedQueue* next,*pre;
}LinkedQueue,*Head,*Tail;

void Initial(Head* H, Tail* T)
{
	(*H) = NULL;
	(*T) = NULL;
}

bool Insert(Head* H, Tail* T,int x)
{
	if ((*H) == NULL)
	{
		LinkedQueue* p = (LinkedQueue*)malloc(sizeof(LinkedQueue));
		p->data = x;
		p->tag = 1;
		p->next = p;
		p->pre = p;
		(*H) = (*T) = p;
		return true;
	}
	else if ((*T)->tag==1)
	{
		LinkedQueue* p = (LinkedQueue*)malloc(sizeof(LinkedQueue));
		p->data = x;
		p->tag = 1;
		LinkedQueue* q = (*T)->next;
		(*T)->next = p;
		p->pre = (*T);
		p->next = q;
		q->pre = p;
		(*T) = p;
		return true;
	}
	else
	{
		(*T)->data = x;
		(*T)->tag = 1;
		(*T) = (*T)->next;
		return true;
	}


}

bool Delete(Head* H, Tail* T,int* x)
{
	if ((*H) == NULL||(*H)->tag==0)
	{
		return false;
	}
	*x = (*H)->data;
	(*H)->tag = 0;
	if ((*T)->tag == 1)
	{
		(*T) = (*H);
	}
	(*H) = (*H)->next;
	return true;
}