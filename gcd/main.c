/*
 * main.c
 *
 *  Created on: 13 дек. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

long gcd(long x, long y){
	if(y == 0)
		return x;
	return gcd(y, x%y);
}

long lcm(long a, long b){
	return a * b / gcd(a, b);
}

int main() {
	FILE *f_in = fopen("input.txt", "r");
	if(f_in != NULL) {
		long a, b;
		fscanf(f_in, "%ld %ld", &a, &b);
		fclose(f_in);
		FILE *f_out = fopen("output.txt", "w");
		fprintf(f_out, "%ld", lcm(a , b));
	}
	else {
		perror("input.txt");
	}
	return 0;
}
