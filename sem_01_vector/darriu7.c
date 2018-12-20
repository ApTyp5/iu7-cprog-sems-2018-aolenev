#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "darriu7.h"

/**
 * \brief Создание универсального динамического массива
 *
 * \param [in] len начальная длина
 * \param [in] size_of_el размер элемента массива в байтах
 *
 * \return указатель на начало массива(его нужно присвоить
 * указателю нужного нам типа) или NULL при ошибке выделения 
 * памяти.
 */
darriu7 darriu7_create(int len, size_t size_of_el)
{
    if (len  < 0) 
        return NULL;

    if (len == 0)
        len = INITIAL_SIZE;

    int *darr; 

    if ((darr = malloc((PRIVAT_DATA_SIZE) * sizeof(int) + 
                        len * size_of_el)) == NULL)
        return NULL;

    *darr++ = size_of_el;
    *darr++ = len; 
    *darr++ = 0;

    // Итог:
    // darr[-1] = CUR_LEN
    // darr[-2] = MAX_LEN
    // darr[-3] = EL_SIZE

    return darr;
}

/// Улучшенный вариант strcpy, принимающий любые указатели
static inline void mycpy(void *dest, void *source, size_t size)
{
    for (int i = 0; i < size; i++, *(char *)dest++ = *(char *)source++);
}

/**
 * \brief Вывод текущей длины массива
 *
 * \return длина массива в случае, если на вход послупил
 * действующий массив, IU7_FAIL иначе
 */
int darriu7_len(darriu7 darr)
{
    if (!darr)
        return IU7_FAIL;
    
    return CUR_LEN;
}




/**
 * \brief Вывод содержимого динамического массива
 *
 * ф-я предназначена для массива вещественных
 * чисел двойной точности
 */
void darriu7_double_print(darriu7 darr)
{
    printf("[");

    for(int i = 0; i < CUR_LEN; i++)
    {
        printf("%lf, ", *((double *)darr + i));
        printf(" ");
    }

    for(int i = CUR_LEN; i < MAX_LEN; i++)
    {
        printf("* ");
    }

    printf("]\n");
}



/**
 * \brief Вывод содержимого динамического массива
 *
 * ф-я предназначена для массива целых
 * чисел, занимающих 4 байта
 */
void darriu7_int_print(darriu7 darr)
{
    printf("[");

    for(int i = 0; i < CUR_LEN; i++)
    {
        printf("%d, ", *((int *)darr + i));
        printf(" ");
    }

    for(int i = CUR_LEN; i < MAX_LEN; i++)
    {
        printf("*, ");
    }

    printf("]\n");
}

/**
 * \brief добавление элемента в конец динамического массива
 *
 * \param [in] darr сам массив
 * \param [in] x указатель на добавляемый элемент
 * \param [out] rc указатель на переменную состояния(может быт равен NULL)
 *
 * \return код состояния программы: IU7_FAIL при ошибке 
 *   выделения памяти(массив остается без изменений), 
 *   IU7_SUCCESS иначе, если элемент был успешно добавлен.
 */
darriu7 darriu7_append(darriu7 darr, void *x, int *rc)
{
    *rc = IU7_SUCCESS;

    if (CUR_LEN == MAX_LEN)
    {
        darriu7 save_copy = darr;

        int new_max_len = 2 * MAX_LEN;
        int old_cur_len = CUR_LEN;
        int old_el_size = EL_SIZE;

        darr = realloc((int *)darr - PRIVAT_DATA_SIZE, 
            new_max_len * EL_SIZE + PRIVAT_DATA_SIZE * sizeof(int));

        if (!darr)
        {
            if (*rc)
                *rc = IU7_FAIL;

            return save_copy;
        }

        // Если не понятно, что написано внизу, смотри ф-ю create
        mycpy( (int *)darr, &old_el_size, sizeof(int));
        mycpy( (int *)darr + 1, &new_max_len, sizeof(int));
        mycpy( (int *)darr + 2, &old_cur_len, sizeof(int));

        darr = (void *)( (int *)darr + PRIVAT_DATA_SIZE);
    }
    
    mycpy( (char *)darr + CUR_LEN * EL_SIZE, x, EL_SIZE);

    CUR_LEN++;

    return darr;
}


/**
 * \brief Освобождение памяти из-под массива
 */
void darriu7_release(darriu7 darr)
{
    free((int *)darr - PRIVAT_DATA_SIZE);
}



