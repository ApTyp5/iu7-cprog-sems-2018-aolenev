/**
revert test
 */

#include <stdio.h>
#include <stdlib.h>
#include "liu7st.h"

#define NOT_EQ 1
#define SUCCESS 0

int cmp_list_int(liu7st a, liu7st b)
{
    if (a.size != b.size)
        return NOT_EQ;
    
    liu7st_element *beg_1;
    liu7st_element *beg_2;
    liu7st_element *end_1;
    liu7st_element *end_2;

    beg_1 = a.first;
    end_1 = a.last;

    beg_2 = b.first;
    end_2 = b.last;

    while (beg_1 != end_1 && beg_2 != end_2)
    {
        if (*(int*)(beg_1->data) != *(int*)(beg_2->data))
            return NOT_EQ;

        if (beg_1->next == NULL && beg_2->next != NULL)
            return NOT_EQ;

        if (beg_1->next != NULL && beg_2->next == NULL)
            return NOT_EQ;

        beg_1 = beg_1->next;
        beg_2 = beg_2->next;
    }

    return SUCCESS;
}

int test_1()
{
    liu7st source;
    liu7st expect;
    liu7st result;

    source.size = 3;
    expect.size = 3;
    
    liu7st_element a;
    liu7st_element aa;
    liu7st_element aaa;
    
    int ai = 1;
    int aai = 2;
    int aaai = 3;

    a.next = &aa;
    a.prev = NULL;
    a.data = &(ai);
    
    aa.next = &aaa;
    aa.prev = &a;
    aa.data = &(aai);
    
    aaa.next = NULL;
    aaa.prev = &aa;
    aaa.data = &(aaai);

    source.first=&a;
    source.last=&aaa;
    
    liu7st_element b;
    liu7st_element bb;
    liu7st_element bbb;
    
    b.next = &aa;
    b.prev = NULL;
    b.data = &(aaai);
    
    bb.next = &aaa;
    bb.prev = &a;
    bb.data = &(aai);
    
    bbb.next = NULL;
    bbb.prev = &aa;
    bbb.data = &(ai);

    expect.first=&b;
    expect.last=&bbb;

    result = liu7st_revert(source);

    return cmp_list_int(result, expect);
}

int main()
{
    int errorcount = 0;
    
    printf("Testing revert \n");
    
    errorcount += test_1();
    printf("%d errors encountered in 1 revert tests\n", errorcount);

    return errorcount;
}
