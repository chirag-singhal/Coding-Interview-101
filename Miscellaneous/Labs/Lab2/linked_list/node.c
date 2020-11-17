// structure definitions
// structure of a linked list node. It contains an element
typedef struct node {
	int element;
	struct node * next;
} NODE;

/* structure of a linked list / head. It stores the count of number of elements
in the list and also a pointer link to the first node of the list. */
struct linkedList {
	int count;
	struct node * first;
};

