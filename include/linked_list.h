/**
 * 
*/

#include <stdbool.h>

struct ListNode {
    int value;
    struct ListNode * next;
};

struct LinkedList {
    unsigned size;
    struct ListNode * head;
    struct ListNode * tail;
};

struct LinkedList * linklst_create();
unsigned linklst_size(struct LinkedList * linklst);
void linklst_add(struct LinkedList * linklst, int value);
int linklst_get(struct LinkedList * linklst, int index);
void linklst_remove(struct LinkedList * linklst, int value);
bool linklst_isEmpty(struct LinkedList * linklst);
void linklst_print(struct LinkedList * linklst);