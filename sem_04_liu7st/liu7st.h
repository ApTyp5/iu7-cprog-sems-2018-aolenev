#ifndef __LIU7ST_H
#define __LIU7ST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    void *data;
    lui7st *prev;
    liu7st *next;
} liu7st_element

typedef struct
{
    int size;
    liu7st_element *first;
    liu7st_element *last;
} liu7st

liu7st create();

// Nabiev
void free(liu7st list);

// Kosor
void append(truiu7st *list, striu7st_element striu7st_element;

// Moroz
int remove(striu7st *list, int i);

// Nekl Konov
int insert(liu7st *list, liu7st_element element, int i);

// Potatoch Drozdov
lui7st concat(liu7st first, liu7st second);

// Pudov Grunk
int has_cycle(liu7st list);

// Gorb Chern
lui7st revert(liu7st list);

// Ilyasov Ignatiev
void sort(liu7st *list);

#ifndef

