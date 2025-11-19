#include<stdlib.h>

typedef struct BiTNode
{
	int weight;
	struct BiTNode* left, * right;
}BiTNode,*BiTree;


void BiTreeWPL(BiTree root,int*height,int*WPL)
{
	if (root == NULL)
	{
		return ;
	}
	(*height)++;
	BiTreeWPL(root->left,height,WPL);
	BiTreeWPL(root->right,height,WPL);
	if (root->left == NULL && root->right == NULL)
	{
		(*WPL) += root->weight * ( * height);
	}
	(*height)--;
	return;
}