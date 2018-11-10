#include <stdio.h>
#include <stdlib.h>

#include "darriu7.h"

/**
create()

append(x)
pop(i):x
insert(i, x)
count()
remove(x)
sort()

**/

int main(void)
{
    DARR darr = darriu7_create(0);
    darriu7_print(darr);

    for(int i = 0; i < 25; i++)
    {
        darr = darriu7_append(darr, i);
    }

    darriu7_print(darr);
    printf("darr len = %d\n", darriu7_len(darr));
    printf("darr[-2] = %d\n", darr[-2]); 
    printf("darr[3] = %d\n", darr[3]);

    darriu7_release(darr);

    return 0;
}
