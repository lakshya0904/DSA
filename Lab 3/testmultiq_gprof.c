#include "multiq.h"

struct multiQ * loadData(FILE* f);	
struct multiQ * testDel(struct multiQ * mq, int num);	
int main(int argc, char * argv[])
{
	int num=5000;
	FILE* fileptr=fopen(argv[1],"r");		//filename.txt must simply filename doesn't work
	
	struct multiQ * mq=loadData(fileptr);
	mq=testDel(mq, num);
	/*
	printf("Total size of mq now: %d\n",sizeMQ (mq));
	printMQ(mq);
	*/
	return 0;
}
struct multiQ * loadData(FILE* f)
{
	struct multiQ * mq=createMQ(10);
	int tid, p;
	char ch;
	/*
	while(fscanf(f,"%d","%d",&tid,&p)!=EOF)
		mq=addMQ(mq,tid,p);
	*/
	while(!feof(f))		//feof() return non-zero value when end of file is reached
	{
		if(fscanf(f,"%d,%d",&tid,&p)==-1)
			break;
		mq=addMQ(mq,tid,p);
	}
	return mq;
}
struct multiQ * testDel(struct multiQ * mq, int num)
{
	int i;
	struct node * deleted;
	for(i=0; i<num; ++i)
		deleted=delNextMQ(mq);
	return mq;
}