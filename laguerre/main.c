/*
 * main.c
 *
 *  Created on: 19 нояб. 2013 г.
 *      Author: ALTAIR
 */
#include <stdlib.h>
#include <stdio.h>

typedef double my_type;

int laguerre_elem(my_type *a, int k, double x ) {
	a[k + 1] = (my_type) 1 / (k + 1) * ((2*k + 1 - x)*a[k] - k * a[k-1]);
	return 0;
}

int laguerre(my_type* a, int n, double x) {
	a[0] = 1;
	a[1] = 1 - x;
	int i;
	for(i = 1; i < n; i++){
		laguerre_elem( a, i, x);
	}
	return 1;
}

my_type* array_init( int n) {
	my_type* array = (my_type*) calloc(n + 1, sizeof(my_type));
	int i;
	for(i = 0; i <= n; i++) {
		array[i] = -1;
	}
	return array;
}

int array_destroy( my_type* array, int n) {
	free(array);
	return 0;
}

int main() {
	int n = 6;
	double x_min = -10;
	double x_max = 10;
	double dx = 0.5;
	double x;
	my_type* a = array_init(n);
	FILE* f_out = fopen("output.txt", "w");
	int i;
	for( i = -1; i <= n; i++)
		fprintf(f_out, "%d\t", i);
	for( x = x_min; x < x_max; x += dx) {
		laguerre(a, n, x);
		fprintf(f_out, "\n%.4lg\t", x);
		for(i = 0; i < n+1; i++)
			fprintf(f_out, "%.4lg\t", a[i]);
	}
	fclose(f_out);
	array_destroy(a, n);
	return 0;
}
