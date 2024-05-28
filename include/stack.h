/*
@author Radu Lucian Radulescu (radulucianr)

Simple fixed-size stack data structure.
*/
#include <stdbool.h>

struct Stack {
    int top;
    unsigned size;
    int * array;
};

struct Stack * stack_create(unsigned size);
void stack_push(struct Stack * stack, int value);
void stack_pop(struct Stack * stack);
int stack_peek(struct Stack * stack);
void stack_print(struct Stack * stack);
bool stack_isFull(struct Stack * stack);
bool stack_isEmpty(struct Stack * stack);