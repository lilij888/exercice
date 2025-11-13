#include<stdbool.h>

#define MAXSIZE 50 

typedef struct SqQueue
{
	int data[MAXSIZE];
	int front, rear;
	int tag;
}SqQueue;

void Initial(SqQueue* S)
{
	S->tag = 0;
	S->front = S -> rear = 0;
}

bool IsEmpty(SqQueue * S)
{
	if (S->tag == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Push(SqQueue* S,int x)
{
	if (S->tag == 1)
	{
		return false;
	}
	S->data[S->rear] = x;
	S->rear = (S->rear + 1) % MAXSIZE;
	if (S->rear == S->front)
	{
		S->tag = 1;
	}
	return true;
}

bool Pop(SqQueue* S,int* x)
{

	if (IsEmpty(S))
	{
		return false;
	}
	*x = S->data[S->front];
	S->front = (S->front + 1) % MAXSIZE;
	S->tag = 0;
	return true;
}