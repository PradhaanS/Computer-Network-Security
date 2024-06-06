#include <stdio.h>
#include <math.h>

long long int power(long long int a, long long int b,
                    long long int P)
{
    if (b == 1)
        return a;
    else
        return (((long long int)pow(a, b)) % P);
}

int isPrime(long long int n) {
    if (n <= 1)
        return 0; // Not prime

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0; // Not prime
    }

    return 1; // Prime
}

int isPrimitiveRoot(long long int G, long long int P) {
    int residues[P];
    for (int i = 0; i < P; i++)
        residues[i] = 0;

    long long int result = 1;
    for (int i = 1; i < P; i++) {
        result = (result * G) % P;
        if (residues[result] == 1)
            return 0; // Not a primitive root
        residues[result] = 1;
    }

    return 1; // G is a primitive root
}

int main()
{
    long long int P, G, x, a, y, b, ka, kb;

    printf("Enter the value of P (prime number): ");
    scanf("%lld", &P);

    if (!isPrime(P)) {
        printf("%lld is not a prime number.\n", P);
        return 1;
    }

    printf("Enter the value of G (primitive root for P): ");
    scanf("%lld", &G);

    if (!isPrimitiveRoot(G, P)) {
        printf("%lld is not a primitive root of %lld\n", G, P);
        return 1;
    }

    // Take input for Alice's private key a
    printf("Enter the private key for Alice (a): ");
    scanf("%lld", &a);

    // Take input for Bob's private key b
    printf("Enter the private key for Bob (b): ");
    scanf("%lld", &b);

    printf("\n");

    printf("The value of P : %lld\n", P);
    printf("The value of G : %lld\n\n", G);
    printf("The private key a for Alice : %lld\n", a);
    printf("The private key b for Bob : %lld\n\n", b);

    x = power(G, a, P); 
    y = power(G, b, P); 

    ka = power(y, a, P); 
    kb = power(x, b, P); 

    printf("Secret key for Alice: %lld\n", ka);
    printf("Secret key for Bob: %lld\n", kb);

    return 0;
}
