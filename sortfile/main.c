/*
 * main.c
 *
 *  Created on: 24 нояб. 2013 г.
 *      Author: ALTAIR
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG

#define ASSERT_MESSAGE(cond,message) \
	if(!(cond)) {\
		perror(message);\
		abort();\
	}

#define ASSERT(cond) \
	if(!(cond)) {\
		printf("%s line: %d", #cond, __LINE__);\
		dump_printf(#cond);\
		abort();\
	}

struct List;
typedef struct List List;

struct List {
	List *prev;
	char *str;
	List *next;
};

int tubs = 0;

int list_add(List **str, char *buf_str);

int list_destroy(List **List);

int list_print(FILE* f_out, List *list);

void list_info(List *list);

void list_dump(List *list, int way);

int list_size(List *head, List *tail);

#ifdef DEBUG
void dump_tubs() {
	FILE *dump = fopen("dump.log", "a");
	int i;
	for(i = 0; i < tubs; i++) {
		fprintf(dump, "    ");
	}
	fprintf(dump, "|");
	fclose(dump);
}
#endif

void dump_printf(char *str) {
#ifdef DEBUG
	FILE *dump = fopen("dump.log", "a");
	dump_tubs();
	fprintf(dump, "%s\n", str);
	fclose(dump);
#endif
}

int strins(char str[], char buf[]){
	int len = strlen(buf) + 1;
	int i;
	for(i = 0; i < len && buf[i] != '\n'; i++)
		str[i] = buf[i];
	if(str[i] != '\0')
		str[i+1] = '\0';
    return 0;
}

char *Middle(List* head, unsigned size) {
	unsigned middle_counter = size / 2;
	List *middleList = head;
	int i;
	for(i = 0; i < middle_counter; i++) {
		middleList = middleList->next;
	}
	dump_printf(middleList->str);
	return middleList->str;
}

int change(List* a, List* b) {
	dump_printf("change");
	ASSERT(a != NULL);
	ASSERT(b != NULL);
	if(a == b)
		return 1;
	//list_dump(a, 1);
	dump_printf("a, b:");
	list_info(a);
	list_info(b);
	if(b->prev != a && a->prev != b) {
		List *buf = a->prev;
		a->prev = b->prev;
		b->prev = buf;
		buf = a->next;
		a->next = b->next;
		b->next = buf;
	}
	else {
		if(b->prev == a){
			b->prev = a->prev;
			a->next = b->next;
			b->next = a;
			a->prev = b;
		}
		else{
			a->prev = b->prev;
			b->next = a->next;
			a->next = b;
			b->prev = a;
		}
	}
	if(a->next != NULL)
		(a->next)->prev = a;
	if(a->prev != NULL)
		(a->prev)->next = a;
	if(b->next != NULL)
		(b->next)->prev = b;
	if(b->prev != NULL)
		(b->prev)->next = b;
	list_info(a);
	list_info(b);
	dump_printf("change_end\n");
	return 0;
}

int sort1(List *head, List *tail) {
	dump_printf("/*******************sort_start******************\\\n");
	list_info(head);
	list_info(tail);
	list_dump(head, 1);
	ASSERT(head != NULL);
	ASSERT(tail != NULL);
	List *left = head;
	List *right = tail;
	long i = 1;
	long size = list_size(head, tail);// + 1;
	long j = size;
	char *middle = Middle(head, size);
	dump_printf("middle:");
	dump_printf(middle);
	do{
		while( strcmp(left->str, middle    ) > 0 && i < size) {
			ASSERT(left != NULL);
			ASSERT(left != tail);
			left = left->next;
			i++;
		}
		while( strcmp(middle   , right->str) > 0 && j > 0) {
			ASSERT(right != NULL);
			ASSERT(right != head);
			right = right->prev;
			j--;
		}
		if( i <= j) {
			ASSERT(left != NULL);
			ASSERT(right != NULL);
			List* left1 = left;
			List* right1 = right;
			if(left == head)
				head = right;
			if(right == tail)
				tail = left;
			left = left->next;
			right = right->prev;
			change(left1, right1);
			i++;
			j--;
		}
	}while (i < j);
	list_dump(head, 1);
	dump_printf("left, right");
	list_info(left);
	list_info(right);
	tubs ++;
	if(left == right )
		left = left->next;
	if(right != NULL && right != head && 1 < j){
		dump_printf("sort1\n");
		sort1(head , right );
	}
	if(left != NULL && left != tail && i < size){
		dump_printf("sort2\n");
		dump_printf("cont");
		sort1(left, tail);
	}
	tubs --;
	return 0;
}

List *MiddleList(List *head, const long size) {
	List *middleList = head;
	int i;
	for(i = 0; i < size/2; i++)
		middleList = middleList->next;
	return middleList;
}

int sort(List *head, List *tail) {
	list_dump(head, 1);
	long size = list_size(head, tail);
	if( size <= 1)
		return 0;
	List *middleList = MiddleList(head, size);
	list_info(middleList);
	if(head != middleList)
		sort(head, middleList);
	if(middleList->next != tail)
		sort(middleList->next, tail);
	List *current1 = head;
	List *current2 = middleList;
	middleList->prev->next = NULL;
	middleList->prev = NULL;
	while(current2 != NULL) {
		while(strcmp(current1->str, current2->str) < 0 && current1->next != NULL)
			current1 = current1->next;
		if(current1->next == NULL) {
			current1->next = current2;
			current2->prev = current1;
			current2 = NULL;
		}
		else {
			List *prev = current1->prev;
			ASSERT(prev->next != NULL);
			prev->next = current2;
			current2 = current2->next;
			prev->next->next = current1;
		}
	}
	return 0;
}

int pre_sort(List *tail) {
	if(tail == NULL)
		return 0;
	List* head = tail;
	while(head->prev != NULL)
		head = head->prev;
	dump_printf("/**************************NEW SORT**************************/");
	sort1(head, tail);
	list_dump(head, 1);
	return 0;
}

