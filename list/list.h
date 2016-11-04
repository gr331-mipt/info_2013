/*
 * list.h
 *
 *  Created on: 07 дек. 2013 г.
 *      Author: ALTAIR
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>
#include <stdio.h>

struct List;

typedef int List_type;
typedef struct List List;

struct List {
	List *prev;
	List_type Value;
	List *next;
};

//Первым параметром во все функции передаётся указатель на начало списка
//добавить элемент в начало списка
List *list_add(List *head, int item);
//добавить элемент в конец списка
List *list_append(List *head, int item);
//вставить элемент в позицию index
List *list_insert(List *head, unsigned index, int item);
//удалить элемент с номером index
List *list_delete(List *head, unsigned index);
//удалить первый элемент
List *list_delete_first(List *head);
//удалить последний элемент
List *list_delete_last(List *head);
//Все вышеперечисленные функции могут изменить голову списка,
//поэтому возвращают новое значение head (или NULL, если список пустой)

//получить элемент с номером index (если не найден, возвращается -1)
int list_get(List *head, unsigned index);
//изменить элемент с номером index
void list_set(List *head, unsigned index, int item);
//найти номер первого элемента, равного item (если не найден, возвращается -1)
int list_find(List *head, int item);
//длина списка
unsigned list_size(List *head);
//распечатать список (числа разделяются пробелами)
void list_print(List *head);
//распечатать список задом наперёд
void list_reverse_print(List *head);
//уничтожить список и освободить всю память
void list_destroy(List *head);

#endif /* LIST_H_ */
