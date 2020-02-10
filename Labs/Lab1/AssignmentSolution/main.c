#include <stdio.h>
#include "seqListOps.h"

int main(void)
{
 int i;
 seqarr seq;
 joblist arr;
 initialize_elements (arr);
 //printjoblist(arr);
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (arr,seq);
// printseqlist (seq[0]);
// printseqlist (seq[1]);
// printseqlist (seq[2]);
 copy_sorted_ele (seq , arr); 
 //printf ("Sorted List\n");
 printjoblist(arr);
}
 
