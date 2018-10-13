#ifndef __STRIU7NG_H__
#define __STRIU7NG_H__

#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 0
#define ERR_ALLOCATION -1
#define ERR_OVERFLOW -2
#define ERR_DEFAULT -3

/*
Structure that keeps dynamic string
*/
typedef struct
{
    int len;
    char *head;
}  strIU7ng;

/*
Creates string from pointer to string
*/
strIU7ng strIU7ng_create(char *);

/*
Frees dynamic string
*/
void strIU7ng_free(strIU7ng string);

/*
Concatenates str1 and str2
*/
strIU7ng concat(strIU7ng str1, strIU7ng str2);

/*
Calculates length of the string
*/
int strIU7ng_len(strIU7ng string);

/*
Splits string by the delimiter
*/
strIU7ng* split(strIU7ng string, char delimiter, int *new_size);

/*
Replace all occurences of replace at source
*/
strIU7ng replace(strIU7ng source, strIU7ng search, strIU7ng replace);

/*
Returns repeated source multiply times
*/
strIU7ng mult(strIU7ng source, int multiply);

/*
Returns reversed string
*/
strIU7ng reverse(strIU7ng string);

/*
Find first occurence search at source
*/
char* find_substrIU7ng(strIU7ng source, strIU7ng search);

#endif
