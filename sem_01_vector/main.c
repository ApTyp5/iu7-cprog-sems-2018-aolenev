#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

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
    DARR arr = create();
    print(arr);
    for(int i = 0; i < 20; i++)
    {
        append(arr, 777);
    }
    print(arr);
    printf("%d\n", arr[0]); //10
    printf("%d\n", arr[1]); //???
    printf("%d\n", arr[2]); //777?
    return 0;
}
