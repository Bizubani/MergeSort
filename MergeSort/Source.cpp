#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

#define SIZE 8



int main(void) {
	int size = 8;
	int test[SIZE] = { 5,4,1,8,7,2,6,3 };
	int copy[SIZE] = { 5,4,1,8,7,2,6,3 };
	int inversions = 0;
	int i = 0;
	inversions = mergeSort(test, size);
	printf("%d\n", inversions);
	//printf("%d\n\n", inversions);
	for (i; i < size; i++) {
		printf("%d ", test[i]);
	}
	printf("\n");
	for (i = 0; i < size; i++) {
		printf("%d ", copy[i]);
	}
	getchar();

}//end of main