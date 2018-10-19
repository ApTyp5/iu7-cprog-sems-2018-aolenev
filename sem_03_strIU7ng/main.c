#include "strIU7ng.h"

int main()
{
    strIU7ng str, search, replace;
    strIU7ng *split_str;
    strIU7ng res;

    int size_split_str = 0;
    char *_str = "Hello World! It is sem_o3)o))))";
    char *_search = "o";
    char *_replace = "";
    char *first_sub;

    str = strIU7ng_create(_str);
    search = strIU7ng_create(_search);
    replace = strIU7ng_create(_replace);

    printf("%s\n", str.head);

    printf("%d\n", strIU7ng_len(str));

    split_str = strIU7ng_split(str, '!', &size_split_str);
    for (int i = 0; i < size_split_str; i++)
        printf("%s%s", split_str[i].head, (i != size_split_str - 1 ? "\n" : ""));

    res = strIU7ng_replace(str, search, replace);
    printf("%s\n", res.head);

    res = strIU7ng_reverse(str);
    printf("%s\n", res.head);

    res = strIU7ng_mult(str, 3);
    printf("%s\n", res.head);

    res = strIU7ng_concat(str, search);
    res = strIU7ng_concat(res, search);
    printf("%s\n", res.head);

    first_sub = strIU7ng_find_substr(str, search);
    printf("%s\n", first_sub);

    strIU7ng_free(&str);
    strIU7ng_free(&search);
    strIU7ng_free(&replace);
    strIU7ng_free(&res);

    for (int i = 0; i < size_split_str; i++)
        free(&split_str[i].head);

    return 0;
}
