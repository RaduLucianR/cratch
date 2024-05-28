/*
@author Radu Lucian Radulescu

Circular fixed-size queue data structure.

*/
#include <stdbool.h>

struct CircQ {
    int head;
    int tail;
    unsigned count;
    unsigned size;
    int * array;
};

struct CircQ * circq_create(unsigned size);
void circq_add(struct CircQ * circq, int value);
bool circq_isEmpty(struct CircQ * circq);
bool circq_isFull(struct CircQ * circq);
void circq_pop(struct CircQ * circq);
int circq_get(struct CircQ * circq);
int circq_peek(struct CircQ * circq);
void circq_print(struct CircQ * circq);