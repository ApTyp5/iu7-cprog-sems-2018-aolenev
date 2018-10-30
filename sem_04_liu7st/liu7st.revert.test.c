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

        beg_1 = beg_1->next;
        beg_2 = beg_2->next;
    }

    return SUCCESS;
}

int negative_test_free_list()
{
    printf("negative_test_free_list: ");
    liu7st source;
    liu7st expect;
    liu7st result;
    
    source.first = NULL;
    source.last = NULL;
    
    source.size = 0;
    expect.size = 0;
    
    expect.first = NULL;
    expect.last = NULL;
    
    result = liu7st_revert(source);
    
    if (result.size != expect.size || result.first != expect.first ||\
        result.last != expect.last)
    {
        printf("Test failed\n");
        return NOT_EQ;
    }
    
    printf("Test success\n");
    return SUCCESS;
}

int positive_test()
{
    printf("positive_test: ");
    liu7st source;
    liu7st expect;
    liu7st result;

    source.size = 3;
    expect.size = 3;
    
    liu7st_element a;
    liu7st_element aa;
    liu7st_element aaa;
    
    int ai = 1, aai = 2, aaai = 3;

    a.next = &aa;
    a.prev = NULL;
    a.data = &(ai);
    
    aa.next = &aaa;
    aa.prev = &a;
    aa.data = &(aai);
    
    aaa.next = NULL;
    aaa.prev = &aa;
    aaa.data = &(aaai);

    source.first = &a;
    source.last = &aaa;
    
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

    expect.first = &b;
    expect.last = &bbb;

    result = liu7st_revert(source);

    if (cmp_list_int(result, expect))
    {
        printf("Test failed\n");
        return NOT_EQ;
    }
    else
    {
        printf("Test success\n");
        return SUCCESS;
    }
}

int negative_test_free_pointer()
{
    printf("negative_test_free_pointer: ");
    liu7st source;
    liu7st expect;
    liu7st result;
    
    source.first = NULL;
    source.last = NULL;
    
    source.size = 3;
    expect.size = 3;
    
    expect.first = NULL;
    expect.last = NULL;
    
    result = liu7st_revert(source);
    
    if (result.size != expect.size || result.first != expect.first ||\
        result.last != expect.last)
    {
        printf("Test failed\n");
        return NOT_EQ;
    }
    
    printf("Test success\n");
    return SUCCESS;
}


int main()
{
    int errorcount = 0;
    
    printf("Testing liu7st_revert \n");
    
    errorcount += positive_test();
    errorcount += negative_test_free_list();
    errorcount += negative_test_free_pointer();
    
    printf("%d errors encountered in 3 revert tests\n", errorcount);

    return errorcount;
}
