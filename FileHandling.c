#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s for reading.\n", filename);
        return;
    }

    char ch;
    printf("Contents of %s:\n", filename);
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

void writeFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not open file %s for writing.\n", filename);
        return;
    }

    char content[100];
    printf("Enter text to write to the file (max 100 characters): ");
    fgets(content, sizeof(content), stdin);
    fprintf(file, "%s", content);
    fclose(file);
    printf("Content written successfully to %s.\n", filename);
}

void deleteFile(const char *filename) {
    if (remove(filename) == 0) {
        printf("File %s deleted successfully.\n", filename);
    } else {
        printf("Could not delete the file %s.\n", filename);
    }
}

void copyFile(const char *sourceFile, const char *destinationFile) {
    FILE *source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Could not open source file %s for reading.\n", sourceFile);
        return;
    }

    FILE *destination = fopen(destinationFile, "w");
    if (destination == NULL) {
        printf("Could not open destination file %s for writing.\n", destinationFile);
        fclose(source);
        return;
    }

    char ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    printf("File copied from %s to %s.\n", sourceFile, destinationFile);
    fclose(source);
    fclose(destination);
}

int main() {
    int choice;
    char filename[100];
    char sourceFile[100], destinationFile[100];

    while (1) {
        printf("\nFile Operations Menu:\n");
        printf("1. Read a file\n");
        printf("2. Write to a file\n");
        printf("3. Delete a file\n");
        printf("4. Copy a file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character from the buffer

        switch (choice) {
            case 1:
                printf("Enter the filename to read: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline character
                readFile(filename);
                break;

            case 2:
                printf("Enter the filename to write to: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline character
                writeFile(filename);
                break;

            case 3:
                printf("Enter the filename to delete: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline character
                deleteFile(filename);
                break;

            case 4:
                printf("Enter the source filename: ");
                fgets(sourceFile, sizeof(sourceFile), stdin);
                sourceFile[strcspn(sourceFile, "\n")] = 0; // Remove newline character
                printf("Enter the destination filename: ");
                fgets(destinationFile, sizeof(destinationFile), stdin);
                destinationFile[strcspn(destinationFile, "\n")] = 0; // Remove newline character
                copyFile(sourceFile, destinationFile);
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}