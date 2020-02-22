#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node {
	int tid;
	int p;
	struct node * next;
};
struct queue{
	int count;
	struct node * front;
	struct node * rear;
};

struct queue * newQ();
bool isEmpty(struct queue * q);
struct queue * delQ(struct queue * q);
struct node * front(struct queue * q);
struct queue * addQ(struct queue * q, int tid, int p);
int lengthQ(struct queue * q);
void printQ(struct queue * q);
