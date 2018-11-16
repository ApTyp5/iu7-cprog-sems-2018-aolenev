#ifndef __TRIU7_H__
#define __TRIU7_H__

#define     IU7_TRUE            1
#define     IU7_FALSE           0
#define     IU7_SUCCESS         0
#define     IU7_FAIL            -1
#define     IU7_WRONG_TREE      -2
#define     IU7_WRONG_INDEX     -3


/*  Структура узла дерева   */
/****************************/
// Содержание структуры:
// 1. Указатель на универсальную информацию.
//
// 2. Массив весов связей с "детьми" узла. 
// (берется реализация 1-го семинара)
//
// 3. Список листьев.
// (берется реализация 4-го семинара)
//
// Внимание:
// --> Изначальный узел дерева и является корнем.
// За счет этого корень можно будет легко поменять.
// --> Связь узлов двунаправленная: если в leaves первого узла
// имеется указатель на второй узел, то у второго узла
// будет аналогичный указатель на первый (с весом связей
// аналогично).

typedef struct triu7_node triu7_node;
typedef triu7_node *triu7_ptr;

struct triu7_node
{
    void *data;
    darriu7 *con_wei; // == connection weight
    liu7st *leavs; 
};


/*  Создание дерева  */
/*********************/
// Реализуют: Коновалова, Неклепаева
// Вход - указатель на данные корня
// Выход - указатель на первый корень
// Особенность: при нежелании добавлять
// что-либо в data пользователь передает 
// NULL
triu7 triu7_create(void *data);


/*  Освобождение памяти из-под дерева  */
/***************************************/
// Реализуют: Ильясов, Игнатьев
// Вход: указатель на корень
// Особенность: NULL на входе обрабатывается корректно
void triu7_free(triu7 root);

/*  Добавление листа  */
/**********************/
// Реализуют: ?
// Вход : указатель на узел, куда добавляется лист
//        указатель на data добавляемого листа
//        вес связи узла с добавляемым листом
// Выход: код состояния
int triu7_add(triu7 node, void *new_data, int weight);


/*  Добавление поддерева  */
/**************************/
// Реализуют: ?
// Вход : указатель на узел (куда добавляют)
//        указатель на подкорень (который добавляют)
// Выход: код состояния
int triu7_add_subtree(triu7 node, triu7 subroot);



/*  Проверка на наличие цикла  */
/*******************************/
// Реализуют: Пудов, Грунковский
// Вход: узел дерева
// Выход: IU7_TRUE, если цикл был найден,
// IU7_FALSE иначе. Остальные ошибки обсуждать
// с гит-мастером
int triu7_has_cycle(triu7 node);


/*  Применение функции func ко всей информации дерева  */
/*******************************************************/
// Реализуют: Дроздов, Степанов
// Вход: узел дерева
//       указатель на func
// Выход: код состояния
int triu7_dat_apply(triu7 node, void (*func)(void *data));


/*  Сортировка листьев по возрастанию  */
/*******************************************************/
// Реализуют: ?
// Вход:  узел дерева
// Выход: код состояния
int triu7_leav_sort(triu7 node);


/*  Применение ф-ии критерия ко всей информации дерева  */
/********************************************************/
// Реализуют: ?
// Вход : узел дерева
//        функция-критерий "test"
//        переменная накопления "статистики" out
// Выход: код состояния
int triu7_dat_test(triu7 node, int (*test)(void *data, int *out), int *out);


/*  Нахождения количества элементов в дереве  */
/**********************************************/
// Реализуют: Мороз, Москаленко
// Вход: узел дерева
// Выход: код состояния (<0) при ошибочных данных,
// размер дерева иначе
int triu7_size(triu7 node); // Не забудьте проверить древо на наличие цикла!


/*  Нахождение максимальной глубины дерева  */
/********************************************/
// Реализуют: Горбунов
// Вход: узел дерева
// Выход: код состояния (<0) при ошибочных данных,
// размер дерева иначе
int triu7_depth(triu7 node); // Не забудьте проверить древо на наличие цикла!

/*  Печать дерева  */
/*******************/
// Реализует: Степанов
// Вход: узел дерева, ф-я печати даных
// Выход: код состояния (как вариант "дерево является графом")
// Особенность вывода: от родительского элемента идут стрелки к дочерним,
//     каждое поддерево печатается с дополнительным отступом
// 
// Пример(дерево представлю в виде массива, каждый элемент хранит номер позиции отца,
//     корень - нулевой элемент не имеет отца и хранит значение -1):
//
// arr: -1 0 0 0 1 1 2 3 3 3 8
// выведется это так:
// data(arr[0])
// ├─>data(arr[1])
// │  ├─>data(arr[4])
// │  └─>data(arr[5])
// ├─>data(arr[2])
// │  └─>data(arr[6])
// └─>data(arr[3])
//    ├─>data(arr[7])
//    ├─>data(arr[8])
//    │  └─>data(arr[10])
//    └─>data(arr[9])
//
// PS: ф-я pdata нужна для того, чтобы печатать инфу, на которую указывает узел в одну строку
int triu7_print(triu7 node, void (* pdata)(void *));


#endif // __TRIU7_H__




    
