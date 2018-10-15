#include <stdlib.h>
#include "strIU7ng.h"

/*
Функция очищает память, выделенную под строку.

@param *string [in]
*/
void strIU7ng_free(strIU7ng *string)
{
    if (!string->head)
        free(string->head);
    string->head = NULL;
    string->len = 0;
}
