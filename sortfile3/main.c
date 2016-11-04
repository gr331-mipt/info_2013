/*
 * main.c
 *
 *  Created on: 06 дек. 2013 г.
 *      Author: ALTAIR
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct List;

typedef char* List_type;
typedef struct List List;

struct List {
	List *prev;
	List_type Value;
	List *next;
};

int tubs = 0;

int list_add(List **tail, char *Str);
int list_insert(List *a, List *b);//написана руками внизу :)
void list_print_and_del(List *list);
int list_size(List *list);

List *list_middle(List *list, int size) {
	int i;
	List *middle = list;
	size = size / 2;
	for(i = 0; i < size && middle != NULL; i++)
		middle = middle->next;
	return middle;
}

int compare(List *a, List *b) {
	return 0;
}

List *list_sort(List *list) {
	List *L = list;
	int size = list_size(list);
	List *R = list_middle(list, size);
	if(R != NULL && R->prev != NULL) {
		R->prev->next = NULL;
		R->prev = NULL;
	}
	if(R == L)
			R = R->next;
	if(size > 2) {
		L = list_sort(list);
		R = list_sort(R);
	}
	list = NULL;
	List *head = NULL;
	while(L != NULL && R != NULL) {
		if(compare(&L, &R)) {
			List *L1 = L;
			L = L->next;
			list_insert(list, L1);
			list = L1;
		}
		else {
			List *R1 = R;
			R = R->next;
			list_insert(list, R1);
			list = R1;
		}
		if(head == NULL)
			head = list;
	}
	if(L != NULL) {
		if(list != NULL)
			list->next = L;
		L->prev = list;
		list = L;
	}
	else {
		if(list != NULL)
			list->next = R;
		R->prev = list;
		list = R;
	}
	if(head != NULL)
		return head;
	else
		return list;
}

int main() {
	FILE *f_in = fopen("input.txt", "r");
	if(f_in != NULL) {
		char buf_str[1025];
		List *list = NULL;
		List *head = NULL;
		while(fgets(buf_str, sizeof(buf_str), f_in)) {
			list_add(&list, strdup(buf_str));
			if(head == NULL)
				head = list;
		}
		fclose(f_in);
		list = list_sort(head);
		list_print_and_del(list);
	}
	else {
		perror("input.txt");
	}
	return 0;
}

int list_add(List **tail, List_type Value) {
	List *newList = (List*) malloc(sizeof(List));
	if(newList == NULL)
		return 0;
	newList->prev = *tail;
	newList->next = NULL;
	int len = strlen(Value) - 1;
	if(len >= 0 && Value[len] == '\n')
		Value[len] = '\0';
	newList->Value = Value;
	if(*tail != NULL)
		(*tail)->next = newList;
	*tail = newList;
	return 1;
}

int list_insert(List *a, List *b) {
	if(a != NULL)
		a->next = b;
	b->prev = a;
	b->next = NULL;
	return 1;
}

void list_print_and_del(List *list) {
	if(list != NULL) {
		List *head = list;
		FILE* f_out = fopen("output.txt", "w");
		while(head != NULL) {
			fprintf(f_out, "%s\n", head->Value);
			free(head->Value);
			list = head;
			head = head->next;
			free(list);
		}
		fclose(f_out);
	}
}

int list_size(List *list) {
	int size = 0;
	List *head = list;
	for(size = 0; head != NULL; size++)
		head = head->next;
	return size;
}
