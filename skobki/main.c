/*
 * main.c
 *
 *  Created on: 22 нояб. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>

#define ASSERT(cond) \
if (!(cond)) {\
    printf("All gone bad: %s, file: %s, line: %d\n", #cond, __FILE__, __LINE__);\
	abort();\
    }
struct Stack;
typedef char Stack_Type;
typedef struct Stack Stack;
void Stack_Destroy(Stack* stack);

#define ASSERT_STACK_OK(stack) \
if(stack == NULL || stack->counter >= stack->size || (stack->counter < -1)) {\
	printf("Stack is BAD!!! file: %s, line: %d\n", __FILE__, __LINE__);\
	Stack_Destroy(stack);\
	abort();\
}

#define func_end(code,stack) \
		Stack_Destroy(stack);\
		return code;

struct Stack {
	int counter;
	int size;
	Stack_Type elements[1];
};

Stack* Stack_Initialize(int size) {
	ASSERT(size > 0);
	Stack* NewStack = (Stack*) malloc(sizeof(Stack) + (size - 1) * sizeof(Stack_Type));
	NewStack->size = size;
	NewStack->counter = -1;
	NewStack->elements[0] = '\0';
	ASSERT_STACK_OK(NewStack);
	return NewStack;
}

void Stack_Destroy(Stack* stack) {
	ASSERT(stack != NULL);
	int i;
	Stack* destroyStack = stack;
	for( i = 0; i < destroyStack->size; i++) {
		destroyStack->elements[i] = '\0';
	}
	destroyStack->counter = 0xBAD;
	destroyStack->size = 0xBAD;
	free(destroyStack);
}

int Stack_Push(Stack* stack, const Stack_Type NewValue) {
	ASSERT_STACK_OK(stack);
	stack->counter++;
	ASSERT_STACK_OK(stack);
	stack->elements[stack->counter] = NewValue;
	return 0;
}

Stack_Type Stack_Pop(Stack* stack) {
	ASSERT_STACK_OK(stack);
	if(stack->counter == -1)
		return '\0';
	Stack_Type Value = stack->elements[stack->counter];
	stack->elements[stack->counter] = '\0';
	stack->counter--;
	ASSERT_STACK_OK(stack);
	return Value;
}

int Stack_Dump(Stack* stack) {
	ASSERT_STACK_OK(stack);
	printf("Stack ok size: %d counter: %d \n", stack->size, stack->counter);
	int i;
	for( i = 0; i < stack->counter; i++){
		printf("%d : %c \n", i, stack->elements[i]);
	}
	return 0;
}

char anti(char c) {
	switch(c) {
		case '(':
			return ')';
		case '[':
			return ']';
		case '{':
			return '}';
		case '<':
			return '>';
	}
	return ' ';
}

int check() {
	Stack *bkt = Stack_Initialize(102400);
	char c;
	while(1) {
		scanf("%c", &c);
		if(c == '\n')
			break;
		if(c == '{' || c == '<' || c == '[' || c == '(')
			Stack_Push(bkt, c);
		else {
			char c1 = Stack_Pop(bkt);
			if(c != anti(c1)){
				func_end(0,bkt);
			}
		}
	}
	if(bkt->counter >= 0) {
		func_end(0,bkt);
	}
	func_end(1,bkt);
	return 1;
}

int main() {
	if( check() )
			printf("YES");
		else
			printf("NO");
	return 0;
}
