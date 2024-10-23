/*Name: Daniel Smith
SFU ID: 301613547
Email: dcs7@sfu.ca*/

/*Notice: Use of ChatGPT for advice on programming best practices, syntax and clarifying input + output.*/

#include "a3_superherolib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 300 // as per assignment description

// Load superheroes from file
int loadSuperheroes(const char* filename, Superhero*** superheroArray, int* numSuperheroes, int* arraySize) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return 0;
    } else {
    // printf("File opened successfully: %s\n", filename);  // Debugging: Confirm file open
    }

    char line[301];  // Buffer to hold each line of the file
    char name[50], superpower[50], traits[100];  // Buffers for superhero attributes
    short feetInHeight, inchesInHeight;

    while (fgets(line, sizeof(line), file)) {
        // printf("DEBUG: Reading line %s\n", line);

        // Remove newline character from the line
        line[strcspn(line, "\n")] = '\0';  // Clean up newline at end of the line

        // Step 1: Check for "Name: " prefix
        if (strncmp(line, "**Name:**", 9) == 0) {
            // printf("DEBUG: Found name: %s\n", line + 10);
            strcpy(name, line + 10);  // Copy the name after "**Name:**"
        }

        // Step 2: Read next line for "Height: "
        fgets(line, sizeof(line), file);
        // printf("DEBUG: Reading Height Line: %s\n", line);
        line[strcspn(line, "\n")] = '\0';  // Remove newline character

        // Extract feet and inches from height
        if (strncmp(line, "**Height:**", 11) == 0) {
            sscanf(line + 11, "%hd'%hd\"", &feetInHeight, &inchesInHeight);
            // printf("DEBUG: Parsed height: %hd'%hd\"", feetInHeight, inchesInHeight);
        }

        // Step 3: Read next line for "Superpower: "
        fgets(line, sizeof(line), file);
        line[strcspn(line, "\n")] = '\0';  // Remove newline character

        // Extract superpower
        if (strncmp(line, "**Superpower:**", 15) == 0) {
            strcpy(superpower, line + 16);  // Copy superpower after "Superpower: "
            // printf("DEBUG: Parsed superpower: %s\n", superpower);
        }

        // Step 4: Read the next line for traits (no prefix)
        fgets(line, 301, file);
        line[strcspn(line, "\n")] = '\0';  // Remove newline character
        // printf("DEBUG: Reading traits line: %s\n", line);
        strcpy(traits, line);  // Copy traits directly since there is no prefix

        // Step 5: Dynamically allocate memory and store the superhero
        if (*numSuperheroes == *arraySize) {
            *arraySize *= 2;
            *superheroArray = realloc(*superheroArray, sizeof(Superhero*) * (*arraySize));
        }

        // Allocate memory for the new superhero
        Superhero* newSuperhero = malloc(sizeof(Superhero));
        newSuperhero->name = strdup(name);
        newSuperhero->superpower = strdup(superpower);
        newSuperhero->traits = strdup(traits);
        newSuperhero->feetInHeight = feetInHeight;
        newSuperhero->inchesInHeight = inchesInHeight;

        // Add the new superhero to the array
        (*superheroArray)[*numSuperheroes] = newSuperhero;
        (*numSuperheroes)++;

        // Step 6: Skip the blank line separating superheroes
        fgets(line, 301, file);
    }

    fclose(file);
    printf("Successfully loaded %d superheroes.\n", *numSuperheroes);
    return 1;  // Success
}

// Compare superheroes by height (ascending)
int compareSuperheroesByHeight(const void* p1, const void* p2) {
    Superhero* heroA = *(Superhero**)p1;
    Superhero* heroB = *(Superhero**)p2;

    // Convert both superheroes' heights to total inches
    int heightA = (heroA->feetInHeight * 12) + heroA->inchesInHeight;
    int heightB = (heroB->feetInHeight * 12) + heroB->inchesInHeight;

    // Return comparison: negative if heroA is shorter, positive if heroA is taller
    return heightA - heightB;
}

// Compare superheroes by name
int compareSuperheroesByName(const void *p1, const void *p2) {
    Superhero* heroA = *(Superhero**)p1;
    Superhero* heroB = *(Superhero**)p2;

    //strcmp to compare names of superheroes
    return strcmp(heroA->name, heroB->name);
}

// Search superheroes by superpower
Superhero** lookupSuperheroBySuperpower(Superhero **array, int size, const char* superpower) {
    // Allocate memory for the result array (account for NULL terminator)
    Superhero** result = (Superhero**)malloc((size+1) * sizeof(Superhero*));
    if (result == NULL) {
        printf("Error: Unable to allocate memory for result array.\n");
        return NULL;
    }

    int resultCount = 0;    // # of matching superheroes

    for (int i = 0; i < size; i++) {
        if (strcmp(array[i]->superpower, superpower) == 0) {    // 0 is a perfect match
            result[resultCount++] = array[i];
        }
    }

    result[resultCount] = NULL; // Null pointer at end of result array

    return result;
}

// Memory cleanup for full superhero array
void cleanupSuperheroes(Superhero*** superheroArray, int* superheroCount){
    if (*superheroArray != NULL) {
        // printf("DEBUG: Beginning memory clearing process...\n"); // Debugging
        // Free each superhero's dynamically allocated memory
        for (int i = 0; i < *superheroCount; i++) {
            free((*superheroArray)[i]->name);       // Free the name string
            free((*superheroArray)[i]->superpower); // Free the superpower string
            free((*superheroArray)[i]->traits);     // Free the traits string
            free((*superheroArray)[i]);             // Free the superhero struct
        }
        // Free the superhero array itself
        *superheroArray = NULL;     // Reset pointer to NULL
        *superheroCount = 0;        // Reset superhero count to 0
    }
    // printf("DEBUG: Memory cleared successfully.\n"); // Debugging
}