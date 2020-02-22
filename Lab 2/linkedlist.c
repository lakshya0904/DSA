#include "linkedlist.h"
#include<stdlib.h>

void insertFirst(struct linkedList *head, int ele)
{
	struct node *newEle=(struct node*) malloc(sizeof(struct node));
	newEle->ele=ele;
	newEle->next=head->first;
	head->first=newEle;

	head->count++;
}

struct node * deleteFirst(struct linkedList *head)
{
	struct node *firstEle=(struct node*) malloc(sizeof(struct node));
	struct node *secondEle=(struct node*) malloc(sizeof(struct node));
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

int search(struct linkedList *head, int ele)
{
	struct node *getEle=(struct node*) malloc(sizeof(struct node));
	getEle=head->first;
	while(getEle!=NULL)
	{
		if(getEle->ele==ele)
			return 1;
		getEle=getEle->next;	
	}
	return 0;
}

struct node * delete(struct linkedList * head, int ele)
{
	if(head->first==NULL)
		return NULL;
	else{
	struct node *getEle=(struct node*) malloc(sizeof(struct node)), *prev=(struct node*) malloc(sizeof(struct node));
	getEle=head->first;
	if(getEle->ele==ele)
	{
		head->first=getEle->next;
		head->count--;
		return getEle;
	}
	while(getEle!=NULL)
	{
		if(getEle->ele==ele)
		{
			//prev=getEle->next;
			prev->next=getEle->next;
			head->count--;
			return getEle;
		}
		prev=getEle;
		getEle=getEle->next;	
	}
	}
	return NULL;
}
