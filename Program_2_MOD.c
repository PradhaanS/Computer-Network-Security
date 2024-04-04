#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void encrypt(char *plaintext, const char *key) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            plaintext[i] = key[plaintext[i] - base];
        }
    }
}

void decrypt(char *ciphertext, const char *key) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            const char *pos = strchr(key, ciphertext[i]);
            if (pos != NULL) {
                ciphertext[i] = base + (pos - key);
            }
        }
    }
}

int main() {
    char plaintext[100];
    char *key;
    char ciphertext[100];
    char decrypted[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove trailing newline

    printf("Enter the key: ");
    key = (char *)malloc(256 * sizeof(char)); // Allocate memory for the key dynamically
    fgets(key, 256, stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove trailing newline
    printf("\n");
    
    // Encrypt
    strcpy(ciphertext, plaintext);
    encrypt(ciphertext, key);
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt
    strcpy(decrypted, ciphertext);
    decrypt(decrypted, key);
    printf("Decrypted Ciphertext: %s\n", decrypted);

    // Free dynamically allocated memory
    free(key);

    return 0;
}
