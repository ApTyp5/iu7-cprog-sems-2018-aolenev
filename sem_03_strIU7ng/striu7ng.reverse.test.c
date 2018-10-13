#include "strIU7ng.h"

int check(striu7ng structn, striu7ng structend)
{
    structn = reverse(structn);

    for (int i = 0; i < (structn.len); i++)
        if (structn.head[i] != structend.head[i])
            return ERR_DEFAULT;
            
    return SUCCESS;
}

int striu7ng_reverse_test1(int *err_cnt)
{
    striu7ng struct1 = striu7ng_create("abcdef");
    striu7ng structend = striu7ng_create("fedcba");

    if (check(struct1, structend) != SUCCESS)
        return ERR_DEFAULT;

    (*err_cnt)++;
    return SUCCESS;
}

int striu7ng_reverse_test2(int *err_cnt)
{
    striu7ng struct2 = striu7ng_create("a");
    striu7ng structend = striu7ng_create("a");

    if (check(struct2, structend) != SUCCESS)
        return ERR_DEFAULT;

    (*err_cnt)++;
    return SUCCESS;
}

int striu7ng_reverse_test3(int *err_cnt)
{
    striu7ng struct3 = striu7ng_create("ab");
    striu7ng structend = striu7ng_create("ba");

    if (check(struct3, structend) != SUCCESS)
        return ERR_DEFAULT;

    (*err_cnt)++;
    return SUCCESS;
}

int striu7ng_reverse_test4(int *err_cnt)
{
    striu7ng struct4 = striu7ng_create("");
    striu7ng structend = striu7ng_create("");

    if (check(struct4, structend) != SUCCESS)
        return ERR_DEFAULT;

    (*err_cnt)++;
    return SUCCESS;
}

int main(void)
{
    int err_cnt = 0;

    striu7ng_reverse_test1(&err_cnt);
    striu7ng_reverse_test2(&err_cnt);
    striu7ng_reverse_test3(&err_cnt);
    striu7ng_reverse_test4(&err_cnt);

    if (4 == err_cnt)
        return SUCCESS;

    printf("Failed tests");
    return ERR_DEFAULT;
}
