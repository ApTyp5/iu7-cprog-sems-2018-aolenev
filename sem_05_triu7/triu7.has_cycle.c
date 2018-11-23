#include "triu7.h"
#include <stdlib.h>

// Количество элементов для массива указателей на triu7_ptr
#define DEFAULT_TRIU7_POINTERS_ARRAY_SIZE 256

// Ситуация, при которой указатель добавляется повторно - найден цикл
#define REPEATED_POINTER 777

/**
* \struct Множество посещенных узлов
* \param pointers Массив из triu7_ptr
* \param count Число элементов в массиве узлов
* \param allocated Число аллоцированных элементов под массив узлов
*/
typedef struct {
    triu7_ptr *pointers;
    int count;
    size_t allocated;
} pointers_set_t;

/**
* \brief Инициализация множества посещенных узлов
* \param set Указатель на множество. *set должен быть равен NULL
* \detail Происходит выделение памяти под *set и под массив pointers
* \return IU7_SUCCESS - если память выделена успешно и проинициализирован
* указатель. Иначе IU7_FAIL
*/
static int init_pointers_set(pointers_set_t **set)
{
    if (set == NULL)
    {
        return IU7_FAIL;
    }

    *set = (pointers_set_t *) malloc(sizeof(pointers_set_t));
    if (*set == NULL)
    {
        return IU7_FAIL;
    }

    (*set)->pointers = (triu7_ptr *) malloc(DEFAULT_TRIU7_POINTERS_ARRAY_SIZE * sizeof(triu7_ptr));
    if ((*set)->pointers == NULL)
    {
        free(*set);
        return IU7_FAIL;
    }

    (*set)->allocated = DEFAULT_TRIU7_POINTERS_ARRAY_SIZE;
    (*set)->count = 0;

    return IU7_SUCCESS;
}

/**
* \brief Проверка на переполнение в множестве
* \param set Указатель на структуру множества
* \return IU7_TRUE - если с добавлением нового элемента множество достигает
* максимального размера. Иначе IU7_FAIL. В том числе и при некорректных входных
* данных
*/
static int is_full(pointers_set_t *set)
{
    if (set == NULL)
    {
        return IU7_FALSE;
    }

    return (set->count + 1 >= set->allocated) ? IU7_TRUE : IU7_FALSE;
}

/**
* \brief Очищение памяти под set
* \param set Указатель на структуру множества
* \detail Происходит очищение выделенной памяти на массив указателей и на саму
* структуру множества
*/
static void free_set(pointers_set_t *set)
{
    if (set == NULL)
    {
        return;
    }

    free(set->pointers);
    free(set);
}

/**
* \brief Изменение размера выделенной памяти под массив указателей множества set
* \param set Указатель на множество
* \detail Происходит увеличение массива pointers вдвое + 1
* \return IU7_SUCCESS - если память выделена успешно. Иначе IU7_FAIL
*/
static int resize(pointers_set_t *set)
{
    if (set == NULL)
    {
        return IU7_FAIL;
    }

    triu7_ptr *buf = realloc(set->pointers, (set->allocated * 2 + 1) * sizeof(triu7_ptr));
    if (buf == NULL)
    {
        free_set(set);
        return IU7_FAIL;
    }

    set->pointers = buf;
    set->allocated = set->allocated * 2 + 1;
    return IU7_SUCCESS;
}

/**
* \brief Проверка на то, содержится ли pointer во множестве set
* \param set Множество, в котором находится соответствие
* \param pointer Узел дерева
* \return IU7_TRUE - если pointer найден. Иначе IU7_FALSE
*/
static int contains(pointers_set_t *set, triu7_ptr pointer)
{
    if (set == NULL || pointer == NULL)
    {
        return IU7_FALSE;
    }

    for (int i = 0; i < set->count; i++)
    {
        if (*(set->pointers + i) == pointer)
        {
            return IU7_TRUE;
        }
    }

    return IU7_FALSE;
}

/**
* \brief Добавление нового pointer во множество set
* \param set Множество, в которое хотим добавить
* \param pointer Узел дерева, который пытаемся добавить
* \return IU7_SUCCESS - если pointer успешно добавлен в set. Если произошла
* внутренняя ошибка, то IU7_FAIL. В противном случае возвращаем REPEATED_POINTER
*/
static int add_pointer(pointers_set_t *set, triu7_ptr pointer)
{
    int rc = IU7_SUCCESS;
    if (set == NULL || pointer == NULL)
    {
        return IU7_FAIL;
    }

    if (contains(set, pointer) == IU7_FALSE)
    {
        if (is_full(set) == IU7_TRUE)
        {
            rc = resize(set);
            if (rc != IU7_SUCCESS)
            {
                return rc;
            }
        }

        *((set->pointers) + set->count) = pointer;
        set->count = set->count + 1;
    }
    else
    {
        return REPEATED_POINTER;
    }

    return rc;
}

int triu7_has_cycle(triu7_ptr node)
{
    if (node == NULL)
    {
        return IU7_FALSE;
    }

    int rc = IU7_SUCCESS;
    pointers_set_t *set = NULL;

    rc = init_pointers_set(&set);
    if (rc != IU7_SUCCESS)
    {
        return IU7_FALSE;
    }

    rc = add_pointer(set, node);
    if (rc != IU7_SUCCESS)
    {
        return IU7_TRUE;
    }

    for (int i = 0; i < set->count; i++)
    {
        liu7st *children = set->pointers[i]->leavs;
        if (children == NULL)
        {
            return IU7_FALSE;
        }

        if (liu7st_has_cycle(*children) == IU7_TRUE)
        {
            return IU7_TRUE;
        }

        liu7st_element *children_head = children->first;
        for (int j = 0; j < children->size && children_head != NULL; j++)
        {
            rc = add_pointer(set, (triu7_ptr) children_head->data);
            if (rc == IU7_FAIL)
            {
                return IU7_FALSE;
            }
            else if (rc == REPEATED_POINTER)
            {
                return IU7_TRUE;
            }

            children_head = children_head->next;
        }
    }

    free_set(set);
    return IU7_FALSE;
}
