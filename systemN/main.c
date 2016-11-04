/*
 * main.c
 *
 *  Created on: 29 дек. 2013 г.
 *      Author: ALTAIR
 */

/*
 * main.c
 *
 *  Created on: 29 дек. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>

#define eps 1e-8
#define IS_ZERO(a) ( -eps < (a) && (a) < eps ? 0 : (a))

typedef double mytype;

int strmin(mytype **a,  int n2, int index1, int index2, double k) {
	int i;
	for(i = 0; i < n2; i++) {
		a[index1][i] -= (k * a[index2][i]);
	}
	return 0;
}

int strmul(mytype **matrix, int index, int n2, double k) {
	int i;
	for(i = 0; i < n2; i++) {
		matrix[index][i] *= k;
	}
	return 1;
}

int strchange(mytype **a, int n, int index1, int index2) {
	if(index1 < n && index2 < n) {
		mytype *w = a[index1];
		a[index1] = a[index2];
		a[index2] = w;
	}
	return 0;
}

mytype **matrix_initialize(const int n) {
	mytype **matrix = (mytype **) calloc(n, sizeof(mytype*));
	int i;
	for(i = 0; i < n; i++)
		matrix[i] = (mytype*) calloc(n + 1, sizeof(mytype));
	return matrix;
}

void matrix_output(mytype **matrix, int n1, int n2) {
	printf("matrix:\n");
	int i, j;
	for(i = 0; i < n1; i++) {
		for(j = 0; j < n2; j++)
			printf("%2.2lf ", matrix[i][j]);
		printf("\n");
	}
}

void matrix_answer(mytype **matrix, int n1) {
	int i;
	for(i = 0; i < n1; i++)
		printf("%lg\n", IS_ZERO(matrix[i][n1]));
}

void matrix_invertible(mytype **matrix, int n1) {
	int i,j;
	for(i = 0; i < n1; i++) {
		for(j = n1; j < 2 * n1; j++) {
			printf("%lg ", IS_ZERO(matrix[i][j]));
		}
		printf("\n");
	}
}

void matrix_destroy(mytype **matrix, int n1) {
	int i;
	for(i = 0; i < n1; i++)
		free(matrix[i]);
	free(matrix);
}

int matrix_identity(mytype **matrix, int n1, int n2) {
	int i, j, j1;
	int KdetA = 1;
	mytype k;
	for(i = 1; i < n1; i++) {
		for(j = 0; j < i; j++) {
			for(j1 = j + 1; !IS_ZERO(matrix[j][j]) && j1 <= i ; j1++) {
				KdetA *= (j1 - j % 2 == 0 ? 1 : -1);
				strchange(matrix, n1, j, j1);
			}
			if(matrix[j][j]) {
				k = matrix[i][j] / matrix[j][j];
				strmin(matrix, n2, i, j, k);
			}
		}
	}
	mytype detA = 1;
	for(i = 0; i < n1; i++)
		detA *= matrix[i][i];
	if(! IS_ZERO(detA))
		return 0;
	for(i = 0; i < n1; i++) {
		strmul(matrix, i, n2, (double)1 / matrix[i][i]);
	}
	for(i = 0; i < n1 - 1; i++) {
		for(j = i + 1; j < n1; j++) {
			strmin(matrix, n2, i, j, matrix[i][j]);
		}
	}
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	mytype **a = matrix_initialize(n);
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n + 1; j++)
			scanf("%lg", &a[i][j]);
	}
	if(!matrix_identity(a, n, n + 1))
		printf("NO");
	else
		matrix_answer(a, n);
	matrix_destroy(a, n);
	return 0;
}
