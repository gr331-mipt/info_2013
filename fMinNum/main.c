/*
 * main.c
 *
 *  Created on: 13 дек. 2013 г.
 *      Author: ALTAIR
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
	return *(char*)a - *(char*)b;
}

int main() {
	FILE *f_in = fopen("input.txt", "r");
	if(f_in != NULL){
		char s[20];
		fscanf(f_in, "%s", s);
		fclose(f_in);
		qsort(s, strlen(s), sizeof(char), compare);
		FILE *f_out = fopen("output.txt", "w");
		fprintf(f_out, "%s", s);
		fclose(f_out);
	}
	else {
		perror("input.txt");
	}
	return 0;
}
