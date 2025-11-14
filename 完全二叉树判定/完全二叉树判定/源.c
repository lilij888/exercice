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


bool DeterCompleteBinaryTree(BiTree T)
{
	if (T == NULL)
	{
		return true;
	}
	SqQueue Q;
	BiTNode* p=NULL;
	int height = 0;
	int full_tag=0;
	int child_tag = 0;
	int empty_tag = 0;
	InitQueue(&Q);
	EnQueue(&Q, T);
	while (!QueueEmpty(&Q))
	{
		height++;
		int levelSize = (Q.rear - Q.front + MaxSize) % MaxSize;
		if (levelSize != (1 << (height - 1)))
		{
			full_tag = 1;
		}
		empty_tag = 0;
		for (int i = 0; i < levelSize; i++)
		{
			child_tag = 0;
			DeQueue(&Q, p);

			if (p->lchild != NULL && full_tag == 0)
			{

				EnQueue(&Q, p->lchild);
				child_tag = 1;
				if (empty_tag == 1)
				{
					return false;
				}
			}
			else
			{
				empty_tag = 1;
			}
			if (p->rchild != NULL && full_tag == 0)
			{
				EnQueue(&Q, p->rchild);
				child_tag = 1;
				if (empty_tag == 1)
				{
					return false;
				}
			}
			else
			{
				empty_tag = 1;
			}
			if (child_tag ==1 && full_tag == 1)
			{
				return false;
			}

		}

	}
	return true;
}