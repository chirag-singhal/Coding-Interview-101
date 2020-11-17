
#include "storage.h"

ORDER compare (Job j1 , Job j2)
{
 if (j1.at < j2.at) return LESSER;
 else if (j1.at > j2.at) return GREATER;
 else if (j1.at == j2.at) return EQUAL;
}

