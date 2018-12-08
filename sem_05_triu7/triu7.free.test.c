#include "triu7.h"
#include <stdio.h>
#include <stdlib.h>

int test_free(triu7_ptr *tree)
{
    triu7_free(tree);

    if (*tree == NULL)
        return 1;
    else
        return 0;
}


int main(void)
{
    printf("Total tests : %d\n", 1);
    triu7_ptr tree = malloc(sizeof(triu7_node));
    triu7_ptr node1 = malloc(sizeof(triu7_node));
    triu7_ptr node2 = malloc(sizeof(triu7_node));
    triu7_ptr node3 = malloc(sizeof(triu7_node));

    node1->data = malloc(sizeof(int));
    node2->data = malloc(sizeof(int));
    node3->data = malloc(sizeof(int));
    node1->leavs = malloc(sizeof(liu7st));
    node2->leavs = malloc(sizeof(liu7st));
    node3->leavs = malloc(sizeof(liu7st));
    *(node1->leavs) = liu7st_create();
    *(node2->leavs) = liu7st_create();
    *(node3->leavs) = liu7st_create();
    node1->con_wei = darriu7_create(0);
    node2->con_wei = darriu7_create(0);
    node3->con_wei = darriu7_create(0);

    tree->data = malloc(sizeof(int));
    tree->leavs = malloc(sizeof(liu7st));
    *(tree->leavs) = liu7st_create();
    liu7st_append(tree->leavs, node1);
    liu7st_append(tree->leavs, node2);
    liu7st_append(tree->leavs, node3);
    tree->con_wei = darriu7_create(3);
    (tree->con_wei)[0] = 1;
    (tree->con_wei)[1] = 3;
    (tree->con_wei)[2] = 5;

    printf("%d\n", test_free(&tree));

//    int *data = malloc(sizeof(int));
//    tree = triu7_create(data);
//    printf("%d\n", test_free(tree));

    return 0;
}
