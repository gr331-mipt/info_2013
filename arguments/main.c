/*
 * main.c
 *
 *  Created on: 21 нояб. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

int main(int argc, char* argv[]) {
	int sum = 0;
	int i;
	int number = 0;
	for(i = 1; i < argc; i++) {
		sscanf(argv[i], "%d", &number);
		sum += number;
	}
	return sum;
}
