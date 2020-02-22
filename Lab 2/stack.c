#include "stack.h"
//#include "linkedlist.h"
#include<stdlib.h>

void push (struct linkedList *head, int ele)
{
	insertFirst(head,ele);
}
struct node * pop(struct linkedList *head)
{
	struct node *firstEle= (struct node *)malloc(sizeof(struct node));
	firstEle=deleteFirst(head);
	return firstEle;
}