/*
 * list.c
 *
 *  Created on: 03 дек. 2013 г.
 *      Author: ALTAIR
 */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#define DEBUG

#define ASSERT(cond) \
	if(!(cond)) { \
		printf("%s file: %s line: %d\n", #cond, __FILE__, __LINE__);\
		abort();\
	}

#define PUSH 1

struct List {
	List *prev;
	List_elem Type;
	List_command Command;
	List_type Value;
	List *next;
};

int list_add(List **tail, List_command Command, List_type Value, List_elem Type) {
	ASSERT( tail != NULL);
	printf("COM: %d, VAL: %d, TYPE: %d\n", Command, Value, Type);
	List *newList = (List*) malloc(sizeof(List));
	ASSERT(newList != NULL);
	newList->next = NULL;
	newList->Type = Type;
	newList->Command = Command;
	newList->Value = Value;
	newList->prev = *tail;
	if(*tail != NULL)
		(*tail)->next = newList;
	*tail = newList;
	printf("#ADD_END\n");
	return 1;
}

int list_add_jump(List **tail, List_type Jump) {
	ASSERT(tail != NULL);
	return list_add(tail, 0, Jump, JUMP);
}

int list_push(List **tail, List_type Value) {
	ASSERT(tail != NULL);
	return list_add(tail, PUSH, Value, COMMAND);
}

int list_add_command(List **tail, List_command Command) {
	ASSERT(tail != NULL);
	return list_add(tail, Command, 0, COMMAND);
}

void list_destroy(List **tail) {
	ASSERT( tail != NULL);
	while((*tail)->next != NULL)
		*tail = (*tail)->next;
	while(*tail != NULL) {
		(*tail)->prev = NULL;
		(*tail)->Command = 0xBAD;
		(*tail)->Value = 0xBAD;
		(*tail)->Type = 0xBAD;
		List *prev = (*tail)->prev;
		(*tail)->next = NULL;
		free(*tail);
		*tail = prev;
	}
	free(*tail);
}

List *list_head(List *tail) {
	ASSERT(tail != NULL);
	List *head = tail;
	while(head->prev != NULL)
		head = head->prev;
	return head;
}

int list_step(List **currentList) {
	ASSERT( currentList != NULL);
	ASSERT(*currentList != NULL);
	if((*currentList)->next == NULL)
		return 0;
	*currentList = (*currentList)->next;
	return 1;
}

int list_jump(List **currentList, List_type Value) {
	ASSERT( currentList != NULL);
	ASSERT(*currentList != NULL);
	List *toJumpList = *currentList;
	while(toJumpList->Type != JUMP && toJumpList->Value != Value) {
		toJumpList = toJumpList->prev;
		if(toJumpList == NULL) {
			printf("#point not find!");
			return 0;
		}
	}
	*currentList = toJumpList;
	return 1;
}

void dump_printf(char *str) {
#ifdef DEBUG
	FILE *dump = fopen("dump.log", "a");
	fprintf(dump, "%s\n", str);
	fclose(dump);
#endif
}

void list_info(List *list) {
#ifdef DEBUG
	FILE* dump = fopen("dump.log", "a");
	fprintf(dump," : Type: %d , Val: %d , Com: %d\n", list->Type, list->Value, list->Command);
	fprintf(dump, "\t I:0x%6X   prev:0x%6X    next:0x%6X \n",(int)list, (int)list->prev, (int)list->next);
	fclose(dump);
#endif
}

void list_dump(List *list, int way) {
#ifdef DEBUG
	dump_printf("LIST DUMP\n");
	if(list == NULL)
		dump_printf("LIST is NULL");
	else {
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
	}
	dump_printf("DUMP END\n");
#endif
}
