#include "stack.h"

void push(struct linkedList* head, int x) {
    insertFirst(head, x);
}

NODE* pop(struct linkedList* head) {
    return deleteFirst(head);
}