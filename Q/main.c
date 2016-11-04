/*
 * main.c
 *
 *  Created on: 25 марта 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM_LEN 3
#define MUL_LEN 7

int square(const int *num, int *mul, int base) {
	int i, j;
	for(i = 0; i < MUL_LEN; i++) {
		mul[i] = 0;
	}
	int buf = 0;
	for(i = NUM_LEN - 1; i >= 0; i--) {
		buf = 0;
		for(j = NUM_LEN - 1; j >= 0; j--) {
			mul[MUL_LEN - (NUM_LEN - i - 1) - (NUM_LEN - j - 1) - 1] += num[i] * num [j] + buf;
			buf = mul[MUL_LEN - (NUM_LEN - i - 1) - (NUM_LEN - j - 1) - 1] / base;
			mul[MUL_LEN - (NUM_LEN - i - 1) - (NUM_LEN - j - 1) - 1] %= base;
		}
		mul[MUL_LEN - NUM_LEN - (NUM_LEN - i)] += buf;
	}
	for(i = 0; i < NUM_LEN; i++) {
		if(num[i] != mul[MUL_LEN - NUM_LEN + i])
			return 0;
	}
	return 1;
}
int f(int *num, int *mul, int base) {
	while(num[0] > 0) {
		for(num[2] = base - 1; num[2] >= 0; num[2]--) {
			if(square(num, mul, base))
				return 1;
		}
		num[1] --;
		if(num[1] < 0) {
			num[0] --;
			num[1] = base - 1;
		}
	}
	return 0;
}

int main() {
	int num[NUM_LEN];
	int mul[MUL_LEN];
	int base;
	scanf("%d", &base);
	int i;
	for(i = 0; i < NUM_LEN; i++) {
		num[i] = base - 1;
	}
	f(num, mul, base);
	long Num = 0;
	int factor = 1;
	for(i = 0; i < NUM_LEN; i++, factor *= base) {
		Num += factor * num[NUM_LEN - 1 - i];
	}
	printf("%ld\n", Num);
	return 0;
}
