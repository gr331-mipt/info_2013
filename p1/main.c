/*
 * main.c
 *
 *  Created on: 16 мая 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

int main() {
	double t1 = 10;
	double t2 = 5;
	__asm {
		lfd t1
		fld t2
		fsub
		fstp t1
	}
	printf("%lf", t1);
	return 0;
}
