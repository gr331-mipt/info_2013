/*
 * main.c
 *
 *  Created on: 16 мая 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

#define IS_DIGIT(a) ('0' <= (a) && (a) <= '9')
#define IS_LATIN(a) (('A' <= (a) && (a) <= 'Z') || ('a' <= (a) && (a) <= 'z'))

int num_word(char *s) {
	int len = strlen(s);
	int i;
	int num = 0;
	for(i = 0; i < len; i++) {
		for(; i < len && (IS_LATIN(s) || IS_DIGIT(s)); i++);
		num++;
	}
	return num;
}

int main() {
	char s[101];
	unsigned numtable[10];
	scanf("%s", s);
	/*int i;
	int flag = 0;
	for(i = 0; i < 10; i++)
		numtable[i] = 0;
	for(i = 0; s[i]; i++) {
		if('0' <= s[i] && s[i] <= '9') {
			if(!flag)
				flag = 1;
			numtable[s[i] - '0'] ++;
		}
	}
	if(!flag)
		printf("DIGITS NOT FOUND!\n");
	else
		for(i = 0; i < 10; i++) {
			printf("%d:%d\n", i, numtable[i]);
		}
	*/
	return 0;
}
