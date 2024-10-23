/*Name: Daniel Smith
SFU ID: 301613547
Email: dcs7@sfu.ca*/

#ifndef _A3_SUPERHEROLIB_H_
#define _A3_SUPERHEORLIB_H_

#include <stdlib.h> //needed for handling dynamic memory
#include <string.h> //needed for some string functions

//the structure used for holding one superhero entry
typedef struct {
	char* name;
	short feetInHeight;
	short inchesInHeight;
	char* superpower;
	char* traits;
} Superhero;

// Declaration for loadSuperheroes function
int loadSuperheroes(const char* filename, Superhero*** superheroArray, int* numSuperheroes, int* arraySize);


//Creates a Superhero struct variable storing a pointer to a char array
// representing a name, two shorts representing feet in height and inches
// in height respectively, a pointer to a char array representing a superpower,
// and a pointer to a array representing an the traits.
//Returns the address of the dynamically (i.e., uses malloc) created variable

Superhero* createSuperhero(const char* name, 
                            short feetInHeight, short inchesInHeight,
                            const char* superpower, const char* traits);


//Releases the memory created to store the 3 fields name, superpower,
// and traits using the address of a Superhero struct variable. Note
// that the parameter can be NULL, and if this is the case the function 
// should do nothing.
//Also, this function does not release the memory used for the struct variable,
// but only those used by the variable's fields. To release all the memory
// dynamically allocated for the struct variable, you should call the free()
// function with the address of this struct variable right after the function
// returns.
void clearSuperhero(Superhero* superhero);

void cleanupSuperheroes(Superhero*** superheroArray, int* superheroCount);

//helper function to look up a superhero entry by superpower (Cstring)
//returns a dynamic array storing all the pointers to the superhero entries with
// superpower containing the input as a substring, NULL if not found.
//To make the size known to the caller, put a NULL as the last item. For example,
// if the first 3 entries have superpower containing "Fly",
// the array would have 4 items: {address_of_the_first_superhero,
// address_of_the_second_superhero, address_of_the_third_superhero, NULL}
Superhero** lookupSuperheroBySuperpower(Superhero **array, int size, 
									const char* superpower);

//helper function for the sorting function (e.g., qsort) to compare superheroes
// by height (int)
int compareSuperheroesByHeight(const void *p1, const void *p2);

//helper function for the sorting function (e.g., qsort) to compare superheroes
// by name (Cstring)
int compareSuperheroesByName(const void *p1, const void *p2);

//sort function (uncomment & implement if you are not using the built-in qsort)
//void sortSuperheros(Superhero **array, int size,
//					int(*compar)(const void *, const void *));

#endif