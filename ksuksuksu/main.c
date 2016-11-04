/*
 * main.c
 *
 *  Created on: 14 мая 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

int check(char *s) {
	int len, i;
	for(len = 0; s[len]; len++);
	if(!len)
		return 0;
	if(!('A' <= s[len - 1] && s[len - 1] <= 'Z'))
		return 0;
	for(i = len - 2; i >= 0 && s[i] != s[len - 1]; i--);
	if(i > 0)
		return 0;
	return 1;
}

int rule1(char *s) {
	int i;
	for(i = 0; s[i]; i++) {
		if('0' <= s[i] && s[i] <= '9') {
			s[i] = s[i] - '0' - 1 + 'a';
		}
	}
	printf("WAS RULE 1\n");
	return 0;
}

int rule2(char *s) {
	int i;
	if(s[0] != 0) {
		for(i = 1; s[i]; i++) {
			while(s[i] && s[i] == s[0]) {
				int j;
				for(j = i; s[j + 1]; j++) {
					s[j] = s[j + 1];
				}
				s[j] = '\0';
			}
		}
	}
	printf("WAS RULE 2\n");
	return 0;
}

int main() {
	char s[101] = "";
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
