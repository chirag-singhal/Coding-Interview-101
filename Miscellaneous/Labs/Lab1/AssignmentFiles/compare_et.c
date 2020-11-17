/***********file:   compare_at.c *********/

#include "storage.h"
#include "compare.h"

ORDER compare (Job j1 , Job j2)
{
 if (j1.et < j2.et)          //2M
       return LESSER;
 else if (j1.et > j2.et)     //2M
       return GREATER;
 else if (j1.et == j2.et)    //2M 
       return EQUAL;
}

