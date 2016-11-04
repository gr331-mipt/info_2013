/*
 * main.c
 *
 *  Created on: 31 окт. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

int known[100][100];

int main() {
	int n;
	for( n = 0; n < 100; n++)
		known[n] = -1;
	scanf("%d", &n);
	printf("%d", p(n));
	return 0;
}
