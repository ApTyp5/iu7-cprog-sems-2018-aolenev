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
    printf("Int massive demonstration\n");

    int *ints = darriu7_create(0, sizeof(int));
    darriu7_int_print(ints);

    for(int i = 0; i < 25; i++)
    {
        ints = darriu7_append(ints, &i);
    }

    darriu7_int_print(ints);
    printf("darr len = %d\n", darriu7_len(ints));
    printf("darr[-2] = %d\n", ints[-2]); 
    printf("darr[3] = %d\n", ints[3]);

    darriu7_release(ints);

    printf("\n");
    printf("\n");
    printf("\n");


    printf("Double massive demonstration\n");

    double *doubles = darriu7_create(0, sizeof(double));

    darriu7_double_print(doubles);

    for(int i = 0; i < 25; i++)
    {
        double g = 1.1;

        doubles = darriu7_append(doubles, &g);
    }

    darriu7_double_print(doubles);


    printf("darr len = %d\n", darriu7_len(doubles));
    printf("darr[-1] = %d\n", ((int *)doubles)[-1]);
    printf("darr[-2] = %d\n", ((int *)doubles)[-2]); 
    printf("darr[-3] = %d\n", ((int *)doubles)[-3]);

    darriu7_release(doubles);

    return 0;
}
