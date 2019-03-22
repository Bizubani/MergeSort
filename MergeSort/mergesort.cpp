/*Implementation of mergesort which can be used to sort an integer array  and also used to count inversions in an array*/
#include <stdlib.h>
#include <stdio.h>
#include "mergesort.h"



// do the merging of the split arrays in linear time, counting inversion
 int mergeAndCount( int* intArray, int leftSize, int rightSize) {
	 // runtime arrays to temporarily store the values to be sorted
	 int *left = (int*) malloc(sizeof(int) * leftSize); 
	 int *right = (int*) malloc(sizeof(int) * rightSize);

	 int length = leftSize + rightSize; 
	 int leftPosition = 0; // the position in the left array
	 int rightPosition = 0; // the position in the right array
	 int mergeCount = 0; // the current position in the sorted array
	 int inversionCount = 0; 

	 //fill out the left array. Runs from the beginning of the array to the the n/2 -1 position
	 for (leftPosition = 0; leftPosition < leftSize; leftPosition++) {
		 left[leftPosition] = intArray[leftPosition];
	 }
	 //fill out the right array. Runs from the n/2 position to the n -1 position, using the loop control varible from the above loop which was already in the correct position
	 for (rightPosition = 0; leftPosition < length; rightPosition++, leftPosition++) {
		 right[rightPosition] = intArray[leftPosition];
	 }

	 leftPosition = 0, rightPosition = 0; // reset the array variable to prepare for merging

	 // loop to merge the sub array values. loops through the length of the array
	 for (mergeCount; mergeCount < length; mergeCount++) {
		 // if the left array is exhausted, just copy over the values in the right array
		 if (leftPosition >= leftSize) {
			 intArray[mergeCount] = right[rightPosition];
			 rightPosition++;
			 continue;
		 }
		 // likewise, if the right array is exhausted, copy over the values in the left array
		 if (rightPosition >= rightSize) {
			 intArray[mergeCount] = left[leftPosition];
			 leftPosition++;
			 continue;
		 }
		 // if next element in the left array is smaller than the next element in the right array, copy the left element and move to the next element in the left sub array
		 if (left[leftPosition] < right[rightPosition]) {
			 intArray[mergeCount] = left[leftPosition];
			 leftPosition++;
		 }
		 /* if the next element in the right array is smaller than the next element in the left arrray, add the amount of remaining elements in the left sub array to the inversion count,
		 then move to the next element in the right array.*/
		 else if(right[rightPosition] < left[leftPosition]){
			 intArray[mergeCount] = right[rightPosition];
			 inversionCount += leftSize - leftPosition;
			 
			 rightPosition++;
		 }
	 }
	 free(left); // deallocate the memory for the left sub array
	 free(right); // deallocate the memory for the right sub array
	 

	 return inversionCount;
}

//return a pointer to the sorted array
long long mergeSort( int* intArray, int size) {
	int mergeAndCount(int* intArray, int leftSize, int rightSize);
	// keep count of the number of inversions
	long long inversionCount = 0;
	// check the trivial case of an array of size 1. If there is only one element, then it is already sorted.
	if (size <= 1) {
		return 0 ;
	}
	else {
		//determine the size of the two subarrays
		int leftSize = size / 2; // left side is 0 - (n/2 -1)
		int rightSize = size - leftSize; // right side is n/2 - n
		// the result of each recursive call and the final call to merge count is saved to inversionCount
		inversionCount += mergeSort( intArray, leftSize); // recurse on the left half of the array
		inversionCount += mergeSort( &intArray[leftSize], rightSize); // recurse on the right half of the array
		inversionCount += mergeAndCount(intArray, leftSize, rightSize);// merge the resulting array
	}
	// the result is passed up the stack to the earlier invocations.
	return inversionCount;
}