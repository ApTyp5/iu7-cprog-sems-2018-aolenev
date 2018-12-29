#include <stdio.h>
#include <stdlib.h>

//XOR cipher

char* xor_chiper(char* text, char* key)
{
    int i = 0, j = 0;
    char *new = calloc(20, sizeof(char));

    while (text[i] != '\0')
    {
        if (key[j] == '\0')
            j = 0;
        new[i] = text[i] ^ key[j];
        i++;
        j++;
    }
    new[i] = '\0';
    return new;
}

int main(void)
{
    char* encoded = xor_chiper("Hello world", "pa$$w0rd");
    puts(encoded);

    char* decoded = xor_chiper(encoded, "pa$$w0rd");
    puts(decoded);

    return 1;
}
