// C Program for array implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack {
	int top;
	unsigned capacity;
	int* array;
};

struct Stack* createStack(unsigned capacity) {
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));

	return stack;
}

int isFull(struct Stack* stack) {
	return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
	return stack->top == -1;
}

void push(struct Stack* stack, int item) {

	if(isFull(stack)) {
		// you can't add a new object to the stack
		return;
	}
	//Increases top by 1
	stack->array[stack->top++] = item;
	printf("%d pushed to stack\n", item);
}

int pop(struct Stack* stack) {
	if (isEmpty(stack)) {
		// you can't delete an object if there is no stack
		return INT_MIN;
	}

	return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
	if (isEmpty(stack)) {
		// you can't peek if there's no stack
		return INT_MIN;
	}

	return stack->array[stack->top];
}

int main() {
	struct Stack* stack = createStack(100);

	push(stack, 10);
	push(stack, 20);
	push(stack, 30);

	printf("%d popped from stack\n", pop(stack));
	printf("peeking top: %d\n", peek(stack));

	return 0;
}