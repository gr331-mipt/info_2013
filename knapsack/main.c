#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num;
	int w; //вес
	int v; //цена
} elem;

int cost = 0;

int addpack(int p, int n) {
	int i;
	for(i = n - 1; i >= 0 && i < n ; i--) {
		if(addpack(p - 1, n - i))

	}
	return 0;
}

int newPack(int p, elem* knapsack, int n) {
	int *pack = (int *) calloc(p, sizeof(int));
	addpack(p , n , knapsack, pack);
	return 1;
}

int main() {
	int p, n;
	scanf("%d %d", &p, &n);
	elem *knapsack = (elem *) calloc(n, sizeof(elem));
	int i;
	for(i = 0; i < n; i++) {
		knapsack[i].num = i + 1;
		scanf("%d %d", &knapsack[i].w, &knapsack[i].v);
	}
	newPack(p, knapsack, n);
	for(i = 0; i < n; i++) {
		printf("%d %d\n", knapsack[i].w, knapsack[i].v);
	}
	free(knapsack);
	return 0;
}
