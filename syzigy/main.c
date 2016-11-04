/*
 * main.c
 *
 *  Created on: 13 апр. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a) > (b) ? (a) : (b))

struct Planet;
typedef struct Planet Planet;

struct Planet {
	long w;
	long y;
	double t0;//время до первой встречи с 0 планетой.
	double dt;//вреся до каждой следующей встречи с 0 планетой.
};

int compare(const void *a,const void *b) {
	return ((Planet*)a)->w - ((Planet*)b)->w;
}

long parad(Planet *a, const int n) {
	int i, j;
	double t = 0;
	/*for(j = 0; j < n - 1; j++) {
		for(i = j + 1; i < n; i++) {
			a[i].dt = abs(1296000 / (a[i].w - a[j].w));
			a[i].t0 = (a[j].y - a[i].y) / (a[i].w - a[j].w);
			if(a[i].t0 < 0) {
				a[i].t0 += 1296000 / max(a[i].w, a[j].w);
			}
			a[i].y = (long)(a[i].t0 * a[i].w + a[i].y) % 1296000;
			a[i].w = (long)(a[i].w  * a[i].dt );
		}
		t += a[j + 1].t0;
	}
	*/
	for(i = 1; i < n; i++) {
		a[i].dt = abs(1296000 / (a[i].w * a[i - 1].dt- a[i - 1].w)) * a[i - 1].dt;
		a[i].t0 = (a[i - 1].y - a[i].y) / (a[i].w * a[i - 1].dt - a[i - 1].w) * a[i - 1].dt;
		if(a[i].t0 < 0) {
			a[i].t0 += 1296000 / max(a[i].w * a[i - 1].dt, a[i - 1].w);
		}
		a[i].y  = (a[i].t0 * a[i].w + a[i].y);
		a[i].w  = (a[i].w  * a[i].dt);
	}
	a[n - 1].y %= 1296000;
	return a[n - 1].t0;
}

int main() {
	int n;
	scanf("%d", &n);
	Planet *a = (Planet*) calloc(n, sizeof(Planet));
	int i;
	for(i = 0; i < n; i++) {
		scanf("%ld %ld", &((a+i)->w), &((a+i)->y));
		a[i].dt = 0;
		a[i].t0 = 0;
	}
	qsort(a, n, sizeof(Planet), compare);
	long t = parad(a, n);
	//if(t > 0)
		printf("%ld %ld", t, a[n - 1].y);
	//else
		//printf("-1");
	free(a);
	return 0;
}
