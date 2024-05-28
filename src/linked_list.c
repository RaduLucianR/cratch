#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

struct LinkedList * linklst_create()
{
    struct LinkedList * llist = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    llist->size = 0;
    llist->head = NULL;
    llist->tail = NULL;
    
    return llist;
}

bool linklst_isEmpty(struct LinkedList * linklst)
{
    return linklst->size == 0;
}

void linklst_add(struct LinkedList * linklst, int value)
{
    if (linklst_isEmpty(linklst) == 1)
    {
        linklst->head = (struct ListNode *) malloc(sizeof(struct ListNode));
        linklst->head->value = value;
        linklst->tail = linklst->head;
        linklst->head->next = linklst->tail;
        linklst->size += 1;
        return;
    }

    if (linklst_isEmpty(linklst) == 0)
    {
        struct ListNode * new_node = (struct ListNode *) malloc(sizeof(struct ListNode));

        new_node->value = value;
        new_node->next = NULL;
        linklst->tail->next = new_node;
        linklst->tail = linklst->tail->next;
        linklst->size += 1;
    }
}

void linklst_remove(struct LinkedList * linklst, int value)
{
    if (linklst_isEmpty(linklst) == 1)
    {
        printf("LinkedList is empty, nothing to remove!");
        return;
    }

    struct ListNode * h = linklst->head;

    if (h->value == value)
    {
        linklst->head = linklst->head->next;
        free(h);
        return;
    }

    while(h->next != NULL)
    {
        if (h->next->value == value)
        {
            struct ListNode * temp = h->next;
            h->next = h->next->next;
            free(temp);
            return;
        }

        if (h->next->value != value)
        {
            h = h->next;
        }
    }

    if (h->value == value)
    {
        h = NULL;
        return;
    }

    printf("Value not found, nothing to remove!");
}

int linklst_get(struct LinkedList * linklst, int index)
{
    if (linklst_isEmpty(linklst) == 1)
    {
        printf("LinkedList is empty, nothing to give!");
        return 1;
    }

    unsigned counter = 0;
    struct ListNode * h = linklst->head;

    while (h != NULL)
    {
        if (counter == index)
        {
            return h->value;
        }

        counter += 1;
        h = h->next;
    }

    return 1;
}

void linklst_print(struct LinkedList * linklst)
{
    if (linklst_isEmpty(linklst) == 1)
    {
        printf("LinkedList is empty, nothing to print!");
        return;
    }

    printf("[");

    struct ListNode * h = linklst->head;

    while(h->next != NULL)
    {
        printf("%i, ", h->value);
        h = h->next;
    }

    printf("%i]\n", h->value);
}