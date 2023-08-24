#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[50];
    char data[100];
    char tempFilename[50];
    char *tempLine = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    // Open the original file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found or unable to open.\n");
        return 1;
    }

    // Create a temporary file to hold the modified content
    strcpy(tempFilename, "temp.txt");
    FILE *tempFile = fopen(tempFilename, "w");
    if (tempFile == NULL) {
        printf("Unable to create temporary file.\n");
        fclose(file);
        return 1;
    }

    // Read each line from the original file
    while ((read = getline(&tempLine, &len, file)) != -1) {
        // Here, you can add conditions to decide whether to delete a line or keep it.
        // For example, let's delete lines containing a specific keyword "DELETE_ME"
        if (strstr(tempLine, "DELETE_ME") == NULL) {
            fprintf(tempFile, "%s", tempLine);
        }
    }

    // Close the original and temporary files
    fclose(file);
    fclose(tempFile);

    // Remove the original file and rename the temporary file
    remove(filename);
    rename(tempFilename, filename);

    printf("Data deleted successfully.\n");

    return 0;
}
