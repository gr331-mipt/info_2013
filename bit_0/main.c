/*
 * main.c
 *
 *  Created on: 25 марта 2014 г.
 *      Author: ALTAIR
 */
#include <stdio.h>

int main() {
	int a, b;
	scanf("%x %x", &a, &b);
	a = a ^ b;
	printf("%x", a);
	return 0;
}
