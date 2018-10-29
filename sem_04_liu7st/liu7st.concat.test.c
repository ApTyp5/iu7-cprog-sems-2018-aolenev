#include "liu7st.h"

// STEST --> START TEST
// STEST рекомендуется ставить сразу после открывающей скобки функции
#define     STEST       printf("%d --> %s(): ", __LINE__, __func__)

// PVERD --> PRINT VERDICT
#define     PVERD(ftype, res, exp_res)   printf(#ftype"\t"#ftype"\t%s\n", res, exp_res, \
    res == exp_res ? "IU7_SUCCESS" : "IU7_FAIL")


void tst_1_liu7st_concat();

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
    
    int res = IU7_SUCESS;
    int exp_res = liu7st_compare(ans, exp_ans, int_cmp) == 0 ? IU7_SUCCESS : IU7_FAIL;

    PVERD(%d, res, exp_res);
}
    

    
