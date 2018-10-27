#ifndef __LIU7ST_H
#define __LIU7ST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    void *data;
    liu7st *prev;
    liu7st *next;
} liu7st_element

typedef struct
{
    int size;
    liu7st_element *first;
    liu7st_element *last;
} liu7st

// Sid
liu7st liu7st_create();

// Nabiev
void liu7st_free(liu7st list);

// Kosor
void liu7st_append(truiu7st *list, striu7st_element striu7st_element;

// Moroz
int liu7st_remove(striu7st *list, int i);

// Nekl Konov
int liu7st_insert(liu7st *list, liu7st_element element, int i);

// Potatoch Drozdov
lui7st liu7st_concat(liu7st first, liu7st second);

// Pudov Grunk
int liu7st_has_cycle(liu7st list);

// Gorb Chern
lui7st liu7st_revert(liu7st list);

// Ilyasov Ignatiev
void liu7st_sort(liu7st *list);

#ifndef

