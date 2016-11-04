/*
 * main.c
 *
 *  Created on: 08 нояб. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>

#define eps 1e-8
#define IS_ZERO(x) (-eps < (x) && (x) < eps)

typedef struct {
	int x;
	int y;
} Point;

int length(Point *a) {
	return (a->x)*(a->x) + (a->y)*(a->y);
}

int compare (const void *a1, const void *b1) {
	Point *a = (Point*) a1;
	Point *b = (Point*) b1;
	double lenA = length(a);
	double lenB = length(b);
	if(lenA - lenB == 0){
		if(a->x - b->x == 0){
			return a->y - b->y;
		}
		else {
			return a->x - b->x;
		}
	}
	else {
		return lenA - lenB;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	Point point[1000];
	int i;
	for(i = 0; i < n; i++) {
		scanf("%d %d", &point[i].x, &point[i].y);
	}
	qsort(point, n, sizeof(Point), compare);
	for(i = 0; i < n; i++) {
		printf("%d %d\n", point[i].x, point[i].y);
	}
	return 0;
}
