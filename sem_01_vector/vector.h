#ifndef __VECTOR_H
#define __VECTOR_H

#define INITIAL_SIZE 10

#define DARR int*

int* create()
{
    int* p = malloc(INITIAL_SIZE*sizeof(int)); 

    *p = INITIAL_SIZE;
    *(p+1) = 0;

    return p;
}

void print(int* p)
{
    printf("[");

    for(int i = 2; i < *(p+1) + 2; i++)
    {
        printf("%d ",*(p+i));
    }

    for(int i = *(p+1) + 2; i < *(p) + 1; i++)
    {
        printf("* ");
    }

    printf("]\n");
}

DARR append(DARR arr, int x)
{
    if(*arr == *(arr+1))
    {
        arr = realloc(arr, 2*(*arr)*sizeof(4));
        *arr = 2*(*arr);
    }
    
    *(arr+2+*(arr+1)) = x;
    *(arr+1) = *(arr+1) + 1;

    return arr;
}

void release(DARR arr)
{
    // free(arr);
}



#endif
