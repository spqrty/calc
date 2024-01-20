#include "graph.h"

int main() {
    char *arr = malloc(sizeof(char));
    int n = input(arr);
    int m[26][80];
    mass_int(m, n, arr);
    output(m);
    free(arr);
    return 0;
}
