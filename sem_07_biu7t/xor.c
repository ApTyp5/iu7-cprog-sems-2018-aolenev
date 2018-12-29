#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//XOR cipher

char* xor_chiper(char* text, char* key)
{
    if (text == NULL || key == NULL)
    {
        return NULL;
    }

    int key_len = strlen(key);
    char *result = calloc((strlen(text) + 1), sizeof(char));
    if (result != NULL)
    {
        int i = 0;
        for (; i < strlen(text); i++)
        {
            result[i] = text[i] ^ key[i % key_len];
        }
        result[i] = '\0';
    }
    return result;
}

int main(void)
{
    char* encoded = xor_chiper("Hello world", "pa$$w0rd");
    printf("%s\n", encoded);

    char* decoded = xor_chiper(encoded, "pa$$w0rd");
    printf("%s\n", decoded);

    free(encoded);
    free(decoded);
    return 0;
}
