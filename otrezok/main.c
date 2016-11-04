/*
 * main.c
 *
 *  Created on: 11 дек. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int xL;
	int xR;
} Otr;

int compare(const void *a1, const void *b1) {
	Otr a = *(Otr*)a1;
	Otr b = *(Otr*)b1;
	if(b.xL == a.xL)
		return a.xR - b.xR;
	return a.xL - b.xL;
}

int main () {
	int n;
	int s;
	scanf("%d %d", &n, &s);
	Otr *otr = (Otr*) calloc(n, sizeof(Otr));
	int i;
	for(i = 0; i < n; i++) {
		scanf("%d %d", &otr[i].xL, &otr[i].xR);
	}
	qsort(otr, n, sizeof(Otr), compare);
	/*
	for(i = 0; i < n; i++) {
			printf("%d %d\n", otr[i].xL, otr[i].xR);
	}
	*/
	int R = otr[0].xR;
	int Rmax = R;
	int Imax = 0;
	int number = 0;
	printf("Answer:\n");
	if(otr[0].xL > 0)
		printf("NO");
	else {
		i = 0;
		while( i < n && R < s) {
			for( ;i < n && otr[i].xL <= R; i++)
				if(Rmax < otr[i].xR) {
					Rmax = otr[i].xR;
					Imax = i;
				}
			number++;
			R = Rmax;
			printf("%d %d\n", otr[Imax].xL, otr[Imax].xR);
		}
		if(Rmax < s)
			printf("NO");
		else
			printf("number: %d", number);
	}
	/*
	for(i = 0; i < n; i++) {
		printf("%d %d\n", otr[i].xL, otr[i].xR);
	}
	*/
	free(otr);
	return 0;
}
