/*
 * list.c
 *
 *  Created on: 07 дек. 2013 г.
 *      Author: ALTAIR
 */
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

struct List;

typedef int List_type;
typedef struct List List;

List *list_search(List *head, unsigned index) {
	if(head == NULL)
		return NULL;
	int i;
	for(i = 0; i < index && head != NULL; i++ , head = head->next)
		;
	return head;
}

List *list_add(List *head, int item) {
	List *newList = (List*) malloc(sizeof(List));
	newList->next = head;
	if(head != NULL)
		head->prev = newList;
	newList->prev = NULL;
	newList->Value = item;
	return newList;
}

List *list_append(List *head, int item) {
	List *tail = head;
	while(tail != NULL && tail->next != NULL)
		tail = tail->next;
	List *newList = (List*) malloc(sizeof(List));
	newList->next = NULL;
	newList->prev = tail;
	newList->Value = item;
	if(tail != NULL) {
		tail->next = newList;
		return head;
	}
	return newList;
}

List *list_insert(List *head, unsigned index, int item) {
	if(index == 0)
		return list_add(head, item);
	if(head == NULL)
		return NULL;
	List *current = list_search(head, index - 1);
	if(current != NULL) {
		List *newList = (List*) malloc(sizeof(List));
		newList->prev = current;
		newList->next = current->next;
		newList->Value = item;
		current->next = newList;
		if(newList->next != NULL)
			newList->next->prev = newList;
	}
	return head;
}

List *list_delete(List *head, unsigned index) {
	List *current = list_search(head, index);
	if(current == NULL)
		return head;
	if(index == 0) {
		head = head->next;
		if(head != NULL)
			head->prev = NULL;
	}
	else {
		if(current->prev != NULL)
			current->prev->next = current->next;
		if(current->next != NULL)
			current->next->prev = current->prev;
	}
	if(current != NULL)
		free(current);
	return head;
}

List *list_delete_first(List *head) {
	if(head == NULL)
		return NULL;
	List *delete = head;
	head = head->next;
	if(head != NULL)
		head->prev = NULL;
	free(delete);
	return head;
}

List *list_delete_last(List *head) {
	if(head == NULL)
		return NULL;
	List *tail = head;
	while(tail->next != NULL)
		tail = tail->next;
	if(tail != NULL) {
		if(tail->prev != NULL)
			tail->prev->next = NULL;
		free(tail);
	}
	if(tail == head)
		return NULL;
	return head;
}

int list_get(List *head, unsigned index) {
	head = list_search(head, index);
	if(head == NULL)
		return -1;
	return head->Value;
}

void list_set(List *head, unsigned index, int item) {
	head = list_search(head, index);
	if(head != NULL)
		head->Value = item;
}

int list_find(List *head, int item) {
	unsigned i;
	for(i = 0; head != NULL && head->Value != item; i++ , head = head->next)
		;
	if(head != NULL)
		return i;
	return -1;
}

unsigned list_size(List *head) {
	unsigned size = 0;
	for(size = 0; head != NULL; size++)
		 head = head->next;
	return size;
}

void list_print(List *head) {
	while(head != NULL) {
		printf("%d ", head->Value);
		head = head->next;
	}
	printf("\n");
}

void list_reverse_print(List *head) {
	while(head != NULL && head->next != NULL)
		head = head->next;
	while(head != NULL) {
		printf("%d ", head->Value);
		head = head->prev;
	}
	printf("\n");
}

void list_destroy(List *head) {
	while(head != NULL) {
		List *delete = head;
		head = head->next;
		free(delete);
	}
}
