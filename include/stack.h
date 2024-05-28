/*
@author Radu Lucian Radulescu (radulucianr)

Simple stack data structure.
*/
#include <stdbool.h>

struct Stack {
    int top;
    unsigned size;
    int * array;
};

/**

*/
struct Stack * stack_create(unsigned size);

/**

*/
void stack_push(struct Stack * stack, int value);

/**

*/
void stack_pop(struct Stack * stack);

/**

*/
int stack_peek(struct Stack * stack);

void stack_print(struct Stack * stack);

/** @brief Checks if stack is full.
    @param stack to be checked
    @return true if full, false if not full
*/
bool stack_isFull(struct Stack * stack);


/** @brief Checks if stack is empty.
    @param stack to be checked
    @return true if empty, false if not empty
*/
bool stack_isEmpty(struct Stack * stack);