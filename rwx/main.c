/*
 * main.c
 *
 *  Created on: 25 марта 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

int f(char num) {
	num -= '0';
	if(num & (1 << 2))
		printf("r");
	else
		printf("-");
	if(num & (1 << 1))
		printf("w");
	else
		printf("-");
	if(num & 1)
		printf("x");
	else
		printf("-");
	return 0;
}

int main() {
	char a[5];
	scanf("%s", a);
	int i;
	for(i = 0; i < 3; i++) {
		f(a[i]);
	}
	return 0;
}
