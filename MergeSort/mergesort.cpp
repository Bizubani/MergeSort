/*Implementation of mergesort which can be used to sort an integer array  and also used to count inversions in an array*/
#include <stdlib.h>
#include "mergesort.h"


// do the merging of the split arrays in linear time, counting inversion
 int mergeAndCount( int* intArray, int leftSize, int rightSize) {
	 int *left = (int*) malloc(sizeof(int) * leftSize);
	 int *right = (int*) malloc(sizeof(int) * rightSize);
	 int length = leftSize + rightSize;
	 int leftPosition = 0;
	 int rightPosition = 0;
	 int mergeCount = 0;
	 int inversionCount = 0;

	 for (leftPosition = 0; leftPosition < leftSize; leftPosition++) {
		 left[leftPosition] = intArray[leftPosition];
	 }
	 for (rightPosition = 0; leftPosition < length; rightPosition++, leftPosition++) {
		 right[rightPosition] = intArray[leftPosition];
	 }

	 leftPosition = 0, rightPosition = 0;

	 for (mergeCount; mergeCount < length; mergeCount++) {
		 if (leftPosition >= leftSize) {
			 intArray[mergeCount] = right[rightPosition];
			 rightPosition++;
			 continue;
		 }
		 if (rightPosition >= rightSize) {
			 intArray[mergeCount] = left[leftPosition];
			 leftPosition++;
			 continue;
		 }
		 if (left[leftPosition] < right[rightPosition]) {
			 intArray[mergeCount] = left[leftPosition];
			 leftPosition++;
		 }
		 else if(right[rightPosition] < left[leftPosition]){
			 intArray[mergeCount] = right[rightPosition];
			 inversionCount += leftSize - leftPosition;
			 rightPosition++;
		 }
	 }
	 free(left);
	 free(right);
	 return inversionCount;
}

//return a pointer to the sorted array
int mergeSort( int* intArray, int size) {
	int mergeAndCount(int* intArray, int leftSize, int rightSize);
	// keep count of the number of inversions
	int inversionCount = 0;
	// check the trivial case of an array of size 1. If there is only one element, then it is already sorted.
	if (size <= 1) {
		return 0 ;
	}
	else {
		//determine the size of the two subarrays
		int leftSize = size / 2; // left side is 0 - (n/2 -1)
		int rightSize = size - leftSize; // right side is n/2 - n
		inversionCount += mergeSort( intArray, leftSize); // recurse on the left half of the array
		inversionCount += mergeSort( &intArray[leftSize], rightSize); // recurse on the right half of the array
		inversionCount += mergeAndCount(intArray, leftSize, rightSize);// merge the resulting array
	}

	return inversionCount;
}