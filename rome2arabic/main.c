/*
 * main.c
 *
 *  Created on: 13 марта 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <string.h>

int rome2arabic(char *n) {
	int i;
	int flag = 1;
	int N = 0;
	for(i = strlen(n); i >= 0; i--) {
		int digit = 0;
		switch(n[i]) {
		case 'I': digit = 1;
			break;
		case 'V': digit = 5;
			break;
		case 'X': digit = 10;
			break;
		case 'L': digit = 50;
			break;
		case 'C': digit = 100;
			break;
		case 'D': digit = 500;
			break;
		case 'M': digit = 1000;
			break;
		}
		if(flag < digit) {
			flag = digit;
		}
		if(flag > digit) {
			digit = -digit;
		}
		N += digit;
	}
	return N;
}

int main() {
	char n[4005];
	scanf("%s", n);
	printf("%d", rome2arabic(n));
	return 0;
}
