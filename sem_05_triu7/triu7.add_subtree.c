#include "triu7.h"

/**
 * @fn triu7_add_subtree(triu7_ptr node, triu7_ptr subroot, int weight)
 * @brief Добавляет поддерево к узлу
 * @param node Узел, к которому добавляется поддерево
 * @param subroot Поддерево
 * @param weight Вес связи узла с поддеревом
 * @return Код выполнения
 */
int triu7_add_subtree(triu7_ptr node, triu7_ptr subroot, int weight)
{
    if (node == NULL || subroot == NULL)
    {
        return IU7_FAIL;
    }

    liu7st_append(node->leavs, subroot);
    node->con_wei = darriu7_append(node->con_wei, weight);

    return IU7_SUCCESS;
}

