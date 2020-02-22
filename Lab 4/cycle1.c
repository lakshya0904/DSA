#include "cycle.h"
bool testCyclic(struct linkedList * head){
	
	if(head->count==0)
		return false;
	if(head->count==1)
		if(head->first==head->first->next)
			return true;
		else
			return false;
	if(head->count==2)
		if(head->first==head->first->next->next)
			return true;
		else
			return false;
	struct node * hare=head->first;
	struct node * tort=head->first;
	tort=tort->next;
	hare=hare->next->next;
	while(hare->next!=NULL && hare->next->next!=NULL){
		if(hare==tort)
			return true;
		tort=tort->next;
		hare=hare->next->next;
	}
	return false;
}