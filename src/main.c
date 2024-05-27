#include <stdio.h>
#include "stack.h"

int main()
{
  printf("Hello World!\n");

  struct Stack * stack = stack_create(7);
  stack_print(stack);
  stack_push(stack, 2);
  stack_push(stack, 3);
  stack_print(stack);
  stack_pop(stack);
  stack_pop(stack);
  stack_print(stack);

  return 0;
}
