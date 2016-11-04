/*
 * main.c
 *
 *  Created on: 07 марта 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <string.h>

int code(char *string, int key) {
	if(!(0 < key && key < 32)) {
		printf("key will be 0< && <32");
		return 0;
	}
	int len = strlen(string);
	int i;
	for(i = 0; i < len; i++) {
		string[i] ^= key;
	}
	return 1;
}

int main() {
	char string[100];
	int key;
	scanf("%s", string);
	scanf("%d", &key);
	code(string, key);
	printf("%s\n", string);
	code(string, key);
	printf("%s\n", string);
	return 0;
}
