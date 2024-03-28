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

int main() {
    char text[1000];
    int s;
    printf("Enter the text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter the shift value: ");
    scanf("%d", &s);
    printf("\n");
    printf("Cipher: %s", encrypt(text, s));
    
    return 0;
}
