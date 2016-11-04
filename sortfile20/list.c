/*
 * list.c

 *
 *  Created on: 05 дек. 2013 г.
 *      Author: ALTAIR
 */
#include "list.h"

#define DEBUG
#ifdef DEBUG
#define ASSERT(cond) \
	if(!(cond)) {\
		printf("%s, file: %s line: %d", #cond, __FILE__, __LINE__);\
		abort();\
	}
#else
#define ASSERT(cond)
#endif

int tubs = 0;

List *list_head(List *tail) {
	ASSERT(tail != NULL);
	List *head = tail;
	while(head->prev != NULL)
		head = head->prev;
	return head;
}

List *list_tail(List *head) {
	ASSERT(head != NULL);
	List *tail = head;
	while(tail->next != NULL)
		tail = tail->next;
	return tail;
}

int list_add(List **tail, List_type Value) {
	ASSERT(tail   != NULL);
	ASSERT(Value  != NULL);
	List *newList = (List*) malloc(sizeof(List));
	if(newList == NULL)
		return 0;
	newList->prev = *tail;
	newList->next = NULL;
	newList->Value = Value;
	if(*tail != NULL)
		(*tail)->next = newList;
	*tail = newList;
	return 1;
}

void list_destroy(List **current) {
	ASSERT(current != NULL);
	List *tail = *current;
	if(tail != NULL) {
		while(tail->next != NULL) {
			tail = tail->next;
		}
		while(tail != NULL) {
			List *delete = tail;
			tail = tail->prev;
			free(delete->Value);
			delete->Value = NULL;
			delete->prev = NULL;
			delete->next = NULL;
			free(delete);
		}
	}
	*current = NULL;
}

int list_insert(List *a, List *b) {
	//ASSERT(a != NULL);
	ASSERT(b != NULL);
	ASSERT(a != b);
	if(a != NULL)
		a->next = b;
	b->prev = a;
	b->next = NULL;
	return 1;
}

void list_print(List *list) {
	if(list != NULL) {
		List *head = list_head(list);
		FILE* f_out = fopen("output.txt", "w");
		while(head != NULL) {
			fprintf(f_out, "%s\n", head->Value);
			head = head->next;
		}
		fclose(f_out);
	}
}

int list_size(List *list) {
	int size = 0;
	if(list != NULL) {
		List *head = list_head(list);
		for(size = 0; head != NULL; size++)
			head = head->next;
	}
	return size;
}

void list_info(List *list) {
#ifdef DEBUG
	if(list != NULL){
	FILE* dump = fopen("dump.log", "a");
	dump_tubs();
	fprintf(dump," : %s\n", list->Value);
	dump_tubs();
	fprintf(dump, "\t I:0x%6X   prev:0x%6X    next:0x%6X \n",(int)list, (int)list->prev, (int)list->next);
	fclose(dump);
	}
#endif
}

void list_dump(List *list, int way) {
#ifdef DEBUG
	dump_printf("LIST DUMP\n");
	List *currentList = list;
	if(!(way > 0))
		while(currentList->next != NULL) {
			currentList = currentList->next;
		}
	else
		while(currentList->prev != NULL)
			currentList = currentList->prev;
	int i;
	for(i = 0; currentList != NULL; i++) {
		ASSERT(currentList->next != currentList);
		ASSERT(currentList->prev != currentList);
		list_info(currentList);
		if(way > 0)
			currentList = currentList->next;
		else
			currentList = currentList->prev;
	}
	dump_printf("DUMP END\n");
#endif
}

void dump_tubs() {
#ifdef DEBUG
	FILE *dump = fopen("dump.log", "a");
	int i;
	for(i = 0; i < tubs; i++) {
		fprintf(dump, "    ");
	}
	fprintf(dump, "|");
	fclose(dump);
#endif
}

void dump_printf(char *str) {
#ifdef DEBUG
	FILE *dump = fopen("dump.log", "a");
	dump_tubs();
	fprintf(dump, "%s\n", str);
	fclose(dump);
#endif
}
