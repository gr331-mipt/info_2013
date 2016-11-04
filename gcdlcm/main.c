/*
 * main.c
 *
 *  Created on: 30 окт. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

long gcd(long x, long y){
	if(y == 0)
		return x;
	return gcd(y, x%y);
}

long lcm(long a, long b){
	return a*b/gcd(a,b);
}

int main() {
	int n = 0;
	int i = 0;
	long a = 0;
	long GCD = 0;
	long LCM = 0;
	scanf("%d %ld", &n, &GCD);
	LCM = GCD;
	for(i = 1; i < n; i++){
		scanf("%ld", &a);
		GCD = gcd(GCD, a);
		LCM = lcm(LCM, a);
	}
	printf("%ld %ld", GCD, LCM);
	return 0;
}
