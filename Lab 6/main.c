#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#include "merge.h"

void main(int argc, char * argv[])
{
	FILE *f=fopen(argv[1],"r");
	FILE *append=fopen(argv[2],"a");	
	int size=2;	
	struct element *ls=(struct element *)malloc(size*sizeof(struct element));
	int i=0;
	if(f==NULL)
	{
		printf("Error in opening file!!\n");
		return ;
	}
	while(fscanf(f,"%[^,],%f\n",ls[i].name,&ls[i].cgpa)!=-1)
	{
		//printf("%s , %f\n",ls[i].name, ls[i].cgpa);	
		if(++i>=size)
		{
			size*=5;
			ls=(struct element*)realloc((struct element*) ls,size*sizeof(struct element));
		}
	}
	int lsSize=i;

	//Working of merge(): Working Fine!!!
	// Can't check its working now at this position
		//	So, don't tyry it out :-|
	/*
	struct element *l=(struct element *)malloc(ls1Size*2*sizeof(struct element));
	merge(ls1,ls1Size,ls1,ls1Size,l);
	print(l,ls1Size*2);	
	*/
	struct timeval t1, t2;
	double elapsedTime;
	gettimeofday(&t1, NULL);
	gettimeofday(&t1, NULL);
	mergeSort(ls,0,lsSize-1);	
	//printf("\n\n\n First list after sorting:\n ");
	//print(ls,lsSize);
	//printf("Space used: %ld",getSpace());
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	fprintf(append,"Total time is for sorting %d records is %lfms.\n",i,elapsedTime);
	fprintf(append,"Stack space used for sorting %d records is %ld bytes.\n\n",i,getSpace());
	
} 

