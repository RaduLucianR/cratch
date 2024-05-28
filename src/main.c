#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "circular_queue.h"

int main()
{
  struct CircQ * circq = circq_create(3);
  circq_add(circq, 5);
  circq_add(circq, 3);
  circq_add(circq, 4);
  circq_pop(circq);
  circq_add(circq, 6);
  circq_pop(circq);
  circq_pop(circq);
  circq_add(circq, 7);
  circq_add(circq, 8);
  circq_pop(circq);
  circq_print(circq);
  return 0;
}
