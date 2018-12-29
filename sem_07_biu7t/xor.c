#include <stdio.h>
#include <stdlib.h>

//XOR cipher

int len(const char *str)
{
    int size = 0;
    
    for (size = 0; str[size] != '\0'; size++);
    
    return size;
}

char* xor_chiper(char* text, char* key)
{
    int size_str = len(text);
    int size_key = len(key);
    char *new_char = malloc(sizeof(char) * size_str + 1);
    int j = 0;
    
    for (int i = 0; i < size_str; i++)
    {
        new_char[i] = text[i] ^ key[j];
        
        if (j >= size_key - 1)
            j = -1;
        j++;
    }
    
    new_char[size_str] = '\0';
    
    return new_char;
}

int main(void)
{
    char* encoded = xor_chiper("Hello world", "pa$$w0rd");
    printf("%s\n", encoded);

    char* decoded = xor_chiper(encoded, "pa$$w0rd");
    printf("%s", decoded);

    return 1;
}
