#include "cycle.h"

int testCyclic(LinkedList ls) {
	if(ls -> count < 1)
		return 0;
	else if(ls -> count < 3 && ls -> tail -> next == ls -> head)
		return 1;
	else if (ls -> count < 3)
		return 0;
		
	NODE* hore;
	NODE* tort;
	hore = ls -> head -> next -> next;
	tort = ls -> head -> next;
	if(hore == tort)
			return 1;
	while(hore -> next != NULL && hore -> next -> next != NULL) {
		if(hore == tort || hore -> next == tort)
			return 1;
		hore = hore -> next -> next;
		tort = tort -> next;
	}
	return 0;
}
