#include "tst.liu7st.concat.h"
#include "liu7st.h"



int main()
{
    tst_1_liu7st_concat();

    return 0;
}

int int_cmp(void *int1, void *int2)
{
    return *int1 - int2;
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
    int exp_res = compare(ans, exp_ans,) == 0 ? HAPPY_END : NON_HAPPY_END;

    PVERD(%d, res, exp_res);
}
    

    
