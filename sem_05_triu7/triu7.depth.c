/**
 @file
 */
#include "triu7.h"

/**
 @fn void count_depth(int *max, int n, triu7 tree)
 
 @param max [in, out] - указатель на размер максимальной длины
 @param n [in] - текущая глубина
 @param tree [in] - текущее положение в дереве
 */
void count_depth(int *max, int n, triu7 tree)
{
    for (int i = 0; i < tree->num_of_leaves; i++)
        count_depth(max, n + 1, *(*((tree->leaves) + i)));
    
    if (n > *max)
        *max = n;
}

/**
 @fn int triu7_depth(triu7 tree)
 
 @param tree [in] - голова дерева
 
 @return Возвращает глубину дерева
 */
int triu7_depth(triu7 tree)
{
    int size = 0;
    int n = 0;
    
    count_depth(&size, n, tree);
    
    return size;
}
