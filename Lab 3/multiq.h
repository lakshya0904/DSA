#include "que.h"
#define MAX 100
//Can be changed if more number of priorities are required
int i;
struct multiQ{
	int num;
	struct queue * (queues[MAX]);
	
	//for(i=0; i<100; ++i)
		//queues[i]= (struct queue *) malloc(sizeof(struct queue));
};
struct multiQ * createMQ(int num);
struct multiQ * addMQ(struct multiQ * mq,int tid, int p);
struct node * nextMQ(struct multiQ * mq);
struct node * delNextMQ(struct multiQ * mq);
bool isEmptyMQ(struct multiQ * mq);
int sizeMQ (struct multiQ * mq);
int sizeMQbyPriority(struct multiQ * mq, int p);
struct queue * getQueueFromMQ(struct multiQ * mq, int p);
void printMQ(struct multiQ * mq);