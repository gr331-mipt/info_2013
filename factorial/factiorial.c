/*
 * factiorial.c
 *
 *  Created on: 09 сент. 2014 г.
 *      Author: ALTAIR
 */
#include <stdio.h>

int main() {
	unsigned N;
	printf("input number:");
	scanf("%u", &N);
	unsigned N1 = N;
	unsigned long F = 1;
	for(; N > 0; F *= N, N--);
	printf("%u!=%lu",N1, F);
	return 0;
}
