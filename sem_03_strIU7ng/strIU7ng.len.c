#include "srtIU7ng.h"
/**
\class strIU7ng_len

\brief Функция возвращающая длинну строки.

\param string Строка, чья длинна будет возвращена.

 
\return Длинна строки или код ошибки.
*/
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
