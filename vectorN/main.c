#include <stdio.h>
#include <stdlib.h>

#define eps 1e-7
#define IS_ZERO(a) ((-eps < (a) && (a) < eps) ? 0 : (a))

typedef double my_type;

int strmin(my_type **a,  int n, int index1, int index2, double k) {
	int i;
	for(i = index2; i < n; i++) {
		a[index1][i] -= (k * a[index2][i]);
	}
	return 0;
}

int strchange(my_type **a, int n, int index1, int index2) {
	if(index1 < n && index2 < n) {
		my_type *w = a[index1];
		a[index1] = a[index2];
		a[index2] = w;
	}
	return 0;
}

my_type determinant(my_type **a, int n) {
	int i = 0;
	int j = 0;
	int i1;
	int KdetA = 1;
	for(i = 0; i < n - 1; i++) {					// i строка содержит элементы главной диагонали
		if(!a[i][i]) {								// если элемент на гл. диагонали 0, ищем строку ниже с ненулевым из этого столбца.
			for(i1 = i+1; i1 < n && !a[i1][i]; i1++);
			KdetA *= -1;							// так как одна строка опускается на (i - i1), а другая поднимается на (i - i1 - 1)
													// что всегда нечетное число
			strchange(a, n, i, i1);
			if(!a[i][i])							// если все элементы столбца ниже главной диагонали тоже 0, то определитель =0
				return 0;
		}
		for(j = i + 1; j < n; j++) {
			strmin(a, n, j, i, a[j][i] / a[i][i]);	//зануляем столбец ниже главной диагонали
		}
	}
	my_type detA = 1;
	for(i = 0; i < n; i++)
		detA *= a[i][i];
	return KdetA*detA;
}

int main() {
	int N;
	scanf("%d", &N);
	my_type **A = (my_type**) calloc(N, sizeof(my_type*));
	my_type **B = (my_type**) calloc(N, sizeof(my_type*));
	int i, j;
	for(i = 0; i < N; i++) {
		A[i] = (my_type*) calloc(N + 1, sizeof(my_type));
		B[i] = (my_type*) calloc(N    , sizeof(my_type));
		for(j = 0; j < N + 1; j++) {
			scanf("%lg", &A[i][j]);
		}
	}
	int column;
	for(column = 0; column < N + 1; column++) {
		for(i = 0; i < N; i++) {
			for(j = 0; j < column; j++) {
				B[i][j] = A[i][j];
			}
			for(j = column + 1; j < N + 1; j++) {
				B[i][j - 1] = A[i][j];
			}
		}
		int k = 1;
		if(column % 2) {
			k = -1;
		}
		printf("%.0lf ", k*determinant(B, N));
	}
	for(i = 0; i < N; i++) {
		free(A[i]);
		free(B[i]);
	}
	free(A);
	free(B);
	return 0;
}
