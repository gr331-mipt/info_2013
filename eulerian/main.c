/*
 * main.c
 *
 *  Created on: 14 февр. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include "list.h"

int rec(Graph* G) {
	if(G->visited)
		return 0;
	G->visited = 1;
	List* list;
	for(list = G->neighbour; list; list = list->prev) {
		printf("1");
		if(!rec(list->Value))
			return 0;
	}
	return 1;
}

int main() {
	int G[100][100];
	int i, j, n;
	int rez = 1;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d", &G[i][j]);
			if(i == j && G[i][j] == 1)
				G[i][i] = 0;
		}
	}
	Graph G1[100];
	for(i = 0; i < n; i++) {
		G1[i].neighbour = NULL;
		G1[i].visited = 0;
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(G[i][j])
				list_append((G1[i].neighbour), &G1[j]);
		}
	}
	for(i = 0; i < n; i++) {
		if(!G1[i].visited ) {
			if( !rec(&G1[i]))
				rez = 0;
		}
	}
	printf("%d",rez);
	for(i = 0; i < n; i++) {
		list_destroy(G1[i].neighbour);
	}
	return 0;
}
