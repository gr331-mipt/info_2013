/*
 * main.c
 *
 *  Created on: 15 нояб. 2013 г.
 *      Author: ALTAIR
 */

#include "cpu.h"

int main(int argc, char* argv[]) {
	if(argc > 1)
		CPU_run(argv[1]);
	else {
		char file[256];
		printf("# file:\n");
		scanf("%s", file);
		CPU_run(file);
	}
	return 0;
}
