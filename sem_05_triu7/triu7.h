#ifndef __TRIU7_H__
#define __TRIU7_H__

#define     SUCCESS         0
#define     FAIL            -1
#define     WRONG_TREE      -2
#define     WRONG_INDEX     -3


typedef struct triu7 triu7;


struct triu7
{
    void *data;
    int num_of_leaves;
    triu7 **leavs;
};

// Ильясов, Игнатьев
// Вход: указатель на дерево
void triu7_free(triu7 *tree);

// Коновалова, Неклепаева
// Вход - указатель на даыыне первого листа
// Выход - первый лист дерева
triu7* triu7_create(void *data);

// Пудов, Грунковский

int triu7_has_cycle(triu7 *tree);

// Дроздов, Степанов
int triu7_apply(triu7 *tree_head, void func(void *data));

// Мороз, Москаленко
int triu7_size(triu7 *tree);

// Горбунов
int triu7_depth(triu7 *tree);

#endif




    
