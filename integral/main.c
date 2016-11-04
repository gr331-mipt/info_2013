/*
 * main.c
 *
 *  Created on: 22 нояб. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <math.h>
#define e 0.00001
#define SQR(a) ((a) * (a))

int main() {
    double a, b;
    scanf("%lg %lg", &a, &b);
    if(a == b)
    	printf("0");
    else {
        char k = 1;
        if(a > b){
            double c = b;
            b = a;
            a = c;
            k = -1;
        }
        a = a * M_PI / 180;
        b = b * M_PI / 180;
        double i;
        double integral = 0;
        for( i = a; i < b ; i += e){
            integral += ( sin(SQR(i)) + sin(SQR(i + e)) ) / 2 * e;
        }
        if(k == -1)
        	integral = -integral;
        printf("%.6lg", integral);
    }
    return 0;
}
