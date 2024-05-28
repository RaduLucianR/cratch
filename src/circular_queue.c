#include "circular_queue.h"
#include <stdio.h>
#include <stdlib.h>

struct CircQ * circq_create(unsigned size)
{
    struct CircQ * circq = (struct CircQ *) malloc(sizeof(struct CircQ));
    circq->size = size;
    circq->head = -1;
    circq->tail = -1;
    circq->count = 0;
    circq->array = (int *) malloc(sizeof(int) * circq->size);

    return circq;
}

bool circq_isFull(struct CircQ * circq)
{
    return circq->count == circq->size;
}

bool circq_isEmpty(struct CircQ * circq)
{
    return circq->count == 0;
}

void circq_add(struct CircQ * circq, int value)
{
    if (circq_isFull(circq) == 1)
    {
        printf("Circular queue is full, cannot add more elements!\n");
        return;
    }

    if (circq_isEmpty(circq) == 1)
    {
        circq->head = 0;
        circq->tail = 0;
        circq->array[circq->tail] = value;
        circq->count += 1;
        return;
    }

    circq->tail = (circq->tail + 1) % circq->size;
    circq->array[circq->tail] = value;
    circq->count += 1;
}

void circq_pop(struct CircQ * circq)
{
    if (circq_isEmpty(circq) == 1)
    {
        printf("Circular queue is empty, nothing to pop!\n");
        return;
    }

    circq->array[circq->head] = 0;
    circq->head = (circq->head + 1) % circq->size;
    circq->count -= 1;
}

void circq_print_array(struct CircQ * circq)
{
    if (circq_isEmpty(circq) == 1) 
    {
        printf("Circular queue is empty, nothing to print!\n");
        return;
    } 

    printf("[");

    for(int i = 0; i < circq->size - 1; i ++) 
    {
        printf("%i, ", circq->array[i]);
    }

    printf("%i]\n", circq->array[circq->size - 1]);
}

void circq_print(struct CircQ * circq)
{
    if (circq_isEmpty(circq) == 1) 
    {
        printf("Circular queue is empty, nothing to print!\n");
        return;
    } 

    if (circq->head <= circq->tail)
    {
        printf("[");

        for(int i = circq->head; i < circq->tail; i ++) 
        {
            printf("%i, ", circq->array[i]);
        }

        printf("%i]\n", circq->array[circq->tail]);
    }

    if (circq->head > circq->tail)
    {
        printf("[");

        for(int i = circq->head; i < circq->size; i ++) 
        {
            printf("%i, ", circq->array[i]);
        }

        for(int i = 0; i < circq->tail; i ++) 
        {
            printf("%i, ", circq->array[i]);
        }

        printf("%i]\n", circq->array[circq->tail]);
    }
}