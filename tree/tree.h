/*
 * tree.h
 *
 *  Created on: 23 нояб. 2013 г.
 *      Author: ALTAIR
 */

#ifndef TREE_H_
#define TREE_H_

#include <stdio.h>
#include <stdlib.h>

struct Tree;

typedef struct Tree Tree;
typedef int Tree_type;

struct Tree {
	Tree *parent;
	Tree *prev;//prev child of parent
	Tree *next;//next child of parent
	Tree_type Value;
	Tree *child;
};

Tree *tree_addnode(Tree_type Value);

#endif /* TREE_H_ */
