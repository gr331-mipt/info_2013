/*
 * main.c
 *
 *  Created on: 03 марта 2014 г.
 *      Author: ALTAIR
 */

#include <string.h>
#include <stdio.h>

#define BASE 2

double fract(char *s) {
	double mul;
	double fract_part = 0;
	int i;
	for(i = 0, mul = 0.5; s[i] != '\0'; i++, mul /= 2) {
		fract_part += (s[i] - '0') * mul;
	}
	return fract_part;
}

int integ(char *s) {
	int i;
	int int_part = 0;
	for(i = 0; s[i] != '\0'; i++) {
		int_part = int_part * BASE + (s[i] - '0');
	}
	return int_part;
}

int main() {
	char s[35];
	scanf("%s", s);
	int i;
	double num = 0;
	for(i = 0;s[i] != '.' && s[i] != '\0'; i++);
	if(s[i] != '\0')
		num += fract(s + i + 1);
	s[i] = '\0';
	num += integ(s);
	printf("%.12lf\n", num);
	return 0;
}
