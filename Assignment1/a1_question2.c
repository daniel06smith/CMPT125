/* ChatGPT was used to explore C syntax, and break down the assignment into steps.
Name: Daniel Smith
Student #: 301613547
Computing-ID: dcs7 */

#include "a1_question2.h"
#include <stdbool.h>

bool rangedCheckforSorted(int array[], unsigned int size, int leftIndex, int rightIndex) {
    // Handle out-of-bound indices
    if (leftIndex < 0) {
        leftIndex = 0;
    }
    if (rightIndex >= size) {
        rightIndex = size - 1;
    }
    
    // If leftIndex is greater than rightIndex, swap them
    if (leftIndex > rightIndex) {
        int temp = leftIndex;
        leftIndex = rightIndex;
        rightIndex = temp;
    }
    
    // Check if the array is sorted between leftIndex and rightIndex
    for (int i = leftIndex; i < rightIndex; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    
    return true;
}
