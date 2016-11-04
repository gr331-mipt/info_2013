/*
 * main.c
 *
 *  Created on: 19 дек. 2013 г.
 *      Author: ALTAIR
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct List;

typedef char* List_type;
typedef struct List List;

typedef struct {
	int group;
	int year;
	char *surname;
	int room;
	float mark;
} Prof;

struct List {
	List *prev;
	Prof *Data;
	List *next;
};

int tubs = 0;

int list_add(List **tail, Prof *prof);
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
	return a->Data->year - b->Data->year;
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
		if(compare(L, R) < 0) {
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

Prof *new_prof() {
	Prof *prof = (Prof*)malloc(sizeof(prof));
	prof->surname =(char*) malloc(512*sizeof(char));
	return prof;
}

int main() {
	FILE *f_in = fopen("input.txt", "r");
	if(f_in != NULL) {
		char buf_str[1025];
		List *list = NULL;
		Prof *prof = NULL;
		List *head = NULL;
		while(fgets(buf_str, sizeof(buf_str), f_in)) {
			prof = new_prof();
			sscanf(buf_str, "%s %d %f %d %d", prof->surname, &(prof->group), &(prof->mark), &(prof->year), &(prof->room));
			list_add(&list, prof);
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

int list_add(List **tail, Prof *prof) {
	List *newList = (List*) malloc(sizeof(List));
	if(newList == NULL)
		return 0;
	newList->prev = *tail;
	newList->next = NULL;
	newList->Data = prof;
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
			list = head;
			head = head->next;
			fprintf(f_out, "%d", list->Data->year);
			fprintf(f_out, "%20s %3d %3.2f %3d %3d\n", list->Data->surname, list->Data->group, list->Data->mark, list->Data->year, list->Data->room );
			free(list->Data->surname);
			free(list->Data);
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
