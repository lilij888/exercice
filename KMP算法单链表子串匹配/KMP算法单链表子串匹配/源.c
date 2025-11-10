#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkList;

void GetNext(LinkList B,int n,LinkList*next_poi,int* next_num) 
{
	int i=0, j=-1;
	LNode* p = NULL;
	LNode* q = B;
	next_poi[0] = NULL;
	next_num[0] = -1;
	while (i<n-1) 
	{
		if (j == -1)
		{
			p = B;
			q = q->next;
			j++;
			i++;
			next_num[i] = j;
			next_poi[i] = p;
		}
		else if ( p->data == q->data) 
		{
			p = p->next;
			q = q->next;
			i++;
			j++;
			next_num[i] = j;
			next_poi[i] = p;
		}
		else 
		{
			p = next_poi[j];
			j = next_num[j];
			
		}
	}
}

bool IndexKMP(LinkList A,LinkList B,int m,int n) 
{
	LinkList q = A;
	LinkList p = B;
	int j = 0;
	LinkList* next_poi = (LinkList*)malloc(sizeof(LinkList) * n);
	int* next_num = (int*)malloc(sizeof(int) * n);
	GetNext(B, n, next_poi,next_num);
	while (q!=NULL) 
	{
		if (j == -1)
		{
			q = q->next;
			p = B;
			j++;
		}
		else if (q->data == p->data)
		{
			q = q->next;
			p=p->next;
			j++;
		}
		else
		{
			p = next_poi[j];
			j = next_num[j];
		}
		if (j==n) {
			free(next_num);
			free(next_poi);
			return true;
		}
	}
	free(next_num);
	free(next_poi);

	return false;
}