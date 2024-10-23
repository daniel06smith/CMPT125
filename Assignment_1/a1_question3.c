/* ChatGPT was used to explore C syntax, and break down the assignment into steps.
Name: Daniel Smith
Student #: 301613547
Computing-ID: dcs7 */

// a1_question3.c
#include "a1_question3.h"

void reversePolarity(unsigned int row, unsigned int col, int** array) {
    for (unsigned int i = 0; i < row; i++) {
        for (unsigned int j = 0; j < col; j++) {
            // Reverse the polarity of the element at array[i][j] using pointer arithmetic
            *(*(array + i) + j) = -(*(*(array + i) + j));
        }
    }
}