/*Name: Daniel Smith
SFU ID: 301613547
Email: dcs7@sfu.ca*/

/*Notice: Use of ChatGPT for advice on programming best practices, syntax and clarifying input + output.*/

#include "a3_superherolib.h"
#include <stdio.h>

// Main function
int main() {
    // print special banner
    printf("=================\n");
    printf("- Daniel Smith --\n");
    printf("--- 301613547 ---\n");
    printf("- dcs7@sfu.ca ---\n");
    
    // Holds user's input
    int option;

    // Superhero data storage (dynamic array of Superhero pointers)
    Superhero** superheroArray = NULL;  // Start with an empty array
    int superheroCount = 0;             // Keep track of # of superhero entries
    int arraySize = 0;                  // Current size of array
    
    // Loop to display menu to user and receive user's input
    do {
        printf("=================\n");
        printf("--- Main Menu ---\n");
        printf("1) Load superheroes file.\n");
        printf("2) List superheroes by height.\n");
        printf("3) List superheroes by name.\n");
        printf("4) Lookup superheroes by superpower.\n");
        printf("5) Exit program.\n");
        printf(">>> ");

        scanf("%d", &option);
    
        switch(option) {
            case 1: {
                char filename[256];
                printf("Enter the name of the superhero file:\n>>> ");
                scanf("%255s", filename);  // Get the filename from the user

                // Cleanup superheroes before loading new file
                if (superheroArray != NULL) {
                    cleanupSuperheroes(&superheroArray, &superheroCount);
                    loadSuperheroes(filename, &superheroArray, &superheroCount, &arraySize);
                    break;
                } else {
                    if (loadSuperheroes(filename, &superheroArray, &superheroCount, &arraySize)) {
                } else {
                    printf("Failed to load superheroes.\n");
                }}
                break;
            }
            case 2:
                // List superheroes by height (ascending)
                if (superheroCount > 0) {
                    // Sort superheroes by height using the helper function
                    qsort(superheroArray, superheroCount, sizeof(Superhero*), compareSuperheroesByHeight);
                    
                    // Print superheroes sorted by height (ascending)
                    printf("Superheroes listed by height:\n");
                    for (int i = 0; i < superheroCount; i++) {
                        printf("Superhero: %d\n%s\n%hd'%hd\"\n%s: %s\n=======================\n",
                            (i+1), 
                            superheroArray[i]->name,
                            superheroArray[i]->feetInHeight, 
                            superheroArray[i]->inchesInHeight,
                            superheroArray[i]->superpower,
                            superheroArray[i]->traits);
                    }
                } else {
                    printf("No superheroes to list.\n");
                }
                break;
            case 3:
                // List superheroes by name
                if (superheroCount > 0) {
                    // Sort heroes by name with the helper function
                    qsort(superheroArray, superheroCount, sizeof(Superhero*), compareSuperheroesByName);

                    // Print superheroes sorted by name
                    printf("Superheroes listed by name:\n");
                    for (int i = 0; i < superheroCount; i++) {
                        printf("Superhero: %d\n%s\n%hd'%hd\"\n%s: %s\n=======================\n",
                            (i+1), 
                            superheroArray[i]->name,
                            superheroArray[i]->feetInHeight, 
                            superheroArray[i]->inchesInHeight,
                            superheroArray[i]->superpower,
                            superheroArray[i]->traits);
                    }
                } else {
                    printf("No superheroes to list.\n");
                }
                break;
            case 4:
                // Lookup superheroes by superpower
                if (superheroCount > 0) {
                    // Declare + initialize superpower variable
                    char superpower[256]; // Buffer for superpower input
                    printf("Enter the superpower to search for:\n>>> ");
                    scanf(" %255[^\n]", superpower); // Read superpower input

                // Superpower lookup function
                Superhero** matchingHeroes = lookupSuperheroBySuperpower(superheroArray, superheroCount, superpower);

                if (matchingHeroes[0] != NULL) {
                    printf("Superheroes containg the superpower '%s':\n", superpower);
                    for (int i = 0; matchingHeroes[i] != NULL; i++) {
                        printf("Superhero: %d\n%s\n%hd'%hd\"\n%s: %s\n=======================\n",
                            (i+1), 
                            superheroArray[i]->name,
                            superheroArray[i]->feetInHeight, 
                            superheroArray[i]->inchesInHeight,
                            superheroArray[i]->superpower,
                            superheroArray[i]->traits);
                    }
                    // Free the result array's dynamically allocated memory
                } else {
                    printf("No heroes matching superpower '%s'.\n", superpower);
                }
                free(matchingHeroes);
                } else {
                    printf("No available superheroes to search.\n");
                }
                break;
            case 5:
                // printf("DEBUG: User selected exit.\n"); // Debugging
                printf("Exiting program...\n");
                break;
            default:
                // Handles invalid user input.
                printf("Invalid input. Please try again."); 
        }
    
    } while (option != 5);    

    
    // printf("DEBUG: Total memory cleanup started.\n");
    // Memory cleanup process
    cleanupSuperheroes(&superheroArray, &superheroCount);
    printf("Program terminated.");

    return 0;
}