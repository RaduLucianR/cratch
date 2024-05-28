/*
@author Radu Lucian Radulescu

Simple fixed-size Queue data structure.

*/
#include <stdbool.h>

struct Queue {
    int tail;
    unsigned size;
    int * array;
};

struct Queue * queue_create(unsigned size);
void queue_add(struct Queue * queue, int value);
bool queue_isEmpty(struct Queue * queue);
bool queue_isFull(struct Queue * queue);
void queue_pop(struct Queue * queue);
int queue_get(struct Queue * queue);
int queue_peek(struct Queue * queue);
void queue_print(struct Queue * queue);