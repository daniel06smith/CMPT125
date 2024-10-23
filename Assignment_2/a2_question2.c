/*
SFU ID: 301613547
Computing ID: dcs7
Name: Daniel Smith

Note: ChatGPT was used to break down the question, translate C language into
Python, a language I know better, for translational understanding, and for
extrapolation on C functions (asking questions about why/why not x, y, z).*/

#include "a2_question2.h"

Superhero* createSuperhero(const char* name, short feetInHeight, short inchesInHeight, const char* superpower, const char* traits) {
    // Memory allocation for the Superhero struct
    Superhero* superhero = (Superhero*)malloc(sizeof(Superhero));

    // Checking if memory allocation was successful
    if (superhero == NULL) {
        return NULL; // NULL indicates failure.
    }

    // Allocate and copy name
    superhero->name = (char*)malloc(strlen(name) + 1); // +1 accounts for the null terminator
    if (superhero->name == NULL) {
        free(superhero);  // Free superhero struct memory if name allocation fails
        return NULL;
    }
    strcpy(superhero->name, name);

    // Allocate and copy superpower
    superhero->superpower = (char*)malloc(strlen(superpower) + 1);
    if (superhero->superpower == NULL) {
        free(superhero->name);  // Free name memory
        free(superhero);        // Free superhero struct memory
        return NULL;
    }
    strcpy(superhero->superpower, superpower);

    // Allocate and copy traits
    superhero->traits = (char*)malloc(strlen(traits) + 1);
    if (superhero->traits == NULL) {
        free(superhero->superpower);  // Free superpower memory
        free(superhero->name);        // Free name memory
        free(superhero);              // Free superhero struct memory
        return NULL;
    }
    strcpy(superhero->traits, traits);

    // Set height fields
    superhero->feetInHeight = feetInHeight;
    superhero->inchesInHeight = inchesInHeight;

    // Returns pointer to the dynamically allocated Superhero struct.
    return superhero;
}

void clearSuperhero(Superhero* superhero) {
    // Checking if the superhero pointer is NULL
    if (superhero == NULL) {
        return; // Do nothing if pointer is NULL
    }

    // Free the dynamically allocated memory
    free(superhero->name);
    free(superhero->superpower);
    free(superhero->traits);
}
