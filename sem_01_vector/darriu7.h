#ifndef __VECTOR_H
#define __VECTOR_H

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE        10
#define PRIVAT_DATA_SIZE    3

// Yeld codes
#define IU7_FAIL    -1
#define IU7_SUCCESS  0

// Чтобы понять смысл следующи define-ов,
// смотрите ф-ю 'create'
#define CUR_LEN (((int *)darr)[-1])
#define MAX_LEN (((int *)darr)[-2])
#define EL_SIZE (((int *)darr)[-3])

typedef void * darriu7;

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
darriu7 darriu7_create(int len, size_t size_of_el);

/**
 * \brief Вывод текущей длины массива
 *
 * \return длина массива в случае, если на вход послупил
 * действующий массив, IU7_FAIL иначе
 */
int darriu7_len(darriu7 darr);

    
/**
 * \brief Вывод содержимого динамического массива
 */
void darriu7_int_print(darriu7 darr);
void darriu7_double_print(darriu7 darr);

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
darriu7 darriu7_append(darriu7 darr, void *x, int *rc);


/**
 * \brief Освобождение памяти из-под массива
 */
void darriu7_release(darriu7 darr);


#endif
