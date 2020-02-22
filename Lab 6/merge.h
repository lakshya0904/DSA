#include<stdio.h>
#include<stdlib.h>
#include "element.h"
void merge(struct element * L, int n1, struct element * R, int n2, struct element * ls);
void mergeSort(struct element * ls, int l, int r);
int getSpace();