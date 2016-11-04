/*
 * main.c
 *
 *  Created on: 15 нояб. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strins(char str[], char buf[]){
	int len = strlen(buf) + 1;
	int i;
	for(i = 0; i < len && buf[i] != '\n'; i++)
		str[i] = buf[i];
	if(str[i] != '\0')
		str[i+1] = '\0';
    return 0;
}

int compare(void** a, void** b) {
	return (strcmp(*a, *b));
}


int main() {
	FILE* f_in = fopen("input.txt", "r");// "w" , "a"
	if(f_in != NULL) {
		int n;
		fscanf(f_in, "%d\n", &n);
		/*
		 * s = "mama"
		 * s == *
		 * s[1] = "mama"
		 * s[1] == *
		 * s == **
		 */
		if(n > 0) {
			char** str_array = (char**) malloc(n * sizeof(char*));
			int i;
			char buf_str[1030];
			for(i = 0; i < n; i++) {
				if(fgets(buf_str, sizeof(buf_str), f_in) != NULL){
					str_array[i] = (char*) malloc((strlen(buf_str) + 2) * sizeof(char));
					strins(str_array[i], buf_str);
				}
				else {
					n = i;
					break;
				}
			}
			fclose(f_in);
			qsort(str_array, n, sizeof(char**), compare);
			FILE* f_out = fopen("output.txt", "w");
			for(i = 0; i < n; i++) {
				fprintf(f_out, "%s\n", str_array[i]);
				free(str_array[i]);
			}
			free(str_array);
			fclose(f_out);
		}
		else
			fclose(f_in);
	}
	else {
		perror("input.txt");
		return -1;
	}
	return 0;
}
