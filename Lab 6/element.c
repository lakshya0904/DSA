#include<stdio.h>
#include "element.h"
void print(struct element * ls, int size)
{
	int i=0; 
	for(i=0; i<size; ++i)
		printf("%s,%f \n ",ls[i].name,ls[i].cgpa);
}