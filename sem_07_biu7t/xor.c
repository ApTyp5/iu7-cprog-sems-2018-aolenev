#include <stdio.h>
#include <string.h>
#include <malloc.h>

//XOR cipher

char* xor_chiper(char* text, char* key )
{

  char * output;
  output=malloc(strlen(text));
  int i;
  for(i = 0; i < strlen(text); i++) {
    output[i] = text[i] ^ key[i % (sizeof(key)/sizeof(char))];
  }
  return output;
}

int main(void)
{

    char* encoded = xor_chiper("Hello world", "pa$$w0rd");
    printf("%s", encoded);

    char* decoded = xor_chiper(encoded, "pa$$w0rd");
    printf("%s", decoded);

    return 1;
}
