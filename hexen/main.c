/*
 * main.c
 *
 *  Created on: 21 февр. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <string.h>

int f1(char c, int is_fr) {
	if(is_fr) {
		switch (c){
			case '0': printf("0");
				break;
			case '1': printf("1");
				break;
			case '2': printf("10");
				break;
			case '3': printf("11");
				break;
			case '4': printf("100");
				break;
			case '5': printf("101");
				break;
			case '6': printf("110");
				break;
			case '7': printf("111");
				break;
			case '8': printf("1000");
				break;
			case '9': printf("1001");
				break;
			case 'A': printf("1010");
				break;
			case 'B': printf("1011");
				break;
			case 'C': printf("1100");
				break;
			case 'D': printf("1101");
				break;
			case 'E': printf("1110");
				break;
			case 'F': printf("1111");
				break;
		}
	}
	else {
		switch (c){
			case '0': printf("0000");
				break;
			case '1': printf("0001");
				break;
			case '2': printf("0010");
				break;
			case '3': printf("0011");
				break;
			case '4': printf("0100");
				break;
			case '5': printf("0101");
				break;
			case '6': printf("0110");
				break;
			case '7': printf("0111");
				break;
			case '8': printf("1000");
				break;
			case '9': printf("1001");
				break;
			case 'A': printf("1010");
				break;
			case 'B': printf("1011");
				break;
			case 'C': printf("1100");
				break;
			case 'D': printf("1101");
				break;
			case 'E': printf("1110");
				break;
			case 'F': printf("1111");
				break;
		}
	}
	return 0;
}

int f(char c, int Is_Frst) {
	int N, len;
	char str[10] = "";
	sscanf(&c, "%X", &N);
	if(!N) {
		if(!Is_Frst)
			printf("0000");
		return 0;
	}
	for(len = 0; N > 0; N = (int) N / 2, len++) {
		int digit = N % 2;
		sprintf(str, "%s%d",str, digit);
	}
	int i;
	if(!Is_Frst) {
		for(i = 0; i < 4 - len; i++)
			printf("0");
	}
	for(i = len - 1; i >= 0; i--){
		printf("%c", str[i]);
	}
	return 0;
}

int main() {
	char a[1000010];
	scanf("%s", a);
	long long i;
	for(i = 0; a[i] != '\0'; i++) {
		f1(a[i], !i );
	}
	return 0;
}
