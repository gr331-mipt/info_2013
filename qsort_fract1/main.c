/*
 * main.c
 *
 *  Created on: 13 дек. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>

struct Drob;
typedef struct Drob Drob;

struct Drob {
	long chisl;
	long znam;
};

int compare(const void *a1, const void *b1) {
	Drob *a = (Drob*)a1;
	Drob *b = (Drob*)b1;
	double A = (double)a->chisl / a->znam;
	double B = (double)b->chisl / b->znam;
	if(A != B)
		return ((A>B) ? 1 : -1);
	return a->znam - b->znam;
}

int main() {
	long n;
	scanf("%ld", &n);
	Drob *drob = (Drob*) calloc(n, sizeof(Drob));
	int i;
	for(i = 0; i < n; i++) {
		scanf("%ld/%ld", &(drob[i].chisl), &(drob[i].znam));
	}
	qsort(drob, n, sizeof(Drob), compare);
	for(i = 0; i < n; i++)
		printf("%ld/%ld ", drob[i].chisl, drob[i].znam);
	free(drob);
	return 0;
}
