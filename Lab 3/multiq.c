#include "multiq.h"

/*modify your code for the cases when initially some element was there 
	for priority 'p' lying in mq somewhere but later it had no elements
	
	Solution: 
*/
int i;
struct multiQ * createMQ(int num)
{
	struct multiQ * mq= (struct multiQ *)malloc(sizeof(struct multiQ));
	for(i=0; i<num; ++i)
		mq->queues[i]=newQ();
	mq->num=num;
	return mq;
}

struct multiQ * addMQ(struct multiQ * mq, int tid, int p)
{
	int flag =0, i;
	for(i=0; i<mq->num; ++i)
		if(!isEmpty(mq->queues[i]))
			if(front(mq->queues[i])->p==p)
			{
				mq->queues[i]=addQ(mq->queues[i], tid, p);
				return mq;
				break;
			}
		/*else
		{
			mq->queues[i]=addQ(mq->queues[i], tid, p);
				break;
		}*/
	for(i=0; i<mq->num; ++i)
		if(isEmpty(mq->queues[i]))
		{
			mq->queues[i]=addQ(mq->queues[i], tid, p);
			return mq;
		}
}

struct node * nextMQ(struct multiQ * mq)
{
	struct node * ans=NULL;
	int maxp=-1000,i;
	for(i=0; i<mq->num; ++i)
		if(!isEmpty(mq->queues[i]) && front(mq->queues[i])->p>maxp)
		{
			ans=front(mq->queues[i]);
			maxp=front(mq->queues[i])->p;
		}
	return ans;
}

struct node * delNextMQ(struct multiQ * mq)
{
	struct node * ans=NULL;
	int maxp=-1000,i;
	for(i=0; i<mq->num; ++i)
		if(!isEmpty(mq->queues[i]) && front(mq->queues[i])->p>maxp)
		{
			//ans=front(mq->queues[i]);
			maxp=front(mq->queues[i])->p;
		}
		//if(isEmpty(mq->queues[i]))
			//break;
	for(i=0; i<mq->num; ++i)
		if(!isEmpty(mq->queues[i]) && front(mq->queues[i])->p==maxp)
		{
			ans=front(mq->queues[i]);
			mq->queues[i]=delQ(mq->queues[i]);
			return ans;
		}
		//if(isEmpty(mq->queues[i]))
			//break;
}

bool isEmptyMQ(struct multiQ * mq)
{
	//bool flag=false;
	int i;
	for(i=0; i<mq->num; ++i)
		if(!isEmpty(mq->queues[i]) && front(mq->queues[i])!=NULL)
			return false;
	return true;
}

int sizeMQ (struct multiQ * mq)
{
	int ans=0, i;
	for(i=0; i<mq->num; ++i)
		ans+=(mq->queues[i])->count;
	return ans;
}

int sizeMQbyPriority(struct multiQ * mq, int p)
{
	int i;
	for(i=0; i<mq->num; ++i)
		if(!isEmpty(mq->queues[i]) && front(mq->queues[i])->p==p)
			return (mq->queues[i])->count;
	return 0;
}

struct queue * getQueueFromMQ(struct multiQ * mq, int p)
{
	int i;
	for(i=0; i<mq->num; ++i)
		if(!isEmpty(mq->queues[i]) && front(mq->queues[i])->p==p)
			return (mq->queues[i]);
	return NULL;
}

void printMQ(struct multiQ * mq)
{
	int i;
	for(i=0; i<mq->num; ++i)
		printQ(mq->queues[i]);
}


