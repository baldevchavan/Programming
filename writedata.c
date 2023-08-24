#include <stdio.h>

int main() {
    // Open a file in write mode
    FILE *file = fopen("data.txt", "w");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1; // Exit with an error code
    }

    // Write data to the file
    fprintf(file, "Hello, this is some data that we're writing to the file.\n");
    fprintf(file, "You can write multiple lines like this.\n");

    // Close the file
    fclose(file);

    printf("Data has been written to the file.\n");

    return 0; // Exit successfully
}
