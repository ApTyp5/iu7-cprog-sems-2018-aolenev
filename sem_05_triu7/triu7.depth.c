/**
 @file triu7.depth.c
 @author Dimon G
 @date 10 Nov 2018
 */

#include "triu7.h"

static int depth = 0;

/**
 @fn static void count_depth(int n, triu7_ptr node)
 
 @param n [in] - текущая глубина
 @param node [in] - текущее положение в дереве
 */
static void count_depth(int n, triu7_ptr node)
{
    liu7st_element *now = node->leavs->first;
    
    while (now != NULL && now->data != NULL)
    {
        count_depth(n + 1, (triu7_ptr)(now->data));
        now = now->next;
    }
    
    if (n > depth)
        depth = n;
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
    
    int n = 0;
    
    count_depth(n, node);
    
    return depth;
}
