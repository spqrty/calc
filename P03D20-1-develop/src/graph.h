#ifndef GRAPH_H
#define GRAPH_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int translate(double *new_arr, char *arr, int n, double x);
int input(char *arr);
struct operation *st(int vz, char symb, struct operation *lst, double *new_arr, int *na);
int s21_isdigit(char s);
void output(int mass[25][80]);
void mass_int(int mass[25][80], int n, char *arr);

#endif
