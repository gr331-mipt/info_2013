/*
 * main.c
 *
 *  Created on: 15 нояб. 2013 г.
 *      Author: ALTAIR
 */
#include <stdio.h>

int main(int argc, char* argv[]) {
	if(argc < 1) {
		perror("Argument not found!");
		return -1;
	}
	FILE* f_in = fopen(argv[1], "r");
	char c;
	if(f_in != NULL){
		while(1) {
			if(!fscanf(f_in, "%c", &c) || feof(f_in))
				break;
			printf("%c",c);
		}
		fclose(f_in);
	}
	else {
		perror("file not found!!");
	}
	return 0;
}
