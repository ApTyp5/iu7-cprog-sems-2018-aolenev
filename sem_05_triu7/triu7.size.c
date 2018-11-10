#include "triu7.h"

int triu7_size(triu7 *tree)
{
	n = 0;
	
	for (int i = 0; i < tree->num_of_leaves; i++)
		n += triu7_size((tree->leavs)[i])
    
	return n + 1;
}