#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/*
    Memory complexity is:
    O(int + unsigned + (int *) + int * size) = 32 * (size + 4) bits
*/
struct Stack * stack_create(unsigned size)
{
    struct Stack * stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (int *) malloc(sizeof(int) * stack->size);
    return stack;
}

/*
    Time complexity is O(1)
*/
bool stack_isEmpty(struct Stack * stack)
{
    if (stack->top == -1) {
        return 1;
    }

    return 0;
}

/*
    Time complexity is O(1)
*/
bool stack_isFull(struct Stack * stack)
{
    if (stack->top == stack->size - 1) {
        return 1;
    }

    return 0;
}

/*
    Time complexity is O(stack->top) 
    i.e. the number of elements in the stack.
*/
void stack_print(struct Stack * stack)
{
    if (stack_isEmpty(stack) == 1) {
        printf("Stack is empty, nothing to print!\n");
        return;
    }

    printf("[");

    for (int i = 0; i < stack->top; i ++)
    {
        printf("%d, ", stack->array[i]);
    }

    printf("%d]\n", stack->array[stack->top]);
}

/*
    Time complexity is O(1)
*/
void stack_push(struct Stack * stack, int value)
{
    if (stack_isFull(stack) == 1) {
        printf("Stack is full, cannot push further!\n");
        return;
    }

    stack->top += 1;
    stack->array[stack->top] = value;
}

/*
    Time complexity is O(1)
*/
void stack_pop(struct Stack * stack)
{
    if (stack_isEmpty(stack) == 1) {
        printf("Stack is empty, nothing to pop!\n");
        return;
    }

    stack->array[stack->top] = 0;
    stack->top -= 1;
}

/*
    Time complexity is O(1)
*/
int stack_peek(struct Stack * stack)
{
    if (stack_isEmpty(stack) == 1) {
        printf("Stack is empty, nothing to see!\n");
        return 1;
    }

    return stack->array[stack->top];
}