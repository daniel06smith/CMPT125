/*
SFU ID: 301613547
Computing ID: dcs7
Name: Daniel Smith

Note: ChatGPT was used to break down the question, translate C language into
Python, a language I know better, for translational understanding, and for
extrapolation on C functions (asking questions about why/why not x, y, z).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a2_question2.h"

int main() {
    // Print banner
    printf("==========\nDaniel Smith\n301613547\ndcs7@sfu.ca\n==========\n");

    // Open the file
    FILE *file = fopen("superheros.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Dynamic array of superheroes
    int capacity = 10, used = 0;
    Superhero** superheroArray = (Superhero**)malloc(sizeof(Superhero*) * capacity);

    // Buffers for reading lines and storing values
    char line[301], name[301], superpower[301], traits[301];
    short feetInHeight, inchesInHeight;

    while (fgets(line, 301, file)) {
        // Remove newline character from the line
        line[strcspn(line, "\n")] = '\0';  // Clean up newline at end of the line

        // Check for "Name: " prefix
        if (strncmp(line, "**Name:**", 9) == 0) {
            strcpy(name, line + 10);  // Copy the name after "**Name:**"
        }

        // Read next line for "Height: "
        fgets(line, 301, file);
        line[strcspn(line, "\n")] = '\0';  // Remove newline character

        // Extract feet and inches from height
        if (strncmp(line, "**Height:**", 11) == 0) {
            sscanf(line + 11, "%hd'%hd\"", &feetInHeight, &inchesInHeight);
        }

        // Read next line for "Superpower: "
        fgets(line, 301, file);
        line[strcspn(line, "\n")] = '\0';  // Remove newline character

        // Extract superpower
        if (strncmp(line, "**Superpower:**", 15) == 0) {
            strcpy(superpower, line + 16);  // Copy superpower after "Superpower: "
        }

        // Read the next line for traits (no prefix)
        fgets(line, 301, file);
        line[strcspn(line, "\n")] = '\0';  // Remove newline character
        strcpy(traits, line);  // Copy traits directly since there is no prefix

        // Create superhero using the parsed values
        if (used == capacity) {
            capacity *= 2;
            superheroArray = (Superhero**)realloc(superheroArray, sizeof(Superhero*) * capacity);
        }
        superheroArray[used++] = createSuperhero(name, feetInHeight, inchesInHeight, superpower, traits);

        // Skip the blank line separating superheroes
        fgets(line, 301, file);
    }

    fclose(file);

    // Print all superheroes
    for (int i = 0; i < used; i++) {
        // Print seperator
        printf("===============\n");

        printf("Superhero #%d\n", i + 1);
        printf("%s\n%d\'%d\"\n%s: %s\n", superheroArray[i]->name, superheroArray[i]->feetInHeight, superheroArray[i]->inchesInHeight, superheroArray[i]->superpower, superheroArray[i]->traits);
    }

    // Free all memory
    for (int i = 0; i < used; i++) {
        clearSuperhero(superheroArray[i]);
        free(superheroArray[i]);
    }
    free(superheroArray);

    return 0;
}
