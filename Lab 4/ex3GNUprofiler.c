#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "linkedlist.h"
#include "myallocfree.h"
#include <sys/time.h>

struct linkedList * createList(int n){
	struct linkedList * head=(struct linkedList *)myalloc(sizeof(struct linkedList));
	head->first=NULL;
	head->count=0;
	srand(time(0));
	int * i=(int *)myalloc(sizeof(int));
	int * rn=(int *)myalloc(sizeof(int));
	
	*i=0;
	for((*i)=0; (*i)<n; ++(*i)){	
		*rn=rand();
		insertFirst(head,rn);
	}
	return head;
}
struct linkedList * createCycle(struct linkedList * head)
{
	int * r=(int *)myalloc(sizeof(int));
	int * flag=(int *)myalloc(sizeof(int));
	*flag=0;
	struct node * temp=head->first;
	srand(time(0));
	(*r)=rand()%2;
	if((*r)==0){
		printf("It will remain linear linked list and cycle isn't created....\n");
		return head;
	}
	else{
		printf("Cyclic list will be created....\n");
		temp=head->first;
		struct node * getEle=head->first;	//getEle is for searching tail of the linkedlist which is required element here
		while((getEle->next)!=NULL)
		{
			getEle=getEle->next;	
		}
		while((*flag)==0)
		{
			(*r)=rand();
			temp=head->first;
			while(temp!=NULL)
			{
				if(temp->ele==(*r))
				{
					getEle->next=temp;
					(*flag)=1;
					break;
				}
				temp=temp->next;
			}
		}
		printf("\nCycle made successfully!!\n");
		return head;
	}
}

void main(){
	
	struct linkedList * head=createList(7000000);
	head =createCycle(head);

	FILE *f;
	f=fopen("ex3Output.txt","w");
	fprintf(f,"---Memory allocated in  heap: %d\n",getheap());
	
	bool testResults=testCyclic(head);
	printf("\n\n******* testCyclic() Results *******\n");
	if(testResults==false)
		printf("It's a linear linked list!!\n");
	else
		printf("It's a cyclic linked list!!\n");

	fclose(f);
}