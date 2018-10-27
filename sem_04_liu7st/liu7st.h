#ifndef __LIU7ST_H
#define __LIU7ST_H

#include <stdio.h>
#include <stdlib.h>

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
void liu7st_free(liu7st *list);

// Drozdov
void liu7st_append(liu7st *list, void *data);

// Moroz & Zlyh
int liu7st_remove(liu7st *list, int i);

// Neklepaeva & Konovalova
void liu7st_insert(liu7st *list, void *data, int i);

// Potapchyk & Drozdov
liu7st liu7st_concat(liu7st first, liu7st second);

// Pudov & Grunkovsky
int liu7st_has_cycle(liu7st list);

// Gorbynov &  Chernenko
liu7st liu7st_revert(liu7st list);

// Ilyasov & Ignatiev
void liu7st_sort(liu7st *list);


// Kosorykov & Coraev & Furdik
void *get(liu7st list, int i);

// Kosorykov & Coraev & Furdik
void set(liu7st list, int i, void *data);

#endif

