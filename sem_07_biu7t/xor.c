#include <stdio.h>
#include <stdlib.h>
//XOR cipher

int my_strlen(char *str)
{
    if (str == NULL)
    {
        return 0;
    }

    int i = 0;
    while (*(str + i++) != '\0');
    return i;
}

char* xor_chiper(char* text, char* key)
{
    if (text == NULL || key == NULL)
    {
        return NULL;
    }

    int key_len = my_strlen(key);
    int text_len = my_strlen(text);
    if (text_len == 0)
    {
        return "";
    }

    if (key_len == 0)
    {
        return text;
    }

    char *result = calloc((text_len + 1), sizeof(char));
    if (result != NULL)
    {
        int i = 0;
        while (*(text + i) != '\0')
        {
            *(result + i) = *(text + i) ^ *(key + (i % key_len));
            i++;
        }
        *(result + i) = '\0';
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
