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
