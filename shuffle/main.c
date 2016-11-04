/*
 * main.c
 *
 *  Created on: 22 нояб. 2013 г.
 *      Author: ALTAIR
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int compare(const void *a, const void *b) {
	return rand()%100 - 50;
}

int main() {
	srand(time(0));
	int n;
	scanf("%d", &n);
	int i;
	int *data = (int*) calloc(n, sizeof(int));
	for(i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	qsort(data, n, sizeof(int), compare);
	for(i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}
	free(data);
	return 0;
}
