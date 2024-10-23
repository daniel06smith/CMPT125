#include <stdio.h>
int main() {
    char str[10] = {'a', 'b', 'c', 0, '1', '2'};
    char* ptr = str;
    printf("%s\n", ptr+1);
    return 0;
}

// Ouput: bc
/*Explanation:
ptr+1 places the pointer at the second index ('b'), and the function
iterates through the array until it reaches the null value (0), in which
the function stops. hence, the output is simply, "bc".*/