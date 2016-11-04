/*
 * main.c
 *
 *  Created on: 22 апр. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>

#define BITS(a) ((1 << ((a) % 8)))

int main() {
	int v;
	long n;
	scanf("%d", &v);
	scanf("%ld", &n);
	long virus;
	int i;
	long j;
	long k;
	char *a = (char *) calloc(n / 8 + 1, sizeof(char));
	long kol = 0;
	for(i = 0; i < v; i++) {
		scanf("%ld", &virus);
		for(k = virus, j = virus; j < n; j += k, k++){
			if(!(a[j / 8] & BITS(j)))
				kol++;
			a[j / 8] = a[j / 8] | BITS(j);
		}
	}
	printf("%ld\n", kol);
	free(a);
	return 0;
}
