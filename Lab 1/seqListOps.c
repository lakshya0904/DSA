/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
	printf ("JOB ID = %d, Priority = %d, Execution time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list)
{
	int i; int size;

	printf("\n Enter the Number of Jobs : ");
	scanf("%d", &size);

	for (i=0;i<size;i++)
	{
	printf ("\nEnter job ID: ");
	scanf ("%d",&list[i].id);
	printf ("Enter Priority (from 0 - 2): ");
	scanf ("%d",&list[i].pri);
	printf ("Execution Time: ");
	scanf ("%d",&list[i].et);
	printf ("Arrival Time: ");
	scanf ("%d",&list[i].at);
	}
	return size;
}
int initialize_elements (JobList list){
	return inputJobs(list);
}
SeqList insert(Job j , SeqList sl)
{

//Implement this function
//
	
	int i,temp;
	//if(sl.size==0)
	
	
		for (i=sl.head ; st[i].next != -1 ; i=st[i].next)
		{
			if (compare(st[st[i].next].ele , j) == GREATER)
				break;
		}
		temp = nextfreeloc++;
		st[temp].next = st[i].next;
		st[temp].ele = j;
		st[i].next = temp;
		sl.size++;
		return sl;
	
	
	/*if(sl.size==0)
	{
		//st[sl.head].ele=j;
		st[sl.head].next=-1;
		
		//st[nextfreeloc].ele=j;
		//st[nextfreeloc].next=-1;
		
		st[sl.head].ele=j;
		//st[nextfreeloc].next = -1;
		//st[sl.head].next = nextfreeloc;
		nextfreeloc++;
		sl.size++;
	}*/
	
	
	/*int i,temp;
	for (i=sl.head ; st[i].next != -1 ; i=st[i].next)
	{
		if (compare(st[st[i].next].ele , j) == GREATER)
			break;
	}
	temp = nextfreeloc++;
	st[temp].next = st[i].next;
	st[temp].ele = j;
	st[i].next = temp;
	sl.size++;
	return sl;
	*/
 }
  
void insertelements (JobList list , int size, SeqList s[3])
{

// Implement this function
	int i,j;
	for(j=0; j<3; ++j)
	{
			for (i=0;i<size;i++)
			{
				if(list[i].pri==j)
					s[j] = insert (list[i],s[j]);
			}
	}

}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{

// Implement this function
	
	int i, j, index = 0;
    for( i = 2; i>=0; i--) {
        for( j=s[i].head; st[j].next != -1; j = st[j].next) {
            ele[index] = st[ st[j].next].ele;
            index++;
        }
    }
}

void printlist(SeqList sl)
{

// Implement this function
	int i;
 printf ("\nSize of this list = %d\n",sl.size);
 for (i=st[sl.head].next ; st[i].next != -1 && sl.size!=0; i=st[i].next)
 {
  printJob (st[i].ele);
 }
 if(sl.size!=0)
	 printJob (st[i].ele);

}

void printJobList(JobList list, int size)
{

// Implement this function
int i;
 for (i=0;i<size;i++)
 {
  printJob (list[i]);
 }

}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);
 printlist(seq[0]);   
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele (seq , list); 
}
