/*
 * sort_array.c
 *
 *  Created on: 09 сент. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b) {
	return (*(double*)a - *(double*)b);
}

int main() {
	unsigned N;
	scanf("%u", &N);
	double *array = (double*) calloc(N, sizeof(double));
	unsigned i;
	for(i = 0; i < N; i++) {
		scanf("%lg", array + i);
	}
	qsort(array, N, sizeof(double), compare);
	for(i = 0; i < N; i++) {
		printf("%lg ", array[i]);
	}
	free(array);
	return 0;
}
