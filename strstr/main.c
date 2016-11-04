/*
 * main.c
 *
 *  Created on: 08 нояб. 2013 г.
 *      Author: ALTAIR
 */

#include <stdlib.h>
#include <stdio.h>

int length(const char* str) {
	int length;
	for(length = 0; *(str + length) != '\0'; length++)
		;
	return length;
}

char* my_strstr(const char* str, const char* sub) {
	int LengthStr = length(str);
	int LengthSub = length(sub);
	int i, j;
	for(i = 0; i < LengthStr; i++) {
		for(j = 0; j < LengthSub && i+j < LengthStr && str[i+j] == sub[j] ; j++)
			;
		if(j == LengthSub)
			return &str[i];
	}
	return NULL;
}

/*
int main() {
	char str[] = "mammamamampapamm";
	char sub[] = "pap";
	char* str1 = my_strstr(str, sub);
	printf("%s", str1);
	return 0;
}
*/

