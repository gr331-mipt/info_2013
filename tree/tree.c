/*
 * tree.c
 *
 *  Created on: 23 нояб. 2013 г.
 *      Author: ALTAIR
 */

#include "tree.h"

Tree *tree_addnode(Tree_type Value) {
	Tree *newNode = (Tree*) malloc(sizeof(Tree));
	newNode->Value = Value;
	newNode->parent = NULL;
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->child = NULL;
	return newNode;
}

Tree *tree_addchild(Tree *parent, Tree *child) {
	if(parent == NULL || child == NULL)
		return NULL;
	Tree *lastChild = parent->child;
	while(lastChild != NULL && lastChild->next != NULL)
		lastChild = lastChild->next;
	lastChild->next = child;
	child->prev = lastChild;
	child->parent = parent;
	return child;
}
