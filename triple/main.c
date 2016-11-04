/*
 * main.c
 *
 *  Created on: 21 февр. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <string.h>

long long toTen(int radix, char *number) {
	int i;
	long mul;
	long long NumInTen = 0;
	for(i = strlen(number) - 1, mul = 1; i >= 0; i--, mul *= radix) {
		int digit = 0;
		if('0' <= number[i] && number[i] <= '9') {
			digit = number[i] - '0';
		}
		else {
			if('a' <= number[i] && number[i] <= 'z') {
				digit = number[i] - 'a';
			}
			else {
				if('A' <= number[i] && number[i] <= 'Z')
					digit = number[i] - 'A';
			}
		}
		NumInTen += mul*digit;
	}
	return NumInTen;
}

int main() {
	char number[100];
	scanf("%s", number);
	printf("%ld", (long) toTen(3, number));
	return 0;
}
