#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *plaintext, const char *key) {
    while (*plaintext) {
        if (isalpha(*plaintext)) {
            char base = isupper(*plaintext) ? 'A' : 'a';
            *plaintext = key[*plaintext - base];
        }
        plaintext++;
    }
}

void decrypt(char *ciphertext, const char *key) {
    while (*ciphertext) {
        if (isalpha(*ciphertext)) {
            char base = isupper(*ciphertext) ? 'A' : 'a';
            const char *pos = strchr(key, *ciphertext);
            if (pos != NULL) {
                *ciphertext = base + (pos - key);
            }
        }
        ciphertext++;
    }
}

int main() {
    char plaintext[1000];
    char key[256];
    char ciphertext[1000];
    char decrypted[1000];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    printf("\n");
    
    // Encrypt
    strcpy(ciphertext, plaintext);
    encrypt(ciphertext, key);
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt
    strcpy(decrypted, ciphertext);
    decrypt(decrypted, key);
    printf("Decrypted Ciphertext: %s\n", decrypted);

    return 0;
}
