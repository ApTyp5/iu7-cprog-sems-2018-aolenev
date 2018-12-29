#include <stdio.h>

//XOR cipher

char* xor_chiper(char* text, char* key)
{
    return NULL;
}

int main(void)
{
    char* encoded = xor_chiper("Hello world", "pa$$w0rd");
    printf("%s", encoded);

    char* decoded = xor_chiper(encoded "pa$$w0rd");
    printf("%s", encoded);

    return 1;
}
