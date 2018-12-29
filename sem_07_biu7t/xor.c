#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//XOR cipher

int len_str(char *str)
{
    int len = 0;

    while (str[len] != '\0')
    {
        len += 1;
    }

    return len;
}

char* xor_chiper(char* text, char* key)
{
    int len;
    char *result;
    result = malloc(20 * sizeof(int));
    len = len_str(text);
    int j = 0;

    for (int i = 0; i < len; i++)
    {
        if (i == len_str(key))
        {
            j = 0;
        }

        result[i] = text[i] ^ key[j];
        ++j;
    }

    return result;
}

int main(void)
{
    char* encoded = xor_chiper("Hello world", "pa$$w0rd");
    
    for (int i = 0; encoded[i] != '\0'; i++)
	    printf("%d\n", encoded[i]);

    char* decoded = xor_chiper(encoded, "pa$$w0rd");
    printf("%s", decoded);

    return 1;
}
