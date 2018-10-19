#include "srtIU7ng.h"
int strIU7ng_len( strIU7ng string )
{
    //Минимальная строчка как минимум ноль, иначе ошибка
    if ( string.len < 0 )
    {
        return ERR_DEFAULT;
    }


    // проверим  вдруг это какая то сломаная строчка
    if ( string.head == NULL )
    {
        return ERR_DEFAULT;
    }
    return string.len;

}
