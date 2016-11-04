/*
 * main.c
 *
 *  Created on: 14 февр. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

int f() {
	int i, j, n;
	int elem;
	int score;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		score = 0;
		for(j = 0; j < n; j++) {
			scanf("%d", &elem);
			if(i != j)
				score += elem;
			else
				score += 2 * elem;
		}
		if(score % 2)
			return 0;
	}
	return 1;
}

int main() {
	printf(f() ? "YES" : "NO");
	return 0;
}
