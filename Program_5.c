#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 100

#define ALPHABET_SIZE 26

// Function to encrypt plaintext using the poly-alphabetic cipher
void encrypt(char plaintext[], char keyword[], char ciphertext[]) {
    int i, j;
    int keywordLen = strlen(keyword);
    int textLen = strlen(plaintext);

    for (i = 0, j = 0; i < textLen; ++i, ++j) {
        if (j == keywordLen) j = 0;

        if (isalpha(plaintext[i])) {
            int shift = tolower(keyword[j]) - 'a';

            if (isupper(plaintext[i])) {
                ciphertext[i] = ((plaintext[i] - 'A') + shift) % ALPHABET_SIZE + 'A';
            } else {
                ciphertext[i] = ((plaintext[i] - 'a') + shift) % ALPHABET_SIZE + 'a';
            }
        } else {
            ciphertext[i] = plaintext[i];
            --j; // Not a letter, so don't increment j
        }
    }
    ciphertext[textLen] = '\0'; // Null-terminate the string
}

// Function to decrypt ciphertext using the poly-alphabetic cipher
void decrypt(char ciphertext[], char keyword[], char decryptedtext[]) {
    int i, j;
    int keywordLen = strlen(keyword);
    int textLen = strlen(ciphertext);

    for (i = 0, j = 0; i < textLen; ++i, ++j) {
        if (j == keywordLen) j = 0;

        if (isalpha(ciphertext[i])) {
            int shift = tolower(keyword[j]) - 'a';

            if (isupper(ciphertext[i])) {
                decryptedtext[i] = ((ciphertext[i] - 'A') - shift + ALPHABET_SIZE) % ALPHABET_SIZE + 'A';
            } else {
                decryptedtext[i] = ((ciphertext[i] - 'a') - shift + ALPHABET_SIZE) % ALPHABET_SIZE + 'a';
            }
        } else {
            decryptedtext[i] = ciphertext[i];
            --j; // Not a letter, so don't increment j
        }
    }
    decryptedtext[textLen] = '\0'; // Null-terminate the string
}

int main() {
    char plaintext[MAX_TEXT_LENGTH];
    char keyword[MAX_TEXT_LENGTH];

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

    printf("Enter keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0'; // Remove newline character

    char ciphertext[strlen(plaintext) + 1];
    char decryptedtext[strlen(plaintext) + 1];

    encrypt(plaintext, keyword, ciphertext);
    printf("Encrypted: %s\n", ciphertext);

    decrypt(ciphertext, keyword, decryptedtext);
    printf("Decrypted: %s\n", decryptedtext);

    return 0;
}