int main() {
	FILE *f_in = fopen("input.txt", "r");
	ASSERT_MESSAGE(f_in != NULL, "input.txt");
	List *strings = NULL;
	char buf_str[1025];
	while(fgets(buf_str, sizeof(buf_str), f_in)) {
		list_add(&strings, buf_str);
	}
	fclose(f_in);
	pre_sort(strings);
	FILE *f_out = fopen("output.txt", "w");
	list_print(f_out, strings);
	fclose(f_out);
	list_destroy(&strings);
	return 0;
}

int list_add(List **str, char *buf_str) {
	if(buf_str == NULL)
		return 0;
	List *newList =(List*) calloc(1, sizeof(List));
	newList->prev = *str;
	newList->str =(char*) calloc(1, strlen(buf_str) + 1);
	strins(newList->str, buf_str);
	newList->next = NULL;
	if(*str != NULL)
		(*str)->next = newList;
	*str = newList;
	return 1;
}

int list_destroy(List **list) {
	List *deletedList = *list;
	while(deletedList != NULL) {
		*list = deletedList->prev;
		deletedList->prev = NULL;
		free(deletedList->str);
		deletedList->str = NULL;
		deletedList->next = NULL;
		free(deletedList);
		deletedList = *list;
	}
	return 1;
}

int list_print(FILE *f_out, List *list) {
	ASSERT_MESSAGE(f_out != NULL, "output error!");
	while(list->next != NULL)
		list = list->next;
	while(list != NULL) {
		fprintf(f_out, "%s\n", list->str);
		list = list->prev;
	}
	return 1;
}

void list_info(List *list) {
#ifdef DEBUG
	FILE* dump = fopen("dump.log", "a");
	dump_tubs();
	fprintf(dump," : %s\n", list->str);
	dump_tubs();
	fprintf(dump, "\t I:0x%6X   prev:0x%6X    next:0x%6X \n",(int)list, (int)list->prev, (int)list->next);
	fclose(dump);
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

int list_size(List *head, List *tail) {
	ASSERT(head != NULL);
	ASSERT(tail != NULL);
	//ASSERT(head != tail);
	List *currentList = head;
	int size;
	for( size = 1; currentList != tail && currentList != NULL; size++) {
		ASSERT(currentList->next != currentList);
		currentList = currentList->next;
	}
	return size;
}
