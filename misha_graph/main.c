/*
 * main.c
 *
 *  Created on: 23 мая 2014 г.
 *      Author: ALTAIR
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
	int Ne = 0; // число ребер
	int Nu = 0; // число вершин
	scanf("%d", &Nu);
	scanf("%d", &Ne);
	int **Ways = (int **) calloc(Nu, sizeof(int *)); // массив соседей
	int *len = (int *) calloc(Nu, sizeof(int)); // длина пути
	int i;
	for(i = 0; i < Nu; i++) {
		len[i] = -1; // -1 => значит, что до этой точки мы еще не меряли расстояние
		Ways[i] = (int *) calloc(Nu, sizeof(int ));
	}
	for(i = 0; i < Ne; i++) {
		int edgeB, edgeE ; // начало ребра и конец
		scanf("%d %d", &edgeB, &edgeE);
		Ways[edgeB - 1][edgeE - 1] = 1; // заполняем массив соседей
		Ways[edgeE - 1][edgeB - 1] = 1;
	}
	int pointA, pointB; // номера точек, расстояние между которыми измеряем
	scanf("%d %d", &pointA, &pointB);
	pointA--;// уменьшаем, так как для людей нумерация с 1, а для массива с 0
	pointB--;

	len[pointA] = 0;// расстояние до 1 первой точки положим 0
	int sumLen;// счетчик суммарного расстояния
	int neighbor; // номер вершины соседа
	for(sumLen = 0; sumLen < Nu; sumLen++) {
		for(i = 0; i < Nu; i++)
			if(len[i] == sumLen) {
				for(neighbor = 0; neighbor < Nu; neighbor++) {
					if(Ways[i][neighbor] && len[neighbor] == -1) // если вершина сосед и мы там не были
						len[neighbor] = sumLen + 1; // положим расстояние на 1 большее чем до той клетки, где мы сейчас
				}
			}
	}

	printf("%d\n", len[pointB]); // печатаем ответ

	// Освобождаем память
	for(i = 0; i < Nu; i++) {
		free(Ways[i]);
	}
	free(Ways);
	free(len);

	return 0;
}
