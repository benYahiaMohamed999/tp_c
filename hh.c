#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* INV_CH(const char* chaine) {
    int longueur = strlen(chaine);
    char* inverse = (char*)malloc((longueur + 1) * sizeof(char)); // Allocate memory for the reversed string

    // Check if memory allocation was successful
    if (inverse == NULL) {
        printf("Erreur lors de l'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }

    const char* end = chaine + longueur - 1;
    char* start = inverse;

    // Copy characters from the end of the original string to the start of the reversed string
    while (end >= chaine) {
        *start++ = *end--;
    }

    *start = '\0'; // Null-terminate the reversed string

    return inverse; // Return the reversed string
}

// Example usage
int main() {
    const char original[] = "Hello, World!";
    char* reversed = INV_CH(original);

    printf("Original: %s\n", original);
    printf("Reversed: %s\n", reversed);

    free(reversed); // Free the allocated memory
    return 0;
}
