/*
 * main.c
 *
 *  Created on: 17 янв. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define g 9.8
#define sqr(a) (a)*(a)

int main() {
	double h, t;
	scanf("%lg %lg", &h, &t);
	if(h == 0) {
		printf("0");
		return 0;
	}
	double fall_time = sqrt((double)2 * h / g);
	//printf("fall_time = %lg\n", fall_time);
	//printf("time = %lg\n", t);
	while(t > fall_time)
		t -= 2 * fall_time;
	double newH;
	newH = h - (double)g * sqr(t) / 2;
	printf("%lg", newH);
	return 0;
}
