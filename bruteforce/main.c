/*
 * main.c
 *
 *  Created on: 06 марта 2014 г.
 *      Author: ALTAIR
 */


#define START_CHAR 'A'
#define STOP_CHAR 'Z'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int check(const char *buf) {
	printf("%s\n", buf);
	return 0;
}

int bruteforce(char buf[], unsigned n) {
	buf[0] = '\0';
	if(check(buf))
		return 1;
	int len;
	int i;
	for(len = 0; len < n - 1; len++) {
		printf("1");
		for(i = 0; i <= len; i++)
			buf[i] = START_CHAR;
		buf[len + 1] = '\0';
		char c = 0;
		while(!c) {
			for(buf[len] = START_CHAR; buf[len] <= STOP_CHAR; buf[len]++) {
				if(check(buf))
					return 1;
			}
			c = 1;
			for(i = len - 1; i >= 0 && c > 0; i--) {
				buf[i] += c;
				c = 0;
				if(buf[i] > STOP_CHAR) {
					c = 1;
					buf[i] = START_CHAR;
				}
			}
		}
	}
	printf("\n");
	return 0;
}

int main() {
	char buf[100];
	printf("%d\n", bruteforce(buf, 6));
	printf("%s\n", buf);
	FILE *fout = fopen("out.txt", "a");
	fprintf(fout, "time:%lf\n", (double)clock() / CLOCKS_PER_SEC);
	fclose(fout);
	return 0;
}
