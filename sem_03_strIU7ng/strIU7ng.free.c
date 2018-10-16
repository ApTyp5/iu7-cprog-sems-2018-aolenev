#include <stdlib.h>
#include "strIU7ng.h"

/**
 * @fn strIU7ng_free(strIU7ng *string)
 * @brief Очищает строку и освобождает выделенную память
 * @param string указатель на строку
 */
void strIU7ng_free(strIU7ng *string)
{
    if (!string->head)
        free(string->head);
    string->head = NULL;
    string->len = 0;
}
