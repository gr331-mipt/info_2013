/*
 * main.c
 *
 *  Created on: 25 марта 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

int main() {
	int IP[4];
	int MA[4];
	scanf("%d.%d.%d.%d", IP, IP + 1, IP + 2, IP + 3);
	scanf("%d.%d.%d.%d", &MA[0], &MA[1], &MA[2], &MA[3]);
	int i;
	for(i = 0; i < 4; i++) {
		IP[i] = ((MA[i] & IP[i]) | (MA[i] ^ 255));
		printf("%d", IP[i]);
		if(i < 3)
			printf(".");
	}
	return 0;
}
