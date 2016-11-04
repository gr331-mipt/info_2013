/*
 * main.c
 *
 *  Created on: 14 февр. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

long f(int G[100][100], int n) {
	int i, j;
	long sum = 0;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(G[i][j] != G[j][i])
				return -1;
			if(i != j)
				sum += G[i][j];
			else
				sum += 2 * G[i][j];
		}
	}
	return (long)sum / 2;
}

int main() {
	int i, j, n;
	int G[100][100];
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d", &G[i][j]);
		}
	}
	printf("%ld", f(G, n));
	return 0;
}
