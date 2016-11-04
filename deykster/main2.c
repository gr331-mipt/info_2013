/*
 * main2.c
 *
 *  Created on: 14 февр. 2014 г.
 *      Author: ALTAIR
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct Graph Graph;
typedef struct List List;

struct Graph {
	unsigned mark;
	unsigned visited;
	List *neighbors;
};

struct List {
	Graph *item;
	unsigned weight;
	List *next;
};

List *list_add(Graph *item, unsigned weight, List *head) {
	List *list = calloc(1, sizeof(List));
	list->item = item;
	list->weight = weight;
	list->next = head;
	return list;
}

int main() {
	unsigned n, m, i;
	unsigned x, y, w;
	scanf("%d %d", &n, &m);
	Graph *G = (Graph*) calloc(n, sizeof(Graph));
	for( i = 0; i < n; i++) {
		G[i].mark = (unsigned) -1;
		G[i].visited = 0;
	}
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &w);
		G[x].neighbors = list_add(G[x].neighbors, &G[y], w);
	}
	scanf("%d", &x);
	G[x].mark = 0;
	while(i = get_next_node(G, n) != (unsigned) -1) {
		List *list;
		G[i].visited = 1;
		for(list = G[i].neighbors; list; list = list->next)
			if(!list->item->visited && G[i].mark + list->weight < list->item->mark)
				list->item->mark = G[i].mark + list->weight;
	}
	for( i = 0; i < n; i++) {
		printf();//вывод на экран
	}
	list_destroy();
}


