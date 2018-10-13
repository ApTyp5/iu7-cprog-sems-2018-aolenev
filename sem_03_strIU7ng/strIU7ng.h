#ifndef __STRIU7NG_H__
#define __STRIU7NG_H__

struct strIU7ng
{
    int len;
    char *head;
}

strIU7ng strIU7ng_create(char *);

void strIU7ng_free(strIU7ng string);

int strIU7ng_len(strIU7ng string);

strIU7ng* split(strIU7ng string, char delimiter);

strIU7ng* replace(strIU7ng source, strIU7ng replace);

strIU7ng mult(strIU7ng source, int multiply);

strIU7ng reverse(strIU7ng string);

#endif
