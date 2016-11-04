/*
 * main.c
 *
 *  Created on: 22 дек. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strdel(char *str, int index, int number, int length) {
	length -= number;
	if(length <= 0)
		return 1;
	int i;
	for(i = index; i < length; i++){
		str[i] = str[i + number];
	}
	return 0;
}

int spacecut(char *str) {
	int len = strlen(str);
	int i;
	for(i = 0; i < len; i++) {
		for(; str[i] == ' ' && str[i + 1] == ' '; len--) {
			strdel(&str[i + 1], 0, 1, len - i);
		}
	}
	for(len--; str[len] == ' '; len--)
		str[len] = '\0';
	return 0;
}

int main() {
	char s[80] = "amma    akjwkajg ajw       ";
	spacecut(s);
	printf("%s|", s);
	return 0;
}
