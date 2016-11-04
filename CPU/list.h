/*
 * list.h
 *
 *  Created on: 03 дек. 2013 г.
 *      Author: ALTAIR
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>
#include <stdio.h>

#define ASSERT(cond) \
	if(!(cond)) { \
		printf("%s file: %s line: %d\n", #cond, __FILE__, __LINE__);\
		abort();\
	}

struct List;

enum List_elem {
	COMMAND,
	JUMP
};

typedef struct List List;

typedef int List_command;

typedef int List_type;

typedef enum List_elem List_elem;

int list_add(List **tail,List_command Command, List_type Value, List_elem Type);

int list_add_jump(List **tail, List_type Jump);

int list_push(List **tail, List_type Value);

int list_add_command(List **tail, List_command Command);

void list_destroy(List **tail);

List *list_head(List *tail);

int list_step(List **currentList);

void dump_printf(char *str);

void list_dump(List *list, int way);

#endif /* LIST_H_ */
