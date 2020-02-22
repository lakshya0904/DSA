#include "que.h"
struct queue *newQ()
{
	struct queue * q=(struct queue * )malloc(sizeof(struct queue));
	q->count=0;
	q->front=NULL;
	q->rear=NULL;
	return q;
}
bool isEmpty (struct queue * q)
{
	if(q->count==0)
		return true;
	else
		return false;
}
struct queue * delQ(struct queue * q)
{
	if(q->count==0)
		return q;
	else
	{
		struct node * firstEle;
		firstEle=q->front;
		q->front=firstEle->next;
		q->count--;
		if(q->count==0)
		{
			q->front=NULL;
			q->rear=NULL;
		}
		return q;
	}
}
struct node * front(struct queue * q)
{
	return q->front;
}
struct queue * addQ(struct queue * q, int tid, int p)
{
	struct node * newEle=(struct node *)malloc(sizeof(struct node));
	newEle->tid=tid;
	newEle->p=p;
	newEle->next=NULL;
	if(q->count!=0)
		(q->rear)->next=newEle;
	q->rear=newEle;
	if(q->count==0)
		q->front=newEle;	
	q->count++;
	return q;
}
int lengthQ(struct queue * q)
{
	return q->count;
}

void printQ(struct queue * q)
{
	if(q==NULL) 		
		printf("\t\tQueue is empty/No such queue!!!\n");
	else
	{
		struct node * ele=q->front;
		while(ele!=NULL)
		{
			printf("\t\tTask ID: %d\n",ele->tid);
			printf("\t\tTask priority: %d\n\n",ele->p);
			ele=ele->next;
		}
	}
}