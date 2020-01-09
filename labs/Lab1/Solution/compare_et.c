#include "storage.h"



ORDER compare (Job j1 , Job j2)
{
 if (j1.et < j2.et) return LESSER;
 else if (j1.et > j2.et) return GREATER;
 else if (j1.et == j2.et) return EQUAL;
}

