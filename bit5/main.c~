/*
 * main.c
 *
 *  Created on: 27 марта 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <string.h>

int main() {
	int a = 0;
	char str[4];
	while(fgets(str, 4, stdin)) {
		str[2] = '\0';
		if(!strcmp(str, "ma")) {
			a = a | 1;
		}
		// strcmp(str, "fe") не нужен
		if(!strcmp(str, "cl")) {
			a = a | (1 << 1);
		}
		// strcmp(str, "du") не нужен
		if(!strcmp(str, "ha")) {
			a = a | (1 << 2);
		}
		// strcmp(str, "nh") не нужен
		if(!strcmp(str, "tr")) {
			a = a | (1 << 3);
		}
		// strcmp(str, "sk") не нужен
		// strcmp(str, "bn") не нужен
		if(!strcmp(str, "rd")) {
			a = a | (1 << 4);
		}
		if(!strcmp(str, "bw")) {
			a = a | (2 << 4);
		}
		if(!strcmp(str, "bk")) {
			a = a | (3 << 4);
		}
		// strcmp(str, "bu") не нужен
		if(!strcmp(str, "ge")) {
			a = a | (1 << 6);
		}
		if(!strcmp(str, "gy")) {
			a = a | (2 << 6);
		}
		if(!strcmp(str, "da")) {
			a = a | (3 << 6);
		}
	}
	printf("%x", a);
	return 0;
}
