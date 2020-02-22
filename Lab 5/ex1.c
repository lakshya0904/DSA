#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/time.h>
struct cc{
        char cno[17];
        char bc[6];
        char exp[8];
        char fn[6];
        char ln[6];
};
int * start;
int * end;
void insertInOrder(struct cc *info, int size)
{
	int prevPos=size-2; 	//prevPos denotes the element just before 
									//the element you want to insert at correct position
	struct cc toInsert=info[size-1];	//it denotes the element which we want to insert 
													//at correct position
	while(prevPos>=0 && strlen(info[prevPos].cno)>strlen(toInsert.cno)){
		info[prevPos+1]=info[prevPos];
		prevPos--;
	}
	//above function is required because file is containing some credit card no of
	//digits less than 16 which ideally shouldn't be the case
	while(prevPos>=0 && (strcmp(info[prevPos].cno,toInsert.cno)>0) ){
		//in place of toInsert.cno, info[size-1] will not work.....
		info[prevPos+1]=info[prevPos];
		prevPos--;
	}
	info[prevPos+1]=toInsert;
}

void insertionSort(struct cc *info, int size){
	if(size>=2)	{
		if(size==2){
			int a;
			end=&a;
		}
		insertionSort(info,size-1);
		insertInOrder(info,size);	
	}
}

void printlist(struct cc * info, int i)
{
	int j=0;
	for(j=0; j<i; ++j)
		printf("%s, %s, %s, %s, %s \t\t\n",info[j].cno, info[j].bc,info[j].exp,info[j].fn,info[j].ln);
}

void main(int argc, char * argv[]){
	struct timeval t1, t2;
	double elapsedTime;
	// start timer
	gettimeofday(&t1, NULL);

    FILE *f=fopen(argv[1],"r");
	FILE *append=fopen("ReqOutputs.txt","a");
	int size=2;	
	struct cc *info=(struct cc *)malloc(size*sizeof(struct cc));
	int i=0;
	if(f==NULL)
	{
		printf("Error in opening file!!\n");
		return ;
	}
	while(fscanf(f,"\"%[^,],%[^,],%[^,],%[^,],%[^\"]\"\n",info[i].cno,info[i].bc, info[i].exp, info[i].fn, info[i].ln)!=-1)
	// & doesn't come in case of array of characters	
	//^ denotes not
	//[a-z] read anything from a to z;
	{
		//printf("%s, %s, %s, %s, %s \t\t\n",info[i].cno, info[i].bc,info[i].exp,info[i].fn,info[i].ln);	
		if(++i>=size)
		{
			size*=5;
			info=(struct cc*)realloc((struct cc *) info,size*sizeof(struct cc));
		}
	}
	// stop timer
	gettimeofday(&t2, NULL);
	// compute and print the elapsed time in millisec
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	fprintf(append,"Total time is for reading %d records is %lfms.\n",i,elapsedTime);

	//Note: for number of records>=100000 stack will get full during sorting
	//Therefore, no output corresponding to them
	int s;
	start=&s;
	gettimeofday(&t1, NULL);
	insertionSort(info,i);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	fprintf(append,"Total time is for sorting %d records is %lfms.\n",i,elapsedTime);
	fprintf(append,"Stack space used for sorting %d records is %ld bytes.\n\n",i,(start-end)*4);
		//printlist(info,i);
}

