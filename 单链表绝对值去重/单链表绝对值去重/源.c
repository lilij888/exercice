#include<stdlib.h>
#include<string.h>

typedef struct LNode
{
	int data;
	struct LNode* link;
}LNode,*LinkList;

LinkList Deduplication(LinkList* L, int n)
{
	int* arr = (int*)malloc(sizeof(int) * (n+1));
	for (int i = 0; i < n+1; i++)
	{
		arr[i] = n + 1;
	}
	int num;
	if (*L == NULL)
	{
		return NULL;
	}
	LNode* p = (*L)->link,*q=*L;
	while (p != NULL)
	{
		num = abs(p->data);
		if (num < arr[num])
		{
			arr[num] = p->data;
			p = p->link;
			q = q->link;
		}
		else
		{
			q->link = p->link;
			free(p);
			p = q->link;
		}
	}
	free(arr);
	return *L;
}

LinkList BetterDeduplication(LinkList* L, int n)
{
	int* arr = (int*)calloc(n+1,sizeof(int));
	int num;
	if (*L == NULL)
	{
		return NULL;
	}
	LNode* p = (*L)->link, * q = *L;
	while (p != NULL)
	{
		num = abs(p->data);
		if (arr[num]!=0)
		{
			arr[num] = 1;
			p = p->link;
			q = q->link;
		}
		else
		{
			q->link = p->link;
			free(p);
			p = q->link;
		}
	}
	free(arr);
	return *L;
}