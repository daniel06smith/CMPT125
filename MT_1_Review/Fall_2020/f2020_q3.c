int bar(int n) {
    int i = 0, sum = 0;
    while (2*sum-1 < n) {
        i++;
        sum += i;
    }
    return i;
}

