#include<stdlib.h>

typedef struct CSNode
{
	int data;
	struct CSNode* firstchild, * nextsibling;
}CSNode, * CSTree;

int  LeafNodeCount(CSTree T, int depth,int* real_depth)
{
	if (T == NULL)
	{
		return 0;
	}
	int current_depth = depth + 1;

	LeafNodeCount(T->firstchild, current_depth,real_depth);
	LeafNodeCount(T->nextsibling, depth, real_depth);
	return 1;
}