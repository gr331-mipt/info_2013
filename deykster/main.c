/*
 * main.c
 *
 *  Created on: 14 февр. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>

unsigned get_next_node(unsigned *visited, unsigned *marks, unsigned n) {
	unsigned i, m = (unsigned) -1;
	for(i = 0; i < n; i++) {
		if(!visited[i] && (m == (unsigned)-1 || marks[i] < marks[m]))
			m = i;
	}
	return m;
}

int main() {
	unsigned i, j, n, m, x, y ,w;
	unsigned G[100][100] = {{}};
	unsigned visited[100], marks[100];
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) {
		marks[i] = (unsigned) -1;
	}
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &w);
		G[x][y] = G[y][x] = w;
	}
	scanf("%d", &x);
	marks[x] = 0;
	while( i = get_next_node(visited, marks, n) != (unsigned)-1 ) {
		visited[i] = 1;
		for( j = 0; j < n; j++) {
			if(G[i][j] > 0 && !visited[j] && marks[i] + G[i][j] < marks[j])
				marks[j] = marks[i] + G[i][j];
		}
	}
	for(i = 0; i < n; i++) {
		printf("%d ",(int) marks[i]);
	}
	return 0;
}
