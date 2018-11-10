
typedef struct triu7 triu7;

struct triu7
{
    void *data;
    int num_of_leaves;
    triu7 **leavs;
}

// Ильясов, Игнатьев
void free(triu7 tree);







    