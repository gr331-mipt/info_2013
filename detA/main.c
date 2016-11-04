/*
 * main.c
 *
 *  Created on: 20 дек. 2013 г.
 *      Author: ALTAIR
 */

#include <stdlib.h>
#include <stdio.h>

typedef double my_type;

void array_print(my_type **a, int n) {
	int i,j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			printf("%lf ", a[i][j]);
		printf("\n");
	}
}

int strmin(my_type **a,  int n, int index1, int index2, double k) {
	int i;
	for(i = index2; i < n; i++) {									//вычитаем начиная с index2 , потому что считаем, что остальные столбцы до него уже 0
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

my_type det(my_type **a, int n) {
	int i = 0;
	int j = 0;
	int i1;
	//double k = 0;
	int KdetA = 1;
	for(i = 0; i < n - 1; i++) {					// i строка содержит элементы главной диагонали
		if(!a[i][i]) {								// если элемент на гл. диагонали 0, ищем строку ниже с ненулевым из этого столбца.
			for(i1 = i+1; i1 < n && !a[i1][i]; i1++);
			KdetA *= -1;							/* так как одна строка опускается на (i - i1), а другая поднимается на (i - i1 - 1)
													   что всегда нечетное число */
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
	int n;
	scanf("%d", &n);
	my_type **a = (my_type**) calloc(n, sizeof(my_type*));
	int i, j;
	for(i = 0; i < n; i++) {
		a[i] = (my_type*)calloc(n, sizeof(my_type));
		for(j = 0; j < n; j++)
			scanf("%lf", &a[i][j]);
	}
	my_type detA = det(a, n);
	//array_print(a, n);
	printf("\n%.0lf", detA);
	for(i = 0; i < n ; i++)
		free(a[i]);
	free(a);
	return 0;
}
