/*
 * main.c
 *
 *  Created on: 03 нояб. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int m;
	int s;
	int num;
} athlete ;

int changeVal(const void *a, const void *b){
	const athlete *a1 = (athlete*) a;
	const athlete *b1 = (athlete*) b;
	return (a1->s - b1->s);
}

int main() {
	int n;
	int m,s;
	scanf("%d", &n);
	athlete* list = (athlete*) calloc(n, sizeof(athlete));
	int i;
	for(i = 0; i < n; i++){
		scanf("%d %d", &m, &s);
		list[i].m = m;
		list[i].s = s;
		list[i].num = i+1;
	}
	qsort( list, n, sizeof(athlete), changeVal);
	int summMass = 0;
	for(i = 0; i < n; i++) {
		if(list[i].s >= summMass){
			printf("%d: %d %d\n",list[i].num, list[i].m, list[i].s);
			summMass += list[i].m;
		}
	}
	free(list);
	return 0;
}
