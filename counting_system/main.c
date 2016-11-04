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
		int digit;
		if('0' <= number[i] && number[i] <= '9') {
			digit = ((int)number[i] - (int)'0');
		}
		else {
			if('a' <= number[i] && number[i] <= 'z') {
				digit = ((int)number[i] - (int)'a') + 10;
			}
			else {
				if('A' <= number[i] && number[i] <= 'Z')
					digit = ((int)number[i] - (int)'A') + 10;
			}
		}
		NumInTen += mul*digit;
	}
	return NumInTen;
}

int intoTen(int radix, long long NumInTen, char *number) {
	if(!NumInTen) {
		number = "0";
		return 0;
	}
	number[0] = '\0';
	int len;
	for(len = 0; NumInTen > 0; NumInTen = (long long) NumInTen / radix, len++) {
		int digit = NumInTen % radix;
		char c;
		if(digit < 10) {
			c = (char)(digit + (int)'0');
		}
		else {
			c = (char)(digit + (int)'A' - 10);
		}
		sprintf(number, "%s%c", number, c);
	}
	int i;
	for(i = 0; i < len / 2; i++) {
		char c = number[i];
		number[i] = number[len - i - 1];
		number[len - i - 1] = c;
	}
	return 0;
}

int main() {
	int radix_old, radix_new;
	char number[1000];
	scanf("%d", &radix_old);
	scanf("%s", number);
	scanf("%d", &radix_new);
	long long NumInTen = toTen(radix_old, number);
	intoTen(radix_new, NumInTen, number);
	printf("%s", number);
	return 0;
}
