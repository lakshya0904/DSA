#include"merge.h"

//*********************
//iterative implementation
//*********************


//********************************************
// NOTE: stack gets out of space even before 5120 records
//********************************************

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
void mergeSort(struct element * ls, int left, int r)
{	int n=r+1;
	int i,l; // i=size to compare

	for( i=1; i<n; i = i*2) {
		for( l=0; l<n-1; l += i*2) {
			
			int m = l+i-1, r;
			if(l+(2*i)-1 > n-1) 
				r = n-1;
			else
				r = l-1 + (2*i);

			int size1 = m-l+1, size2 = r-m;

			struct element ls1[size1], ls2[size2];

			int k;
			for(k=0; k<size1; k++)
				ls1[k] = ls[k+l];
			for(k=0; k<size2; k++)
				ls2[k] = ls[k+m+1];

			struct element * ls3=(struct element *)malloc((size1+size2)*sizeof(struct element));
			merge(ls1, size1, ls2, size2, ls3);
			for(k=0; k<size1+size2; k++) 
				ls[k + l] = ls3[k];
			free(ls3);
			int e;
			end=&e;
			if(end-start>ans)
				ans=end-start;
		}
	}

}

int getSpace()
{
	return ans;
}
