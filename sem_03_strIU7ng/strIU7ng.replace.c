/**
 @file strIU7ng.replace.c
 */

#include "strIU7ng.h"

/**
 @fn int my_strcmp(const char *str_1, const char *str_2)
 @brief Проверяет одинаковые ли строки
 
 @param str_1 [in] - указатель на первую строку
 @param str_2 [in] - указатель на вторую строку
 
 @return Возвращает SUCCESS, если строки равны, иначе ERR_DEFAULT
 */

int compare_str(const char *str_1, const char *str_2)
{
    int size_1, size_2;
    
    for (size_1 = 0; str_1[size_1] != '\0'; size_1++);
    for (size_2 = 0; str_2[size_2] != '\0'; size_2++);
    
    if (size_1 != size_2)
        return ERR_DEFAULT;
    
    for (int i = 0; i < size_1; i++)
        if (str_1[i] != str_2[i])
            return ERR_DEFAULT;
    
    return SUCCESS;
}

/**
 @fn strIU7ng strIU7ng_replace(strIU7ng source, strIU7ng search, strIU7ng replace)
 @brief Функция заменяет подстроку search на подстроку replace во всей строке source

 @param source [in]
 @param search [in]
 @param replace [in]

 @return Функция возвращает получившуюся строку с заменами
 */

strIU7ng strIU7ng_replace(strIU7ng source, strIU7ng search, strIU7ng replace)
{
    char *find = NULL;
    char *beg = NULL;
    char *end = NULL;
//    int n;
//    int l;
    char *new = NULL;

    if (source.len < 0 || source.head == NULL)
        return source;

    if (search.len < 0 || search.head == NULL)
        return source;

    if (compare_str(search.head, replace.head) == 0)
        return source;
    
    find = strIU7ng_find_substr(source, search);

    while (find != NULL)
    {
        beg = malloc((find - source.head) * sizeof(char));

        for (int i = 0; i < find - source.head; i++)
        {
            beg[i] = source.head[i];
        }

//        n = source.len - (find - source.head) - search.len;
        end = malloc((source.len - (find - source.head) - search.len) * sizeof(char));

        if (!end)
        {
            free(beg);
            return source;
        }

        for (int i = 0; i < source.len - (find - source.head) - search.len; i++)
        {
            end[i] = (find + search.len)[i];
        }

//        l = source.len + (replace.len - search.len);

        new = malloc(source.len + (replace.len - search.len + 1) * sizeof(char));

        if (!new)
        {
            free(end);
            free(beg);
            return source;
        }

        for (int i = 0; i < find - source.head; i++)
        {
            new[i] = beg[i];
        }

        for (int i = 0; i < replace.len; i++)
        {
            new[i + find - source.head] = replace.head[i];
        }

        for (int i = 0; i < source.len - (find - source.head) - search.len; i++)
        {
            new[i + find - source.head + replace.len] = end[i];
        }

        new[source.len + (replace.len - search.len)] = '\0';

        source = strIU7ng_create(new);

        find = strIU7ng_find_substr(source, search);

        free(new);
        free(end);
        free(beg);
    }

    return source;
}
