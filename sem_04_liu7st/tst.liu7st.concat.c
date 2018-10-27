
#include "tst.liu7st.concat.h"
#include <stdio.h>
#include "liu7st.h"



int main()
{
    tst_1_liu7st_concat();

    return 0;
}

int byte_cmp(void *byte1, void *byte2, int len)
{
    char *ch1 = byte1;
    char *ch2 = byte2;

    for (int i = 0; i < len; i++)
        if (*ch1++ != *ch2++)
            return NON_HAPPY_END;
    return HAPPY_END;
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
    int exp_res = byte_cmp(ans->first.data, exp_ans->first.data, len * sizeof(liu7st);

    PVERD(%d, res, exp_res);
}
    

    
