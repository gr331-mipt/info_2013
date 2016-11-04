/*
 * main.c
 *
 *  Created on: 22 апр. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	long X;
	scanf("%ld", &X);
	long x = X / 8 + 1;
	char *a = (char*) calloc(x, sizeof(char));
	long i, j;
	for(i = 0; i < x; i++)
		a[i] = ~0;
	long n = 0;
	for(i = 2; i <= X; i++) {
		if(a[i / 8] & (1 << (i % 8))) {
			n++;
			for(j = i; j <= X; j += i) {
				a[j / 8] = a[j / 8] & ~(1 << (j % 8));
			}
		}
	}
	free(a);
	printf("%ld", n);
	return 0;
}
