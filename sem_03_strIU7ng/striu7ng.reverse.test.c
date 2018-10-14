#include "strIU7ng.h"

int check(strIU7ng structn, strIU7ng structend)
{
    structn = reverse(structn);

    for (int i = 0; i < (structn.len); i++)
        if (structn.head[i] != structend.head[i])
            return ERR_DEFAULT;

    return SUCCESS;
}

int strIU7ng_reverse_test1(int *err_cnt)
{
    strIU7ng struct1 = strIU7ng_create("abcdef");
    strIU7ng structend = strIU7ng_create("fedcba");

    if (check(struct1, structend) != SUCCESS)
        return ERR_DEFAULT;

    (*err_cnt)++;
    return SUCCESS;
}

int strIU7ng_reverse_test2(int *err_cnt)
{
    strIU7ng struct2 = strIU7ng_create("a");
    strIU7ng structend = strIU7ng_create("a");

    if (check(struct2, structend) != SUCCESS)
        return ERR_DEFAULT;

    (*err_cnt)++;
    return SUCCESS;
}

int strIU7ng_reverse_test3(int *err_cnt)
{
    strIU7ng struct3 = strIU7ng_create("ab");
    strIU7ng structend = strIU7ng_create("ba");

    if (check(struct3, structend) != SUCCESS)
        return ERR_DEFAULT;

    (*err_cnt)++;
    return SUCCESS;
}

int strIU7ng_reverse_test4(int *err_cnt)
{
    strIU7ng struct4 = strIU7ng_create("");
    strIU7ng structend = strIU7ng_create("");

    if (check(struct4, structend) != SUCCESS)
        return ERR_DEFAULT;

    (*err_cnt)++;
    return SUCCESS;
}

int main(void)
{
    int err_cnt = 0;

    strIU7ng_reverse_test1(&err_cnt);
    strIU7ng_reverse_test2(&err_cnt);
    strIU7ng_reverse_test3(&err_cnt);
    strIU7ng_reverse_test4(&err_cnt);

    if (4 == err_cnt)
        return SUCCESS;

    printf("Failed tests");
    return ERR_DEFAULT;
}
