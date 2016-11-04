/*
 * stack.c
 *
 *  Created on: 03 февр. 2014 г.
 *      Author: ALTAIR
 */

#include "stack.h"

Stack *Stack_Initialize() {
	return NULL;
}

Stack *Stack_Destroy(Stack **stack) {
	ASSERT(stack != NULL);
	while( !*stack ) {
		Stack *deleted = *stack;
		*stack = (*stack)->prev;
		deleted->Value = 0xBAD;
		deleted->prev = NULL;
		free(deleted);
	}
	return NULL;
}

void Stack_Dump(Stack *stack) {

}
