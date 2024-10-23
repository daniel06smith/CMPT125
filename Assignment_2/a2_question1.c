/*
SFU ID: 301613547
Computing ID: dcs7
Name: Daniel Smith

Note: ChatGPT was used to break down the question, translate C language into
Python, a language I know better, for translational understanding, and for
extrapolation on C functions (asking questions about why/why not x, y, z).*/

#include"a2_question1.h"

int replaceDigitsRecursive(int number, char target, char replacement){
    int negative = 0; // Flag to check for negative number.

    if (number < 0){
        negative = 1; // Flag is raised.
        number = -number; // Make number positive temporarily.
    }

    if (target < '0' || target > '9' || replacement < '0' || replacement > '9'){
        return number; // Returns original number input if the number is invalid.
    }

    // Base Case
    if (number == 0){
        return 0; // Returns 0 if the number is 0.
    }

    // Extracting the last digit of number
    int last_digit = number % 10;
    if (last_digit == (target - '0')){
        last_digit = replacement - '0';
    }

    // Calling the recursive function to process the rest of the number
    int rest_of_number = replaceDigitsRecursive(number/10, target, replacement);
    int result = rest_of_number * 10 + last_digit;

    // If the negative flag is raised, reverts the number to negative.
    if (negative == 1){
        result = -result;
    }
    
    return result;
    
}