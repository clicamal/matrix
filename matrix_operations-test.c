#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "matrix.h"
#include "matrix_operations.h"

double set_matrix_a_item(unsigned i, unsigned j) {
    if (i <= j) return sqrt(i * j);
    return 0;
}

double set_matrix_b_item(unsigned i, unsigned j) {
    if (i >= j) return sqrt(i * j);
    return 0;
}

int main(void) {
    MATRIX* a = create_matrix(4, 4, set_matrix_a_item);
    MATRIX* b = create_matrix(4, 4, set_matrix_b_item);
    MATRIX* c = sum_matrixes(a, b);

    printf("Matrix a:\n");
    print_matrix(a);

    printf("Matrix b:\n");
    print_matrix(b);

    printf("Matrix c:\n");
    print_matrix(c);

    for (int i = 4 - 1; i >= 0; i--) {
        for (int j = 4 - 1; j >= 0; j--) {
            if (i < j) assert(c->itens[i][j] == a->itens[i][j]);
            else if (i > j) assert(c->itens[i][j] == b->itens[i][j]);
            else assert(c->itens[i][j] = 2 * sqrt((i + 1) * (j + 1)));
        }
    }

    return 0;
}