#include "liu7st.tst.concat.h"
#include "liu7st.h"



int main()
{
    tst_1_liu7st_concat();

    return 0;
}

int int_cmp(void *ptr1, void *ptr2)
{
    int *int1 = (int *)ptr1;
    int *int2 = (int *)ptr2;
    return *int1 - *int2;
}

void tst_1_liu7st_concat()
{
    STEST;

    int data1 = 5;
    int data2 = 10;
    int len = 2;

    void *data_ptr_1 = &data1;
    void *data_ptr_2 = &data2;

    liu7st lst1 = liu7st_create();
    liu7st lst2 = liu7st_create();

    liu7st exp_ans = liu7st_create();
    liu7st_append(&exp_ans, data_ptr_1);
    liu7st_append(&exp_ans, data_ptr_2);

    liu7st_append(&lst1, data_ptr_1);
    liu7st_append(&lst2, data_ptr_2);

    liu7st ans = liu7st_concat(lst1, lst2);
    
    int res = HAPPY_END;
    int exp_res = liu7st_compare(ans, exp_ans, int_cmp) == 0 ? HAPPY_END : NON_HAPPY_END;

    PVERD(%d, res, exp_res);
}
    

    
