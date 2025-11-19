#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 100

typedef struct BiTNode
{
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;


typedef struct {
	BiTNode* data[MaxSize];
	int front, rear;
}SqQueue;
//初始化
void InitQueue(SqQueue* Q) {
	Q->front = Q->rear = 0;
}
//队列判空
bool QueueEmpty(SqQueue* Q) {
	if (Q->front == Q->rear) {
		return true;
	}
	else {
		return false;
	}
}
//入队
bool EnQueue(SqQueue* Q, BiTNode* x) {
	if ((Q->rear + 1) % MaxSize == Q->front) {
		return false;
	}
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MaxSize;
	return true;
}
//出队
bool DeQueue(SqQueue* Q, BiTNode** x) {
	if (Q->rear == Q->front) {
		return false;
	}
	*x = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;
	return true;
}

void BiTreeToLinkList(BiTree *T)
{
	SqQueue Q;
	InitQueue(&Q);
	BiTree R,P=*T;
	if (*T == NULL)
	{
		return;
	}
	EnQueue(&Q, *T);

	while (!QueueEmpty(&Q))
	{
		DeQueue(&Q, &R);
		if (R != *T)
		{
			P->rchild = R;
		}
		if (R->lchild != NULL)
		{
			EnQueue(&Q, R->lchild);
		}
		if (R->rchild != NULL)
		{
			EnQueue(&Q, R->rchild);
		}
		P = R;
	}
	R->rchild = NULL;
}