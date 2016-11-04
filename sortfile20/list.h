/*
 * list.h
 *
 *  Created on: 05 дек. 2013 г.
 *      Author: ALTAIR
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>
#include <stdio.h>

typedef char* List_type;
typedef struct List List;

struct List {
	List *prev;
	List_type Value;
	List *next;
};

int list_add(List **tail, char *Str);

void list_destroy(List **current);

int list_insert(List *a, List *b);

void list_print(List *list);

int list_size(List *list);

List *list_head(List* tail);

List *list_tail(List* head);

void dump_printf(char *str);
void dump_tubs();
void list_dump(List *list, int way);
void list_info(List *list);

//List *list_middle(List *list, int size);

#endif /* LIST_H_ */
