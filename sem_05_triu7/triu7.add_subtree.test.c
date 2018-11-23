#include <triu7.h>


int triu7_add_subtree_test(triu7_ptr root, triu7_ptr sub, int w)
{
    int res = 0;

    if (triu7_add_subtree(root, sub, w) == 0 && (root->con_wei)[0] == w && root->leavs->first->data == sub)
        res = 1;

    return res;
}


int main(void)
{
    int data1 = 1;
    int data2 = 2;
    triu7_ptr root = triu7_create(&data1);
    triu7_ptr subtree = triu7_create(&data2);

    triu7_add_subtree_test(root, subtree, 3);

    triu7_free(&root);

    return 0;
}

