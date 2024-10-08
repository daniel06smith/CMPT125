/*
Header file for Assignment 1 Question 1.
Do not modify or submit.
*/
#ifndef _A1_QUESTION1_H_
#define _A1_QUESTION1_H_

/*
A function that replaces a specific digit in an int number with another digit
and returns the result as an int.
return the same number if the target/replacement character is not a digit
Input: number - the number to be modified
       target - the digit to be replaced
       replacement - the digit used for replacement
Returns: the modified number
*/
int replaceDigits(int number, char target, char replacement);

#endif