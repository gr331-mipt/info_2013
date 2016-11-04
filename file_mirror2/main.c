/*
 * main.c
 *
 *  Created on: 13 дек. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List;

typedef char* List_type;
typedef struct List List;

struct List {
	List *prev;
	List_type Value;
};

int list_add(List **tail, List_type Value) {
	List *newList = (List*) malloc(sizeof(List));
	if(newList == NULL)
		return 0;
	newList->prev = *tail;
	long len = strlen(Value) - 1;
	if(len >= 0 && Value[len] == '\n')
		Value[len] = '\0';
	newList->Value = Value;
	*tail = newList;
	return 1;
}

void list_print_and_del(List *list) {
	List *head = list;
	FILE* f_out = fopen("output.txt", "w");
	while(head != NULL) {
		fprintf(f_out, "%s\n", head->Value);
		free(head->Value);
		list = head;
		head = head->prev;
		free(list);
	}
	fclose(f_out);
}

int main() {
	FILE *f_in = fopen("input.txt", "r");
	if(f_in != NULL) {
		char buf_str[1025];
		List *list = NULL;
		while(fgets(buf_str, sizeof(buf_str), f_in) != NULL) {
			if(!list_add(&list, strdup(buf_str)))
				perror("NO MEMORY!!!");
		}
		fclose(f_in);
		list_print_and_del(list);
	}
	else
		perror("input.txt");
	return 0;
}
