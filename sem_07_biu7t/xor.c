#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//XOR cipher

char* xor_chiper(char* text, char* key)
{
    int len = strlen(text),
        keylen = strlen(key);

    char *result = malloc(len + 1);

    for (int i = 0; i < len; i++)
        result[i] = text[i] ^ key[i % keylen];

    result[len] = '\0';
    return result;
}

int main(void)
{
    char* encoded = xor_chiper("Hello world", "pa$$w0rd");
    printf("%s\n", encoded);

    char* decoded = xor_chiper(encoded, "pa$$w0rd");
    printf("%s\n", decoded);

    return 1;
}
