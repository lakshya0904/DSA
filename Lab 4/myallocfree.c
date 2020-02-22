#include "myallocfree.h"
#include<stdlib.h>
int heap=0;
void * myalloc(int n){
        void * r= malloc(n+sizeof(int));
        heap+=(n+sizeof(int));
	*(int *)r=n;
        return (r+sizeof(int));
}
void myfree(void *ptr){
	heap-=*(int *)(ptr-sizeof(int));
	free(ptr-sizeof(int));
}
int getheap(){
	return heap;
}