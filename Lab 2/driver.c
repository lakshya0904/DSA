//#include "linkedlist.h"
#include "stack.h"
#include<stdlib.h>
#include<stdio.h>
int main(int argc, char * argv[])
{
	FILE *fileptr;
	fileptr=fopen(argv[1],"r");
	struct linkedList *head= (struct linkedList *)malloc(sizeof(struct linkedList));
	head->count=0;
	head->first=NULL;
	while(!feof(fileptr))
	{
		int temp;
		if(fscanf(fileptr,"%d",&temp)==-1)
			break;
		push(head,temp);
	}
	
	printList(head);
	
	printf("\n\nNow popping out elements....\n");
	struct node *popped =(struct node*)malloc(sizeof(struct node));
	while(head->count!=0)
	{
		popped=pop(head);
		printf("Deleted element is: %d\n",popped->ele);
	}
	return 0;
	
}