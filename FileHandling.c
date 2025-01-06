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



