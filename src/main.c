#include <stdio.h>
#include "stack.h"
#include "queue.h"

int main()
{
  struct Queue * queue = createQueue(5);
  queue_add(queue, 5);
  queue_add(queue, 3);
  queue_add(queue, 4);
  queue_print(queue);
  int a = queue_peek(queue);
  printf("%i\n", a);
  queue_print(queue);
  a = queue_get(queue);
  printf("%i\n", a);
  queue_print(queue);
  return 0;
}
