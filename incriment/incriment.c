/*
 * incriment.c
 *
 *  Created on: 09 сент. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

void inc(int *N) {
	(*N)++;
}

int main() {
	int N = 1;
	inc(&N);
	printf("%d", N);
	return 0;
}
