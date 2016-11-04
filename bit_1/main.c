/*
 * main.c
 *
 *  Created on: 25 марта 2014 г.
 *      Author: ALTAIR
 */
#include <stdio.h>

int main() {
	int a;
	scanf("%x", &a);
	if(a & 1)
		printf("ma ");
	else
		printf("fe ");
	if(a & 2)
		printf("cl ");
	else
		printf("du ");
	if(a & (1 << 2))
		printf("ha ");
	else
		printf("nh ");
	if(a & (1 << 3))
		printf("tr ");
	else
		printf("sk ");
	switch((a & (3 << 4)) >> 4) {
	case 0:
		printf("bn ");
		break;
	case 1:
		printf("rd ");
		break;
	case 2:
		printf("bw ");
		break;
	case 3:
		printf("bk ");
		break;
	default:
		printf("error");
	}
	switch((a & (3 << 6)) >> 6) {
	case 0:
		printf("bu\n");
		break;
	case 1:
		printf("ge\n");
		break;
	case 2:
		printf("gy\n");
		break;
	case 3:
		printf("da\n");
		break;
	default:
		printf("error2");
	}
	return 0;
}
