#include <stdlib.h>
#include "strIU7ng.h"

/*!
Создает строку new_str, содержащую multiply повторений подстроки source.

@param source [in]
@param multiply [in]

@return Возвращает new_str в случае успешного выполнения,
source - в случае ошибки.
*/

strIU7ng mult(strIU7ng source, int multiply)
{
    // проверка входных данных
    if (source.len <= 0 || source.head == NULL || multiply <= 0)
        return source;

    // объявление и инициализация новой строки
    strIU7ng new_str;
    new_str.len = source.len * multiply;
    new_str.head = malloc(new_str.len * sizeof(char) + 1 * sizeof(char));

    // заполнение новой строки
    for (int i = 0; i < new_str.len; i++)
        new_str.head[i] = source.head[i % source.len];
    new_str.head[new_str.len] = 0;

    return new_str;
}
