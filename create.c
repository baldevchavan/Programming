#include <stdio.h>

int main() {
    FILE *filePointer;

    // Open the file in write mode
    filePointer = fopen("example.txt", "w");

    if (filePointer == NULL) {
        printf("Failed to create the file.\n");
        return 1;
    }

    printf("File created successfully.\n");

    // Close the file
    fclose(filePointer);

    return 0;
}
