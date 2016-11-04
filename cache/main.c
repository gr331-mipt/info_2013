/*
 * main.c
 *
 *  Created on: 28 февр. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

int gcd(long x, long y){
	if(y == 0)
		return x;
	return gcd(y, x%y);
}

int main() {
	int a, b;
	int n, d;
	scanf("%d %d", &n, &d);
	int i, j, k;
	int amount = 0;
	for(i = 0; i < n; i++) {
		for(k = 0; k < n; k++) {
			long sum = 0;
			for(j = 0; j < n; j++) {
				a = gcd(i + 1, k + 1);
				b = gcd(n - k + 1, n - j + 1);
				sum += a * b;
			}
			if(!(sum % d) && sum)
				amount++;
		}
	}
	printf("%d", amount);
	return 0;
}
