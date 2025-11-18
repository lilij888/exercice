typedef struct BiTNode
{
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

void PreToPost(int* pre,int left,int right,int*post,int*postIdx)
{
	if (left > right)
	{
		return;
	}
	int rootVal = pre[left];
	int len = right - left + 1;
	int m = (len - 1) / 2;
	PreToPost(pre, left + 1, left + m, post, postIdx);
	PreToPost(pre, m + 1,right, post, postIdx);
	post[*postIdx] = rootVal;
	(*postIdx)++;
}