/*
 * main.c
 *
 *  Created on: 14 мая 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

#define IS_DIGIT(a) ('0' <= (a) && (a) <= '9')
#define IS_LATIN(a) (('A' <= (a) && (a) <= 'Z') || ('a' <= (a) && (a) <= 'z'))

int check(char *s) {
	int i;
	for(i = 0; s[i]; i++) {
		if(!(IS_DIGIT(s[i]) || IS_LATIN(s[i])))
			return 0;
	}
	return 1;
}

int rule1(char *s) {
	int i;
	for(i = 0; s[i]; i++) {
		if('A' <= s[i] && s[i] <= 'Z')
			s[i] = 'Z' - (s[i] - 'A');
	}
	return 0;
}

int rule2(char *s) {
	int i;
	int len;
	for(len = 0; s[len]; len++);
	for(i = 0; i < len - 1; i++) {
		while(s[i] == s[i + 1]) {
			len--;
			int j;
			for(j = i + 1; j < len; j++)
				s[j] = s[j + 1];
			s[len] = '\0';
		}
	}
	return 0;
}

int main() {
	char s[101];
	scanf("%s", s);
	printf("%s\n", s);
	if(check(s)) {
		rule1(s);
	}
	else {
		rule2(s);
	}
	printf("%s\n", s);
	return 0;
}
