#include"merge.h"

//*********************
//recursice implementation
//*********************
int * start;
int * end;
int ans=0;
void merge(struct element * L, int n1, struct element * R, int n2, struct element * ls)
{
	int i=0, j=0;
	int k=0;	
	while(i<n1 && j<n2){
		if(L[i].cgpa<=R[j].cgpa){
			ls[k]=L[i];
			++i;	
		}
		else{
			ls[k]=R[j];
			++j;		
		}
		++k;
	}
	while(i<n1){
		ls[k]=L[i];
		++i;	
		++k;
	}
	while(j<n2){
		ls[k]=R[j];
		++j;	
		++k;
	}
}
void mergeSort(struct element * ls, int l, int r)
{
	int s;
	start=&s;
	if(l<r)
	{
		int m=(l+r)/2;
		struct element ls1[m-l+1];
		struct element ls2[r-m];
		int i=0;
		for(i=0; i<r-l+1; ++i)
			if(i<m-l+1)
				ls1[i]=ls[i];
			else
				ls2[i-m+l-1]=ls[i];
		mergeSort(ls1,0,m-l);
		mergeSort(ls2,0,r-m-1);
		/*The way other than indicated above that is either by replacing 
		line 76-85 by anyone of the following creates problem bcoz:
		1. struct element * ls1=ls;
			struct element * ls2=ls+m+1;
			mergeSort(ls1,l,m);
			mergeSort(ls1,m+1,r); 
			...bcoz after few recursion we will lend in a situation where one of the elements
			of 2nd half try to get exchanged by first element in first half bcoz ls1 will be 
			still pointing to oth index at that time also
		2. struct element * ls1=ls;
			struct element * ls2=ls+m+1;
			mergeSort(ls1,l,m);
			mergeSort(ls2,m+1,r);
			...bcoz after few recursion we will lend in a situation where we will be pointing to that
			index of 2nd half which even doesn't exist though we will not get segmentation fault 
			bcoz out conditions of merge handle that situation. 
			Ex: we pointed ls2 to (n/2)+1th position then also we are passing left argument as m+1
			which will ask it to point to (n/2)+1+(m+1) which doesn't even exist.
		*/
		struct element * ls3=(struct element *)malloc((r+1)*sizeof(struct element));
		i=0;			
		merge(ls1,m-l+1,ls2,r-m,ls3);
		for(i=0; i<(r-l+1); ++i)
			ls[i+l]=ls3[i];	
		free(ls3);
		int e;
		end=&e;
		if(end-start>ans)
			ans=end-start;
	}
}
int getSpace()
{
	return ans;
}
