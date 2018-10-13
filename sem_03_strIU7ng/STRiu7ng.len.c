#include "srtIU7ng.h"
int strIU7ng_len( strIU7ng string )
{
	//Минимальная строчка как минимум один, иначе ошибка
    if ( string.len < 1)
	{
	    return 	ERR_DEFAULT;
	}
	
	
	// проверим  вдруг это какая то сломаная строчка
	if ( string.head == NULL)
	{
	    return 	ERR_DEFAULT;
	}
	return string.len;
	
}
