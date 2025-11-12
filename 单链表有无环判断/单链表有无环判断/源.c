#include<stdlib.h>

typedef struct LNode 
{
	int data;
	struct LNode* next;
}LNode;

LNode* HasCycle(LNode* head, int* has_cycle) 
{
	*has_cycle = 0;
	if (head == NULL || head->next == NULL)
	{
		return NULL;
	}
	LNode* slow = head;
	LNode* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			*has_cycle = 1;
			return slow;
		}
	}
	return NULL;
}