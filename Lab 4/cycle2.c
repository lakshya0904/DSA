#include "cycle.h"
bool testCyclic(struct linkedList * head){

	if(head->count==0)
		return false;
	if(head->count==1)
		if(head->first==head->first->next)
			return true;
		else
			return false;
	
	struct node * prev=NULL;
	struct node * current=head->first;
	struct node * first=head->first;	
	struct node * nxt=head->first->next;
	while(current!=NULL)
	{
		nxt=current->next;
		current->next=prev;
		prev=current;
		current=nxt;
		if(current==first)
			return true;
		
	}
	return false;
	//return (prev==first);
}