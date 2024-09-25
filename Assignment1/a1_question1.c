// ChatGPT was used to explore C syntax, and break down the assignment into steps.

#include "a1_question1.h"

/*
  Helper function to check if a character is a digit ('0' to '9').
  Returns 1 if the character is a digit, 0 otherwise.
*/
int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int replaceDigits(int number, char target, char replacement) {
    // Check if target and replacement are valid digits using our helper function
    if (!is_digit(target) || !is_digit(replacement)) {
        return number;
    }

    // Convert target and replacement to their integer forms
    char target_digit = target - '0';
    char replacement_digit = replacement - '0';

    // Handle negative numbers
    int is_negative = (number < 0);
    if (is_negative) {
        number = -number;  // Make number positive for easier processing
    }

    int result = 0;
    int multiplier = 1;

    // Process each digit of the number from the last to the first
    while (number > 0) {
        int digit = number % 10;
        if (digit == target_digit) {
            result += replacement_digit * multiplier;
        } else {
            result += digit * multiplier;
        }
        multiplier *= 10;
        number /= 10;
    }

    // If the number was 0 and we are replacing 0, return the correct result
    if (result == 0 && target_digit == 0 && replacement_digit != 0) {
        result = replacement_digit;
    }

    // Restore the negative sign if the original number was negative
    return is_negative ? -result : result;
}