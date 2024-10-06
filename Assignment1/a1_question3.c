#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a 2x3 array dynamically
    int rows = 2, cols = 3;
    int** my2DIntArray = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        my2DIntArray[i] = (int*)malloc(cols * sizeof(int));
    }
    // Initialize array with values [[0, 1, -2], [-999, 2345, 678]]
    my2DIntArray[0][0] = 0;   my2DIntArray[0][1] = 1;   my2DIntArray[0][2] = -2;
    my2DIntArray[1][0] = -999; my2DIntArray[1][1] = 2345; my2DIntArray[1][2] = 678;

    // Call the reversePolarity function
    reversePolarity(rows, cols, my2DIntArray);

    // Print the array after reversing polarity
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", my2DIntArray[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(my2DIntArray[i]);
    }
    free(my2DIntArray);

    return 0;
}
