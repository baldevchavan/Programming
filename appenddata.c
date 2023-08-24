#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("data.txt", "a"); // Open the file in append mode
    
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    
    char data[100];
    
    printf("Enter data to append: ");
    fgets(data, sizeof(data), stdin); // Read data from user
    
    fprintf(file, "%s", data); // Append data to the file
    
    fclose(file); // Close the file
    
    printf("Data appended successfully.\n");
    
    return 0;
}
