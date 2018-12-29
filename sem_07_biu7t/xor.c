#include <stdio.h>
#include <stdlib.h>

//XOR cipher

int len_str(char *str)
{
    int n = 0;
    while (str[n] != '\0') n++;
    return n;
}

char* xor_chiper(char* text, char* key)
{
    int len;
    char *result;
    len = len_str(text);
    result = malloc((len + 1) * sizeof(int));
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
    result[len] = '\0';
    return result;
}

int main(void)
{
    char* encoded = xor_chiper("Hello world", "pa$$w0rd");
    for (int i = 0; encoded[i] != '\0'; i++)
	    printf("%d\n", encoded[i]);

    char* decoded = xor_chiper(encoded, "pa$$w0rd");
    printf("%s\n", decoded);

    free(encoded);

    return 0;
}
