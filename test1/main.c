/*
 * main.c
 *
 *  Created on: 23 мая 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

int main() {
	const int c = 5;
	*(int *)(&c) = 10;
	printf("%d ", c);
	return 0;
}

