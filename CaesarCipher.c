#include <stdio.h>
#include <ctype.h>

char* encrypt(char* text, int s) {
    int i;
    static char result[1000]; 

    for (i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i]))
            result[i] = (char)(((text[i] + s - 'A') % 26) + 'A');
        else if (islower(text[i]))
            result[i] = (char)(((text[i] + s - 'a') % 26) + 'a');
        else
            result[i] = text[i]; 
    }
    
    result[i] = '\0'; 
    return result;
}


char* decrypt(char* text, int s) {
    int i;
    static char result[1000]; 
    for (i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i]))
            result[i] = (char)(((text[i] - s - 'A' + 26) % 26) + 'A');
        else if (islower(text[i]))
            result[i] = (char)(((text[i] - s - 'a' + 26) % 26) + 'a');
        else
            result[i] = text[i]; 
    }
    
    result[i] = '\0'; 
    return result;
}

int main() {
    char text[1000];
    int s;
    int choice;
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter the text to encrypt: ");
            getchar(); 
            fgets(text, sizeof(text), stdin);
            printf("Enter the shift value: ");
            scanf("%d", &s);
    
            printf("Encrypted Cipher: %s\n", encrypt(text, s));
            break;
        
        case 2:
            printf("Enter the text to decrypt: ");
            getchar(); 
            fgets(text, sizeof(text), stdin);
            printf("Enter the shift value: ");
            scanf("%d", &s);
    
            printf("Decrypted Cipher: %s\n", decrypt(text, s));
            break;
        
        default:
            printf("Invalid choice!\n");
            break;
    }
    
    return 0;
}
