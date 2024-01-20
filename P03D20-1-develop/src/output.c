#include "graph.h"

void mass_int(int mass[26][80], int n, char *arr) {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 80; j++) {
            mass[i][j] = 0;
        }
    }
    for (int j = 0; j < 80; j++) {
        double new_arr[n];
        double x = j * M_PI / 20.0;
        translate(new_arr, arr, n, x);
        double y = new_arr[0];
        if ((y >= -1) && (y <= 1)) {
            int i = lround(y * 12.0) + 13;
            mass[i][j] = 1;
        }
    }
}

void output(int mass[26][80]) {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 80; j++) {
            if (mass[i][j] == 0)
                printf(".");
            else
                printf("*");
        }
        printf("\n");
    }
}