#include "graph.h"

struct operation {
    struct operation *next;
    char info;
    int v;
};

double tp(char *a, int *i, int n) {
    int v = 0, len = n;
    int k, sch = 10;
    double ch = 0;
    while (s21_isdigit(a[(*i)]) != 0 && ((*i) < len)) {
        if (a[(*i)] == '.') {
            v = 1;
            (*i)++;
            continue;
        }
        if (v == 0) {
            k = (int)a[(*i)] - 48;
            ch = ch * 10 + k;

        } else {
            k = (int)a[(*i)] - 48;
            ch = ch + (double)k / (double)sch;
            sch *= 10;
        }
        (*i)++;
    }
    return ch;
}

struct operation *st(int vz, char symb, struct operation *p, double *new_arr, int *na) {
    while (p && p->v > vz) {
        if (p->info == 'm') {
            new_arr[*na] = -1 * new_arr[*na];
        } else if (p->info == 'u') {
            new_arr[(*na) - 1] = new_arr[(*na) - 1] * new_arr[(*na)];
            (*na)--;
        } else if (p->info == 'd') {
            new_arr[(*na) - 1] = new_arr[(*na) - 1] / new_arr[(*na)];
            (*na)--;
        } else if (p->info == 'b') {
            new_arr[(*na) - 1] = new_arr[(*na) - 1] - new_arr[(*na)];
            (*na)--;
        } else if (p->info == 'a') {
            new_arr[(*na) - 1] = new_arr[(*na) - 1] + new_arr[(*na)];
            (*na)--;
        } else if (p->info == 's') {
            new_arr[(*na)] = sin(new_arr[(*na)]);
        } else if (p->info == 'c') {
            new_arr[(*na)] = cos(new_arr[(*na)]);
        } else if (p->info == 'l') {
            new_arr[(*na)] = logl(new_arr[(*na)]);
        } else if (p->info == 'q') {
            new_arr[(*na)] = sqrt(new_arr[(*na)]);
        } else if (p->info == 't') {
            new_arr[(*na)] = tan(new_arr[(*na)]);
        } else if (p->info == 'g') {
            new_arr[(*na)] = 1 / (tan(new_arr[(*na)]));
        }
        struct operation *tek = p;
        p = p->next;
        free(tek);
    }
    struct operation *new = (struct operation *)malloc(sizeof(struct operation));
    new->info = symb;
    new->v = vz;
    new->next = p;
    p = new;
    return p;
}

int s21_isdigit(char s) {
    int ch = s, flag = 0;
    if (ch < 58 && ch > 47) flag = 1;
    return flag;
}

int translate(double *new_arr, char *arr, int n, double x) {
    int i = 0, na = -1, f = 0;
    struct operation *lst = NULL;
    while (i < n) {
        if (arr[i] == 'x') {
            new_arr[++na] = x;
            i++;
        } else if (arr[i] == '(') {
            f += 5;
            i++;
        } else if (arr[i] == ')') {
            f -= 5;
            i++;
        } else if (arr[i] == 's' && arr[i + 1] == 'i' && arr[i + 2] == 'n' && arr[i + 3] == '(') {
            char sym = 's';
            lst = st(4 + f, sym, lst, new_arr, &na);
            i += 3;
        } else if (arr[i] == 'c' && arr[i + 1] == 'o' && arr[i + 2] == 's' && arr[i + 3] == '(') {
            char sym = 'c';
            lst = st(4 + f, sym, lst, new_arr, &na);
            i += 3;
        } else if (arr[i] == 't' && arr[i + 1] == 'a' && arr[i + 2] == 'n' && arr[i + 3] == '(') {
            char sym = 't';
            lst = st(4 + f, sym, lst, new_arr, &na);
            i += 3;
        } else if (arr[i] == 'c' && arr[i + 1] == 't' && arr[i + 2] == 'g' && arr[i + 3] == '(') {
            char sym = 'g';
            lst = st(4 + f, sym, lst, new_arr, &na);
            i += 3;
        } else if (arr[i] == 's' && arr[i + 1] == 'q' && arr[i + 2] == 'r' && arr[i + 3] == 't' &&
                   arr[i + 4] == '(') {
            char sym = 'q';
            lst = st(4 + f, sym, lst, new_arr, &na);
            i += 4;
        } else if (arr[i] == 'l' && arr[i + 1] == 'n' && arr[i + 2] == '(') {
            char sym = 'l';
            lst = st(4 + f, sym, lst, new_arr, &na);
            i += 2;
        } else if (arr[i] == '-' && arr[i + 1] == '(') {
            char sym = 'm';
            lst = st(2 + f, sym, lst, new_arr, &na);
            i += 1;
        } else if (arr[i] == '-' && (i == 0 || arr[i - 1] == '(')) {
            char sym = 'm';
            lst = st(2 + f, sym, lst, new_arr, &na);
            i++;
        } else if (arr[i] == '*' || arr[i] == '/') {
            char sym;
            if (arr[i] == '*')
                sym = 'u';
            else
                sym = 'd';
            lst = st(3 + f, sym, lst, new_arr, &na);
            i += 1;
        } else if (arr[i] == '+' || arr[i] == '-') {
            char sym;
            if (arr[i] == '+')
                sym = 'a';
            else
                sym = 'b';
            lst = st(1 + f, sym, lst, new_arr, &na);
            i++;
        } else if (s21_isdigit(arr[i])) {
            new_arr[++na] = tp(arr, &i, n);
        } else
            i++;
    }
    while (lst) {
        if (lst->info == 'm') {
            new_arr[na] = -1 * new_arr[na];
        } else if (lst->info == 'u') {
            new_arr[na - 1] = new_arr[na - 1] * new_arr[na];
            na--;
        } else if (lst->info == 'd') {
            new_arr[na - 1] = new_arr[na - 1] / new_arr[na];
            na--;
        } else if (lst->info == 'b') {
            new_arr[(na)-1] = new_arr[na - 1] - new_arr[na];
            na--;
        } else if (lst->info == 'a') {
            new_arr[na - 1] = new_arr[na - 1] + new_arr[na];
            na--;
        } else if (lst->info == 's') {
            new_arr[na] = sin(new_arr[na]);
        } else if (lst->info == 'c') {
            new_arr[na] = cos(new_arr[na]);
        } else if (lst->info == 'l') {
            new_arr[na] = logl(new_arr[na]);
        } else if (lst->info == 'q') {
            new_arr[na] = sqrt(new_arr[na]);
        } else if (lst->info == 't') {
            new_arr[na] = tan(new_arr[na]);
        } else if (lst->info == 'g') {
            new_arr[na] = 1 / (tan(new_arr[na]));
        }
        struct operation *tek = lst;
        lst = lst->next;
        free(tek);
    }
    return na;
}
