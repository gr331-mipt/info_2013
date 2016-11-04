/*
 * main.c
 *
 *  Created on: 22 нояб. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    double a[1000];
    scanf("%d\n", &n);
    int i;
    double m = 0;
	double d = 0;
    for(i = 0; i < n; i++){
        scanf("%lg", &a[i]);
        m += a[i];
    }
    m = m / n;
    for(i = 0; i < n; i++){
        d += ( a[i] - m )*( a[i] - m );
    }
    d = sqrt( d / n );
    printf("%lg %lg", m, d);
    return 0;
}
