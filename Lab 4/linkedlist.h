//#include<stdio.h>
#include<stdlib.h>
#include "myallocfree.h"
#include<stdio.h>

struct node{
	int ele;
	struct node *next;
};
struct linkedList{
	int count;
	struct node *first;
};

void insertFirst(struct linkedList *head, int * ele);
struct node * deleteFirst(struct linkedList *head);
void printList(struct linkedList *head);

