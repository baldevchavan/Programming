#include <stdio.h>

int main() {
    // Declare a file pointer
    FILE *file;

    // Open the file in read mode
    file = fopen("example.txt", "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1; // Return an error code
    }

    // Read and print the contents of the file
    char c;
    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }

    // Close the file
    fclose(file);

    return 0; // Return success
}
