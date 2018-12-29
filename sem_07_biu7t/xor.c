#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//XOR cipher

char* xor_chiper(char* text, char* key)
{
    char *res = malloc(strlen(text) + 1);

    for (int i = 0; i < strlen(text); i++)
    {
        res[i] = text[i] ^ key[i % strlen(key)];
    }
    res[strlen(text)] = '\0';

    return res;
}

int main(void)
{
    char* encoded = xor_chiper("Hello world", "pa$$w0rd");
    printf("%s\n", encoded);
    for (int i = 0; i < strlen(encoded); i++)
    {
        printf("%d ", encoded[i]);
    }
    printf("\n");

    char* decoded = xor_chiper(encoded, "pa$$w0rd");
    printf("%s\n", decoded);
    free(encoded);
    free(decoded);

    return 1;
}
