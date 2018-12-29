#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//XOR cipher

char* xor_chiper(char* text, char* key);

int main(void)
{
    char* encoded = xor_chiper("Hello world", "pa$$w0rd");
    printf("%s", encoded);

    char* decoded = xor_chiper(encoded, "pa$$w0rd");
    printf("%s", decoded);

    return 1;
}

char *xor_chiper(char *str, char *key)
{
    char *result = malloc(strlen(str) + 1);
    char *iter = result;

    int len = strlen(key);
    char *kiter = key;

    while (*str)
    {
//        printf("%c_%c_%c_%c_\n", *iter, *str, *kiter, *str ^ *kiter);
        *iter++ = *str++ ^ *kiter++;

        if (kiter == key + len)
            kiter = key;
    }
//    printf("\n");

    *iter = 0;

    return result;
}



