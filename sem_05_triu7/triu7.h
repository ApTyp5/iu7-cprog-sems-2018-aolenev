#ifndef __TRIU7_H__
#define __TRIU7_H__



typedef struct triu7 triu7;


struct triu7
{
    void *data;
    int num_of_leaves;
    triu7 **leavs;
};

// Ильясов, Игнатьев
void triu7_free(triu7 tree);

// Коновалова, Неклепаева
triu7 triu7_create(void *data);

// Пудов, Грунковский
int triu7_has_cycle(triu7 tree);

// Дроздов, Степанов
int apply(triu7 tree_head, void func(void *data))

// Мороз, Москаленко
int triu7_size(triu7 tree);

// Горбунов
int depth(triu7 tree);

#endif




    