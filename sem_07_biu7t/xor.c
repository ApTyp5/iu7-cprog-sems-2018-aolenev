#include <stdio.h>
#include <stdlib.h>

//XOR cipher

int len(char *str)
{
    int n = 0;
    while (str[n] != '\0') n++;
    return n;
}

char* xor_chiper(char* text, char* key)
{
    int len_text = len(text);
    int len_key = len(key);

    char *result = malloc(len_text + 1);

    for (int i = 0; i < len_text; i++)
        result[i] = text[i] ^ key[i % len_key];

    result[len_text] = '\0';

    return result;
}

int main(void)
{
    char* encoded = xor_chiper("Hello world", "pa$$w0rd");
    printf("%s\n", encoded);

    char* decoded = xor_chiper(encoded, "pa$$w0rd");
    printf("%s\n", decoded);

    free(encoded);

    return 1;
}
