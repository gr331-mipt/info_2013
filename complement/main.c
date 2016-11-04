/*
 * main.c
 *
 *  Created on: 26 марта 2014 г.
 *      Author: ALTAIR
 */

#define MAX_LEN 8

#include <stdio.h>

int main() {
	int a;
	scanf("%d", &a);
	char s[MAX_LEN + 1];
	int i;
	for(i = 0; i < MAX_LEN; i++) {
		s[MAX_LEN - i - 1] = ((a & (1 << i)) >> i) + '0';
	}
	printf("%s\n", s);
	return 0;
}
