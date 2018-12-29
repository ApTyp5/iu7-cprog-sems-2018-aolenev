#include <stdio.h>
#include <stdlib.h>

//XOR cipher

int len_str(const char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        count++;

    return count;
}

void copy(const char *from, char *to, int n)
{
    int i = 0;
    while (from[i] != '\0' && n > i)
    {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}

char* xor_chiper(char* text, char* key)
{
    int size;
    if (len_str(text) > len_str(key))
    {
        size = len_str(text);
    }
    else
    {
        size = len_str(key);
    }

    char *sup = calloc(size, sizeof(char));
    copy(key, sup, len_str(key));
    if (len_str(key) < size)
    {
        copy(key, sup + (len_str(key)), size - len_str(key));
    }
    char *res = calloc(size, sizeof(char));
    for (int i = 0; i < size; i++)
    {
        res[i] = text[i] ^ sup[i];
    }

    free(sup);
    return res;
}

int main(void)
{
    char* encoded = xor_chiper("Hello world", "pa$$w0rd");
    printf("%s\n", encoded);

    char* decoded = xor_chiper(encoded, "pa$$w0rd");
    printf("%s\n", decoded);
	
    free(encoded);
    free(decoded);
    return 1;
}
