#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Include ctype.h for character classification functions

#define MAX_SIZE 1000 // Maximum size of the plaintext
#define BLOCK_SIZE 3  // Block size for encryption

// Following function generates the key matrix for the key string
void getKeyMatrix(char key[], int keyMatrix[][3]) {
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            keyMatrix[i][j] = toupper(key[k]) % 65; // Convert characters to uppercase and store in keyMatrix
            k++;
        }
    }
}

// Following function encrypts the message block
void encryptBlock(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1]) {
    int x, i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 1; j++) {
            cipherMatrix[i][j] = 0;

            for (x = 0; x < 3; x++) {
                cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];
            }

            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
}

// Function to implement Hill Cipher
void HillCipher(char message[], char key[], char ciphertext[]) {
    // Get key matrix from the key string
    int keyMatrix[3][3];
    getKeyMatrix(key, keyMatrix);

    int messageVector[BLOCK_SIZE][1];
    int cipherMatrix[BLOCK_SIZE][1];

    int size = strlen(message);
    int numBlocks = size / BLOCK_SIZE;
    if (size % BLOCK_SIZE != 0)
        numBlocks++; // If there are remaining characters, add one more block

    int index = 0; // Index to store characters in ciphertext buffer

    // Encrypt each block of the message
    for (int block = 0; block < numBlocks; block++) {
        // Generate vector for the block
        for (int i = 0; i < BLOCK_SIZE; i++) {
            int idx = block * BLOCK_SIZE + i;
            if (idx < size) {
                char ch = toupper(message[idx]); // Convert character to uppercase
                if (isalpha(ch)) {
                    int value = (ch - 65) % 26;
                    if (value < 0)
                        value += 26; // Adjust negative values
                    messageVector[i][0] = value;
                } else {
                    messageVector[i][0] = 0; // Set non-alphabetic characters to 0
                }
            } else
                messageVector[i][0] = 0; // Padding if the message is not multiple of BLOCK_SIZE
        }

        // Encrypt the block
        encryptBlock(cipherMatrix, keyMatrix, messageVector);

        // Store the encrypted block in the ciphertext buffer
        for (int i = 0; i < BLOCK_SIZE; i++) {
            ciphertext[index++] = cipherMatrix[i][0] + 65;
        }
    }

    // Null-terminate the ciphertext string
    ciphertext[index] = '\0';
}

// Driver function for above code
int main() {
    // Get the message to be encrypted
    char message[MAX_SIZE];
    printf("Enter the message to be encrypted: ");
    fgets(message, MAX_SIZE, stdin);

    // Get the key
    char key[10]; // Assuming the key size is at most 9 characters
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters from input strings
    message[strcspn(message, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    // Encrypt the message
    char ciphertext[MAX_SIZE]; // Buffer to store the ciphertext
    HillCipher(message, key, ciphertext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
