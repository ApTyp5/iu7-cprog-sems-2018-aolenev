#include <stdlib.h>

#include "strIU7ng.h"

void strIU7ng_free(strIU7ng string)
{
    if (!string.head)
        free(string.head);
    string.head = NULL;
    string.len = 0;
}
