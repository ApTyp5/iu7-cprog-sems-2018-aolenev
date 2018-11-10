#ifndef __VECTOR_H
#define __VECTOR_H

#define INITIAL_SIZE        10
#define PRIVAT_DATA_SIZE    2

// Yeld codes
#define IU7_FAIL    -1
#define IU7_SUCESS  0

// Чтобы понять смысл следующи define-ов,
// смотрите ф-ю 'create'
#define CUR_LEN (darr[-1])
#define MAX_LEN (darr[-2])

#define DARR int*

/*  Создание дин. массива длины len  */
/*************************************/
// --> Вход : длина массива
// --> Выход: указатель на начало массива при успешном
// выделении памяти и корректности входных даннх, 
// NULL иначе
DARR darriu7_create(int len)
{
    if (len  < 0) 
        return NULL;

    if (len == 0)
        len = INITIAL_SIZE;

    DARR darr; 

    if ((darr= malloc((len + PRIVAT_DATA_SIZE) * sizeof(int))) == NULL)
        return NULL;

    *darr++ = len; 
    *darr++ = 0;

    // Итог:
    // darr[-1] = CUR_LEN
    // darr[-2] = MAX_LEN

    return darr;
}

/*  Вывод текущей дины      */
/****************************/
// --> Вход : дин. массив
// --> Выход: длина массива
// в случае корректных данных,
// IU7_FAIL иначе
int darriu7_len(DARR darr)
{
    if (!darr)
        return IU7_FAIL;
    
    return CUR_LEN;
}

/*  Вывод coдержимого динамического массива на экран  */
/******************************************************/
// --> Вход : дин. массив
void darriu7_print(DARR darr)
{
    printf("[");

    for(int i = 0; i < CUR_LEN; i++)
    {
        printf("%d ", darr[i]);
    }

    for(int i = CUR_LEN; i < MAX_LEN; i++)
    {
        printf("* ");
    }

    printf("]\n");
}

/* Добавление элемента в конец дин. массива  */
/*********************************************/
// --> Вход : дин. массив, значение элемента,
// который хотим добавить
// --> Выход: адрес получившегося дин. массива.
DARR darriu7_append(DARR darr, int x)
{

    if(CUR_LEN == MAX_LEN)
    {
        int old_max_len = MAX_LEN;
        int old_cur_len = CUR_LEN;

        darr = realloc(darr - PRIVAT_DATA_SIZE, 
            (2 * MAX_LEN + PRIVAT_DATA_SIZE) * sizeof(int));
        if (!darr)
            return NULL;

        // Если не понятно, что написано внизу, смотри ф-ю create
        *darr++ = 2 * old_max_len;
        *darr++ = old_cur_len;
    }
    
    darr[CUR_LEN++] = x;

    return darr;
}


/* Освобождение памяти из-под дин. массива */
/*******************************************/
// --> Вход: дин. массив.
void darriu7_release(DARR darr)
{
    free(darr - PRIVAT_DATA_SIZE);
}



#endif
