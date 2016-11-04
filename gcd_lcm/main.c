/*
 * main.c
 *
 *  Created on: 30 окт. 2013 г.
 *      Author: ALTAIR
 */

long gcd(long x, long y){
	if(y == 0)
		return x;
	return gcd(y, x%y);
}

long lcm(long LCM, long a, long GCD){
	return a*LCM/GCD;
}

int main() {
	int n = 0;
	int i = 0;
	long a = 0;
	long a1 = 0;
	long GCD = 0;
	long LCM = 0;
	scanf("%ld", &a);
	for(i = 1; i < n; i++){
		a1 = a;
		scanf("%ld", &a);
		GCD = gcd(GCD, a);
		LCM = lcm(LCM, a, GCD);
	}
	printf("%ld %ld", GCD, LCM);
	return 0;
}
