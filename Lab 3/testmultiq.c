#include "multiq.h"
#include <sys/time.h>

struct multiQ * loadData(FILE* f);	
struct multiQ * testDel(struct multiQ * mq, int num);	
int main(int argc, char * argv[])
{
	int num=5000;
	FILE* fileptr=fopen(argv[1],"r");		//filename.txt must simply filename doesn't work
	
	struct timeval t1, t2;
	double elapsedTime;
	// start timer
	gettimeofday(&t1, NULL);
	struct multiQ * mq=loadData(fileptr);
	// stop timer
	gettimeofday(&t2, NULL);
	// compute and print the elapsed time in millisec
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
	printf("Total time elapsed in loadData is %lf ms.\n",elapsedTime );
	
	gettimeofday(&t1, NULL);
	mq=testDel(mq, num);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
	printf("Total time elapsed in delTest() is %lf ms.\n",elapsedTime );
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