/*
 * main.c
 *
 *  Created on: 28 янв. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

int main () {
	char a[1024];
	FILE *f_in = fopen("input.txt", "r");
	FILE *f_out = fopen("output.txt", "w");
	if(f_in && f_out) {
		while(fgets(a, sizeof(a), f_in)) {
			if((int)'0' <= (int)a[0] && (int)a[0] <= (int) '9' )
				fputs(a , f_out);
		}
		fclose(f_in);
		fclose(f_out);
	}
	return 0;
}
