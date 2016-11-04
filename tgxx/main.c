/*
 * main.c
 *
 *  Created on: 28 окт. 2013 г.
 *      Author: user
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define eps 1e-10
#define eps1 1e-7
#define sred(a,b) ((double)((a)+(b))/2)
#define IS_ZERO(a) ((-eps1 < (a) && (a) < eps1) ? 0 : a)
#define func(a) (tan(a) - (a))

int check(double Xa, double Xb){
	if(func(Xa) > 0 || func(Xb) < 0){
			printf("-1");
			return 1;
	}
	return 0;
}

int main(){
	double Xa = 0;
	double Xb = 0;
	long iteration = 0;
	scanf("%lg %lg", &Xa, &Xb);
	if(check(Xa, Xb) == 0){
		while( Xb - Xa > eps){
			if(func(sred(Xa, Xb))> 0){
				Xb = sred(Xa, Xb);
			}
			else {
				Xa = sred(Xa, Xb);
			}
			iteration++;
		}
		printf("%.10lf\n%ld", IS_ZERO(sred(Xa, Xb)), iteration);
	}
	return 0;
}
