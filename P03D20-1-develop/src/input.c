#include "graph.h"

int input(char *arr) {
    int n = 0;
    char s;
    scanf("%c", &s);
    while (s != '\n') {
        arr[n++] = s;
        arr = (char *)realloc(arr, sizeof(char) * n);
        scanf("%c", &s);
    }
    return n;
}