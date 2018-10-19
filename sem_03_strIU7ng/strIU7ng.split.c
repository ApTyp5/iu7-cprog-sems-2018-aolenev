#include <stdlib.h>

#include "strIU7ng.h"

/**
 * Replaces all occurrences of one character with another
 * \param [in] str Source string
 * \param [in] what Character that should be replaced
 * \param [in] on_what Character with which previous character should be replaced
 * \return Returns number of characters were replaced
 */
int byte_replace(strIU7ng str, char what, char on_what)
{   
    int n = 0;
    for (int i = 0; i < strIU7ng_len(str); i++)
        if (str.head[i] == what)
        {
            n++;
            str.head[i] = on_what;
        }

    return n;
}

/**
 * Splits string by delimiter into an array of substrings
 * \param [in] string Source string
 * \param [in] delimiter Delimiter symbol
 * \param [out] new_size Amount of strings source string was splitted into
 * \return Returns array of substrings
 */
strIU7ng* strIU7ng_split(strIU7ng string, char delimiter, int *new_size)
{
    int n = 1 + byte_replace(string, delimiter, 0);

    strIU7ng *array = malloc(sizeof(strIU7ng) * n);
    *new_size = 0;

    if (array != NULL)
    {
        char *beg = string.head;

        for (int i = 0; i < n; i++)
        {
            array[i] = strIU7ng_create(beg);
            beg += strIU7ng_len(array[i]) + 1;
        }

        *new_size = n;
    }

    byte_replace(string, 0, delimiter);

    return array;
}
