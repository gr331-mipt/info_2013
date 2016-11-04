/*
 * main.c
 *
 *  Created on: 12 янв. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>

void output(int **a, int n) {
	int i,j;
	for(i = 0; i < n + 1; i++) {
		for(j = 0; j < i + 1; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}

}

int stirling2(int n, int k) {
	int stirling;
	int **a = (int**) calloc(n + 1, sizeof(int*));
	int i,j;
	for(i = 0; i < n + 1; i++) {
		a[i] = (int*) calloc(i + 2, sizeof(int));
	}
	a[0][0] = 1;
	a[0][1] = 0;
	for(i = 1; i < n + 1; i++) {
		a[i][0] = 0;
		for(j = 1; j < i + 1; j++) {
			a[i][j] = a[i-1][j-1] + j * a[i - 1][j];
		}
		a[i][i + 1] = 0;
	}
	stirling = a[n][k];
	//output(a, n);
	for(i = 0; i < n + 1; i++)
		free(a[i]);
	free(a);
	return stirling;
}

int stirling1(int n, int k) {
	int stirling;
	int **a = (int**) calloc(n + 1, sizeof(int*));
	int i,j;
	for(i = 0; i < n + 1; i++) {
		a[i] = (int*) calloc(i + 2, sizeof(int));
	}
	a[0][0] = 1;
	a[0][1] = 0;
	for(i = 1; i < n + 1; i++) {
		a[i][0] = 0;
		for(j = 1; j < i + 1; j++) {
			a[i][j] = a[i-1][j-1] - (i - 1) * a[i - 1][j];
		}
		a[i][i + 1] = 0;
	}
	stirling = a[n][k];
	//output(a, n);
	for(i = 0; i < n + 1; i++)
		free(a[i]);
	free(a);
	return stirling;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if(!n && !k)
		printf("1");
	else {
		if(!k || k > n)
			printf("0");
		else {
			printf("%d", stirling2(n,k));
		}
	}
	return 0;
}
