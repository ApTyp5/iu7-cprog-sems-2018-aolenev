#include "liu7st.h"

// STEST --> START TEST
// STEST рекомендуется ставить сразу после открывающей скобки функции
#define     STEST       printf("%d --> %s(): ", __LINE__, __func__)

// PVERD --> PRINT VERDICT
#define     PVERD(ftype, res, exp_res)   printf(#ftype"\t"#ftype"\t%s\n", res, exp_res, \
    res == exp_res ? "SUCCESS" : "FAIL")


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
    
    int res = SUCCESS;
    int exp_res = lst1.first->data != data_ptr_1 || lst1.last->data != data_ptr_2;
    // Почему не :
    // int exp_res = *(int *)(lst1->first.data) != data1 // etc
    // То есть, если lst1 содержит указатель на структуру liu7st_element *first, то запись 
    // 'lst1.first' должна означать неразыменованный указатель на структуру в то время как
    // 'lst1->first' есть сама структура first, в которой уже можно найти указатель на data.
    // Однако компилятор забраковал первый логичный с моей точки зрения вариант, и каким-то 
    // образом получает указатель на data через неразыменованный указатель на предшествующую
    // ей структуру

    PVERD(%d, res, exp_res);
}
    

    
