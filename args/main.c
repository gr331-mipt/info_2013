/*
 * main.c
 *
 *  Created on: 15 нояб. 2013 г.
 *      Author: ALTAIR
 */
#include <stdio.h>
#include <stdlib.h>

//int f(int a, int b);
int f1 (int n, double ...);

int main(int argc, char* argv[], char* envp[]) {
	printf("argv[]\n");
	int i;
	for(i = 0; i < argc; i++) {
		printf("%d : %s\n", i, argv[i]);
	}
	printf("envp[] \n");
	f1(5, 1, 2 , 3, 4 ,5);
	for(i = 0; envp[i] != NULL; i++) {
		printf("%d : %s \n", i, envp[i]);
	}
	return 0;
}
