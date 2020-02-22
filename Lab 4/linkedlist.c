#include "linkedlist.h"
#include<stdlib.h>
#include "myallocfree.h"
#include<stdio.h>

void insertFirst(struct linkedList *head, int * ele)
{
	struct node *newEle=(struct node*) myalloc(sizeof(struct node));
	/*newEle->ele=ele;
	newEle->next=head->first;
	head->first=newEle;

	head->count++;*/
	
	newEle->ele=* ele;
	
	if(head->count==0)
	{
		newEle->next=NULL;
		head->first=newEle;
	}
	else{
		newEle->next=head->first;
		head->first=newEle;
	}
	head->count++;
	//*/
}

struct node * deleteFirst(struct linkedList *head)
{
	struct node *firstEle=(struct node*) myalloc(sizeof(struct node));
	struct node *secondEle=(struct node*) myalloc(sizeof(struct node));
	if(head->first==NULL)
		return NULL;
	else
	{
		firstEle=head->first;
		head->first=firstEle->next;
		head->count--;
		return firstEle;	
	}
}

void printList(struct linkedList *head)
{
	struct node * getEle=head->first;
	while(getEle!=NULL)
	{
		printf("Element is: %d\n",getEle->ele);
		getEle=getEle->next;	
	}
}
