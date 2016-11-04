/*
 * main.c
 *
 *  Created on: 16 нояб. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <string.h>

int main() {
	char a[100];
	char b[100];
	char c[10000];
	int i,j;
	for(i = 0; i < sizeof(c) -1; i++)
		c[i] = 0;
	scanf("%s %s", a, b);
	int n1 = strlen(a);
	int n2 = strlen(b);
	for(i = n2 ; i > 0; i--) {
		for(j = n1; j > 0; j--) {
			int mul = ((int)b[i - 1] - (int)'0') * ((int)a[j - 1] - (int)'0');
			c[i + j - 1] += mul % 10;
			c[i + j - 2] +=(int) mul / 10 + c[i + j - 1] / 10;
			c[i + j - 1] = c[i + j - 1] % 10;
		}
	}
	printf("answer:\n");
	/*for(i = n1 + n2; i > 0; i--)
		if(c[i] >= 10) {
			c[i - 1] += c[i] / 10;
			c[i] = c[i] % 10;
		}*/
	long sum1 = 0;
	for(i = 0; i < n1 + n2; i++) {
		sum1 +=c[i];
	}
	printf("\n%ld", sum1);
	return 0;
}
