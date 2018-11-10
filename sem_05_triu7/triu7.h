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
int triu7_create(void);

// Пудов, Грунковский
int has_cycle(triu7 tree);

// Дроздов, Степанов
int apply(triu7 tree_head, void func(void *data))

// Мороз, Москаленко
int size(triu7 tree);

// Горбунов
int depth(triu7 tree);




    