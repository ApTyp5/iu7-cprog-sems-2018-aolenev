typedef struct triu7 triu7;

struct triu7
{
    void *data;
    int num_of_leaves;
    triu7 **leavs;
}

// Ильясов, Игнатьев
void triu7_free(triu7 tree);

// Коновалова, Неклепаева
int triu7_create(void);






    