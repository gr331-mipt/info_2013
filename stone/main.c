/*
 * main.c
 *
 *  Created on: 31 марта 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

int f(const int x, int *v, int *n) {
	for(*v = 8; *v > 1; *v = *v >> 1) {
		int i = 0;
		int v1 = *v + 1;
		for(i = 1; x != v1 && v1 > 0 && i <= 8; i *= 2) {
			v1 = v1 << 1;
		};
		if(v1 > 0 && i <= 8) {
			*n = i;
			return 1;
		}
	}
	return -1;
}

int main() {
	int x, n, v;
	scanf("%d", &x);
	if(f(x, &v, &n) != -1) {
		printf("%d %d\n", v, n);
	}
	else
		printf("-1\n");
	return 0;
}
