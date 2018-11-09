#ifndef __LIU7ST_H
#define __LIU7ST_H

#include <stdio.h>
#include <stdlib.h>

#define FREE_LIST 0

#define SUCCESS 0
#define FAILED  -1

#define SET_ERROR   -2
#define WRONG_INDEX -3
#define WRONG_LIST  -4

#define LIU7ST_CYCLED            (1 << 0)
#define LIU7ST_BACK_CYCLED       (1 << 1)
#define LIU7ST_LAST_UNREACHABLE  (1 << 2)
#define LIU7ST_FIRST_UNREACHABLE (1 << 3)
#define LIU7ST_INVALID_LAST      (1 << 4)
#define LIU7ST_INVALID_FIRST     (1 << 5)
#define LIU7ST_MISSED_FIRST      (1 << 6)
#define LIU7ST_MISSED_LAST       (1 << 7)
#define LIU7ST_NONLINEAR         (1 << 8)
#define LIU7ST_INVALID_COUNT     (1 << 9)

#define LIU7ST_FOREACH(TYPE, ITER, LIST_PTR) \
    for (TYPE ITER = liu7st_begin(LIST_PTR); ITER != NULL; ITER = liu7st_next(ITER))

typedef struct liu7st_element liu7st_element;

struct liu7st_element
{
    void *data;
    liu7st_element *prev;
    liu7st_element *next;
};

typedef struct
{
    int size;
    liu7st_element *first;
    liu7st_element *last;
} liu7st;

// Sidenko
liu7st liu7st_create();

// Nabiev & Kyprii
void liu7st_free(liu7st *list, void (*free_data)(void*));

// Drozdov
void liu7st_append(liu7st *list, void *data);

// Moroz & Zlyh
int liu7st_remove(liu7st *list, int i);

// Neklepaeva & Konovalova
int liu7st_insert(liu7st *list, void *data, int i);

// Potapchyk & Drozdov
liu7st liu7st_concat(liu7st first, liu7st second);

// Pudov & Grunkovsky
int liu7st_has_cycle(liu7st list);

// Gorbynov &  Chernenko
liu7st liu7st_revert(liu7st list);

// Ilyasov & Ignatiev
void liu7st_sort(liu7st *list, int (*compare)(const void*, const void*));

// Kosorykov & Coraev & Furdik
void *liu7st_get(liu7st list, int i);

// Kosorykov & Coraev & Furdik
int liu7st_set(liu7st list, int i, void *data);

// Drozdov
void *liu7st_begin(liu7st *list);
void *liu7st_end(liu7st *list);
void *liu7st_next(void *iterator);
void *liu7st_prev(void *iterator);

// Drozdov
int liu7st_check(liu7st list);

// Stepanov
int liu7st_print(liu7st list, void (*print_data)(const void*));

#endif
