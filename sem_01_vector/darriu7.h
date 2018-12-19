#ifndef __VECTOR_H
#define __VECTOR_H

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE        10
#define PRIVAT_DATA_SIZE    3

// Yeld codes
#define IU7_FAIL    -1
#define IU7_SUCESS  0

// Чтобы понять смысл следующи define-ов,
// смотрите ф-ю 'create'
#define CUR_LEN (((int *)darr)[-1])
#define MAX_LEN (((int *)darr)[-2])
#define EL_SIZE (((int *)darr)[-3])

typedef void * darriu7;


/*  Создание дин. массива длины len  */
/*************************************/
// --> Вход : длина массива
// --> Выход: указатель на начало массива при успешном
// выделении памяти и корректности входных даннх, 
// NULL иначе
darriu7 darriu7_create(int len, int size_of_el);


/*  Вывод текущей дины      */
/****************************/
// --> Вход : дин. массив
// --> Выход: длина массива
// в случае корректных данных,
// IU7_FAIL иначе
int darriu7_len(darriu7 darr);

    
    

/*  Вывод coдержимого динамического массива на экран  */
/******************************************************/
// --> Вход : дин. массив
void darriu7_int_print(darriu7 darr);
void darriu7_double_print(darriu7 darr);


/* Добавление элемента в конец дин. массива  */
/*********************************************/
// --> Вход : дин. массив, значение элемента,
// который хотим добавить
// --> Выход: адрес получившегося дин. массива.
darriu7 darriu7_append(darriu7 darr, void *x);



/* Освобождение памяти из-под дин. массива */
/*******************************************/
// --> Вход: дин. массив.
void darriu7_release(darriu7 darr);


#endif
