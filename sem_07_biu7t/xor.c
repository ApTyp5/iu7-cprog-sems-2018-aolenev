#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//XOR cipher

char* xor_chiper(char* text, char* key)
{
	int len = strlen(text);
	char *result = malloc(len * sizeof(char));
	for (int i = 0; i < len; i++)
		result[i] = text[i] ^ key[i % strlen(key)];
	result[len] = '\0';
	
    return result;
}

int main(void)
{
    char* encoded = xor_chiper("Hello world", "pa$$w0rd");
    printf("%s", encoded);

    char* decoded = xor_chiper(encoded, "pa$$w0rd");
    printf("\n%s", decoded);

    return 1;
}