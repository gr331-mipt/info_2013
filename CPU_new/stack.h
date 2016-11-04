/*
 * stack.h
 *
 *  Created on: 03 февр. 2014 г.
 *      Author: ALTAIR
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdlib.h>
#include <stdio.h>
#include "assert.h"

struct Stack;
typedef double Stack_type;
typedef struct Stack Stack;

struct Stack {
	Stack_type Value;
	Stack *prev;
};

Stack *Stack_Initialize();
Stack *Stack_Destroy(Stack **stack);

void Stack_Dump(Stack *stack);

int        Stack_Push(Stack **stack, Stack_type Value);
Stack_type Stack_Pop (Stack **stack);

#endif /* STACK_H_ */
