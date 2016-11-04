/*
 * main.c
 *
 *  Created on: 06 февр. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

typedef struct {
	int x;
	int y;
	int z;
} Vector;

int main() {
	Vector x, y, z;
	scanf("%d %d %d", &x.x, &x.y, &x.z);
	scanf("%d %d %d", &y.x, &y.y, &y.z);
	z.x = x.y * y.z - x.z * y.y;
	z.y = - (x.x * y.z - x.z * y.x);
	z.z = x.x * y.y - x.y * y.x;
	printf("%d %d %d", z.x, z.y, z.z);
	return 0;
}
