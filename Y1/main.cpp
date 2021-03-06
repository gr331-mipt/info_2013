/*
 * main.cpp
 *
 *  Created on: 27 апр. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <iostream>

long double Ryad(const long x) {
	long n;
	long double a = 0;
	for(n = 1; n <= x; n++) {
		a += (long double)1 / (n * n + 2 * n);
	}
	return a;
}

int main() {
	long x;
	scanf("%ld", &x);
	std::cout << Ryad(x);
	return 0;
}
