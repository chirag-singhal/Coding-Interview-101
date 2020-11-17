#include "cycle.h"

int testCyclic(LinkedList ls) {
	if(ls -> count < 1)
		return 0;
	
    NODE* prev = NULL;
	NODE* curr = ls -> head;
	NODE* next = curr -> next;

    if(curr == next)
        return 1;
    else {
        while(next != NULL) {
            if(next == ls -> head) 
                return 1;

            curr -> next = prev;

            prev = curr;
            curr = next;
            next = next -> next;
        }
    }
	return 0;
}
