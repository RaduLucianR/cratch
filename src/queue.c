#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct Queue * createQueue(unsigned size)
{
    struct Queue * queue = (struct Queue *) malloc(sizeof(struct Queue));
    queue->size = size;
    queue->tail = -1;
    queue->array = malloc(sizeof(int) * queue->size);
}

bool queue_isFull(struct Queue * queue)
{
    return queue->tail == queue->size - 1;
}

bool queue_isEmpty(struct Queue * queue)
{
    return queue->tail == -1;
}

void queue_add(struct Queue * queue, int value)
{
    if (queue_isFull(queue) == 1) 
    {
        printf("Queue is full, cannot add element!\n");
        return;
    }

    queue->tail += 1;
    queue->array[queue->tail] = value;
}

/*
    Complexity O(n) in the size of the current
    number of elements in the queue.
*/
void queue_pop(struct Queue * queue)
{
    if (queue_isEmpty(queue) == 1) 
    {
        printf("Queue is empty, nothing to pop!\n");
        return;
    }

    int current_tail = queue->tail;

    for (int i = 0; i < current_tail; i ++)
    {
        queue->array[i] = queue->array[i + 1];
    }

    queue->array[current_tail] = 0;
    queue->tail -= 1;
}

int queue_get(struct Queue * queue)
{
    if (queue_isEmpty(queue) == 1) 
    {
        printf("Queue is empty, nothing to give!\n");
        return 1;
    } 

    int current_head = queue->array[0];

    queue_pop(queue);

    return current_head;
}

int queue_peek(struct Queue * queue)
{
    if (queue_isEmpty(queue) == 1) 
    {
        printf("Queue is empty, nothing to see!\n");
        return 1;
    } 

    return queue->array[0];
}

void queue_print(struct Queue * queue)
{
    if (queue_isEmpty(queue) == 1) 
    {
        printf("Queue is empty, nothing to print!\n");
        return;
    } 

    printf("[");

    for(int i = 0; i < queue->tail; i ++) 
    {
        printf("%i, ", queue->array[i]);
    }

    printf("%i]\n", queue->array[queue->tail]);
}