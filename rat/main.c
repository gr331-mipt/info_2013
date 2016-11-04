/*
 * main.c
 *
 *  Created on: 03 апр. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

#define MAX_LEN 64
#define eps 1e-5
#define IS_ZERO(a) ((-eps < (a) && (a) < eps) ? 1 : 0)
#define abs(a) ((a) < 0 ? -(a) : (a))

int rational(double n, char *rat) {
	int i;
	for(i = 0, n *= 2; i < MAX_LEN && n; i++, n *= 2) {
		if(n >= 1) {
			n -= 1;
			rat[i] = '1';
		}
		else
			rat[i] = '0';
	}
	rat[i] = '\0';
	return 0;
}

int main() {
	double n;
	char rat[MAX_LEN + 1];
	scanf("%lg", &n);
	//r - это дробная часть n
	double r = abs((long double)n - (long)n);
	rational(r, rat);
	printf("0.%s", rat);
	return 0;
}
