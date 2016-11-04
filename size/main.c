/*
 * main.c
 *
 *  Created on: 27 марта 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char str[20];
	int done = 0;
	int i;
	gets(str);
	if(!strcmp(str, "double")) {
		double a = 1;
		done = 1;
		long long b = 1;
		for(i = 0; a == b; i++) {
			a = 2 * a + 1;
			b = 2 * b + 1;
		}
	}
	if(!done && !strcmp(str, "float")) {
		float a = 1;
		done = 1;
		long long b = 1;
		for(i = 0; a == b; i++) {
			a = 2 * a + 1;
			b = 2 * b + 1;
		}
	}
	if(!done && !strcmp(str, "long double")) {
		long double a = 1;
		long long b = 1;
		for(i = 0; a == b; i++) {
			a = 2 * a + 1;
			b = 2 * b + 1;
		}
	}
	printf("%d", i);
	return 0;
}
