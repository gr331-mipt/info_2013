/*
 * main.c
 *
 *  Created on: 19 дек. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INS 1
#define FND 2

struct Profile;
struct Tree;
typedef struct Profile Prof;
typedef struct Tree Tree;

struct Profile {
	char *name;
	char *number;
};

struct Tree {
	Prof* Data;
	Tree* rht;
	Tree* lft;
};

int recognize(char *command) {
	if(!strcmp(command, "INSERT"))
		return 1;
	if(!strcmp(command, "FIND"))
		return 2;
	return 0;
}

Prof *prof_add() {
	Prof *newNode = (Prof*)malloc(sizeof(Prof));
	newNode->name = (char*)malloc(128*sizeof(char));
	newNode->number = (char*)malloc(128*sizeof(char));
	return newNode;
}

void prof_clear(Prof *node) {
	if(node) {
		free(node->name);
		free(node->number);
		free(node);
	}
}

Tree *insert(Tree *book, Prof* Node) {
	if(!book) {
		book = (Tree*) malloc(sizeof(Tree));
		book->lft = NULL;
		book->rht = NULL;
		book->Data = Node;
		return book;
	}
	int cmp_res = strcmp(book->Data->name, Node->name);
	if(cmp_res == 0) {
		printf("Changed. Old value = %s", book->Data->number);
		free(book->Data);
		book->Data = Node;
		return book;
	}
	if(cmp_res > 0) {
		book->rht = insert(book->rht, Node);
	}
	else {
		book->lft = insert(book->lft, Node);
	}
	return book;
}

Prof *find(Tree *book, Prof *Node) {
	if(!book)
		return NULL;
	int cmp_res = strcmp(book->Data->name, Node->name);
	if( !cmp_res)
		return (book->Data);
	if( cmp_res > 0)
		return find(book->rht, Node);
	else
		return find(book->lft, Node);
	return NULL;
}

void clear(Tree *book) {
	if(book) {
		if(book->rht)
			clear(book->rht);
		if(book->lft)
			clear(book->lft);
		prof_clear(book->Data);
		free(book);
	}
}

int main() {
	Tree *book = NULL;
	char command[256] = "START";
	Prof *newNode;
	Prof *Node;
	while(strcmp(command, "EXIT")) {
		scanf("%s", command);
		switch(recognize(command)) {
			case INS :
				newNode = prof_add();
				scanf("%s %s", (newNode->name), (newNode->number));
				book = insert(book, newNode);
				break;
			case FND :
				newNode = prof_add();
				scanf("%s", newNode->name);
				Node = find(book, newNode);
				if(!Node)
					printf("NO");
				else
					printf("number : %s", Node->number);
				break;
		}
	}
	clear(book);
	free(newNode);
	return 0;
}
