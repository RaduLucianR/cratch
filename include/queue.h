/*
@author Radu Lucian Radulescu

Simple Queue data structure.

All operations are O(1), but pop is O(n) because
the entire queue must be shifted by 1.
*/
#include <stdbool.h>

struct Queue {
    int tail;
    unsigned size;
    int * array;
};

struct Queue * createQueue(unsigned size);
void queue_add(struct Queue * queue, int value);
bool queue_isEmpty(struct Queue * queue);
bool queue_isFull(struct Queue * queue);
void queue_pop(struct Queue * queue);
int queue_get(struct Queue * queue);
int queue_peek(struct Queue * queue);
void queue_print(struct Queue * queue);