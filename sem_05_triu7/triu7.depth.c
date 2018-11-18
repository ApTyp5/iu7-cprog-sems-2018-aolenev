/**
 @file triu7.depth.c
 */

#include "triu7.h"

/**
 @fn void count_depth(int *max, int n, triu7_ptr node)
 
 @param max [in, out] - указатель на найденную максимальную глубину
 @param n [in] - текущая глубина
 @param node [in] - текущее положение в дереве
 */
void count_depth(int *max, int n, triu7_ptr node)
{
    liu7st_element *now = node->leavs->first;
    
    while (now != NULL && now->data != NULL)
    {
        count_depth(max, n + 1, (triu7_ptr)(now->data));
        now = now->next;
    }
    
    if (n > *max)
        *max = n;
}

/**
int triu7_depth(triu7_ptr node)
 
 @param node [in] - узел дерева
 
 @return Возвращает глубину дерева
 */
int triu7_depth(triu7_ptr node)
{
    if (node == NULL)
        return IU7_FAIL;
    
    if (triu7_has_cycle(node))
        return IU7_FAIL;
    
    int size = 0;
    int n = 0;
    
    count_depth(&size, n, node);
    
    return size;
}
