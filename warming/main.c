/*
 * main.c
 *
 *  Created on: 13 февр. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

#include <stdio.h>

#define eps 1e-7
#define IS_EQUALLY(a,b) (-eps < (a - b) && (a - b) < eps ? 1 : 0)

double f() {
	double q, m2;
	scanf("%lg %lg", &q, &m2);
	double Q, m, t0;
	scanf("%lg %lg", &m, &t0);
	double c1;
	scanf("%lg", &c1);
	double A, t1;
	scanf("%lg %lg", &A, &t1);
	double c2;
	scanf("%lg", &c2);
	double L, t2;
	scanf("%lg %lg", &L, &t2);
	Q = q * m2 * 1000;
	L *= 1000;
	A *= 1000;
	if((!A && !t1 && c1) || t0 < t1) {
		double Q1 = c1 * m * (t1 - t0);
		if(Q < Q1 || !A) {
			return Q / (c1 * m) + t0;
		}
		t0 = t1;
		Q -= Q1;
	}
	if(t1 == t0)
		Q -= A * m;
	if(Q <= 0)
		return t0;
	else {
		double Q2 = c2 * m * (t2 - t0);
		if((Q < Q2 || (!L && !t2)) && c2 != 0) {
			return Q / (c2 * m) + t0;
		}
		t0 = t2;
		Q -= Q2;
	}
	if(Q >= L * m)
		return -1;
	return t0;
}

int main() {
	//input data
	printf("%lg", f());
	return 0;
}
