/*
 * main.c
 *
 *  Created on: 12 марта 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define digit(a) (((a) != '$') ? ((a) - '0')  : -1)

int fill(char *a) {
	char str[1001];
	scanf("%s", str);
	strcpy(a + 1, str);
	return 1;
}

char *stradd(char *a, char *b) {
	int dl = strlen(a) - strlen(b);
	if(dl < 0) {
		char *w = a;
		a = b;
		b = w;
		dl = -dl;
	}
	int i;
	int c = 0;
	for(i = strlen(a) - 1; i >= 0; i--) {
		int sum_digit = digit(a[i]) + c;
		if(i - dl >= 0) {
			sum_digit += digit(b[i - dl]);
		}
		if( sum_digit > 1) {
			c = sum_digit / 2;
			sum_digit -= 3;
		}
		else {
			if(sum_digit < -1) {
				c = sum_digit / 2;
				sum_digit += 3;
			}
			else {
				c = 0;
			}
		}
		if(sum_digit < 0) {
			a[i] = '$';
		}
		else {
			a[i] = sum_digit + '0';
		}
	}
	for(i = 0; a[i] == '0' && a[i] != '\0'; i++);
	if(!a[i] && i > 0)
		return a + i - 1;
	return a+i;
}

int main() {
	char a[1005] = "0";
	char b[1005] = "0";
	fill(a);
	fill(b);
	printf("%s", stradd(a, b));
	return 0;
}
