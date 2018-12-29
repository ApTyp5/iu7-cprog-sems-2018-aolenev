#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *xor_enc(char *src, int src_sz, char *key) {

    int i, j = 0;
    int k_len = strlen(key);
    char *ret = calloc(src_sz+1, sizeof(char));

    for (i = 0; i < src_sz; i++) {
        ret[i] = src[i] ^ key[j];
        j++;
        j = j > k_len ? 0 : j;
    }
    return ret;

}

int main() {

    char *str = "Hello World!";
    char *key = "pa$$w0rd";

    printf("Cleartext = %s\n", str);
    printf("Ciphertext = %s\n", xor_enc(str, strlen(str), key));

}
