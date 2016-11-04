/*
 * main.c
 *
 *  Created on: 22 нояб. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define assert(cond) \
if (!(cond)) {\
    printf("All gone bad: %s, file: %s, line: %d\n", #cond, __FILE__, __LINE__);\
    abort();\
    }

int sort( int array[], const int low, const int high){
	assert(array != NULL);
	assert(low >= 0);
	assert(high >= 0);
	assert(low <= high);
	int i = low;
	int j = high;
	float w = 0;
	float m = array[(i + j) / 2];
	do{
		while( array[i] < m && i < high) {
			assert(low <= i && i < high);
			i++;
		}
		while( array[j] > m && j > low) {
			assert(low < j && j <= high);
			j--;
		}
		if(i <= j) {
			assert(low <= i && i <= high);
			assert(low <=j && j <= high);
			w = array[i];
			array[i] = array[j];
			array[j] = w;
			i++;
			j--;
		}
	} while (i < j);
	if(low < j)
		sort(array , low, j );
	if(i   < high)
		sort(array , i  , high);
	return 0;
}

void array_print(int *array, const int n) {
	int i;
	printf("\n%d\n", n);
	for(i = 0; i < n; i++)
		printf("%d ", array[i]);
}

int main() {
	srand(time(0));
	int n = rand() % 20;
	int* array = (int*) calloc(n, sizeof(int));
	int i;
	for(i = 0; i < n; i ++) {
		array[i] = (rand() % 100)*1000 + i;
		/* такая задача элемента массива, чтобы действительно удостовериться,
		 * что он сортируется. последние 2 разряда показывают номер элемента
		 * в начальном массиве
		 * */
	}
	array_print(array, n);
	sort(array, 0, n - 1);
	array_print(array, n);
	free(array);
	return 0;
}
