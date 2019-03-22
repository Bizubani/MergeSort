#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

#define SIZE 100000



int main(void) {
	

		FILE *fptr;
		int j = 0;
		long int count = 0;
		char sample[6] = { 0 };
		char* end = &sample[6];
		int* test = (int*)malloc(sizeof(int) * SIZE);

		if ((fptr = fopen("IntegerArrayweek1.txt", "r")) == NULL) {
			puts("Unable to open  \"IntegerArrayweek1.txt\"");
		}
		else {

			while (sample[j] != EOF) {
				sample[j] = fgetc(fptr);
				if (sample[j] == '\n' || sample[j] == '\t') {
					test[count] = strtol(sample, &end, 10);
					count++;
					j = 0;

					continue;
				}
				j++;

			}
			fclose(fptr);
		}


		long long inversions = 0;
		inversions = mergeSort(test, SIZE);
		printf("%lld\n", inversions);

		free(test);

		 getchar();
	

	
	
}//end of main