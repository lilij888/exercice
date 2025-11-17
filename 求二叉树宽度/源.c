#include<stdlib.h>
#include<stdbool.h>

typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

#define MaxSize 50

//队列
//定义
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


int WidthMeasure(BiTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	SqQueue Q;
	BiTNode* p = NULL;
	int width = 0;
	InitQueue(&Q);
	EnQueue(&Q, T);
	while (!QueueEmpty(&Q))
	{
		int levelSize = (Q.rear - Q.front + MaxSize) % MaxSize;
		if (levelSize > width)
		{
			width = levelSize;
		}
		for (int i = 0; i < levelSize; i++)
		{
			DeQueue(&Q, &p);
			if (p->lchild != NULL)
			{
				EnQueue(&Q, p->lchild);
			}
			if (p->rchild != NULL)
			{
				EnQueue(&Q, p->rchild);
			}

		}

	}
	return width;
}