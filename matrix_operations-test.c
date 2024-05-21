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
    const unsigned MATRIX_DIMENSION_SIZE = 4;

    MATRIX* a = create_matrix(MATRIX_DIMENSION_SIZE, MATRIX_DIMENSION_SIZE, set_matrix_a_item);
    MATRIX* b = create_matrix(MATRIX_DIMENSION_SIZE, MATRIX_DIMENSION_SIZE, set_matrix_b_item);
    MATRIX* c = sum_matrixes(a, b);

    printf("Matrix a:\n");
    print_matrix(a);

    printf("Matrix b:\n");
    print_matrix(b);

    printf("Matrix c:\n");
    print_matrix(c);

    for (int i = MATRIX_DIMENSION_SIZE - 1; i >= 0; i--) {
        for (int j = MATRIX_DIMENSION_SIZE - 1; j >= 0; j--) {
            if (i < j) assert(c->itens[i][j] == a->itens[i][j]);
            else if (i > j) assert(c->itens[i][j] == b->itens[i][j]);
            else assert(c->itens[i][j] == 2 * sqrt((i + 1) * (j + 1)));
        }
    }

    free_matrix(c);

    MATRIX* opposite_matrix_of_a = opposite_matrix_of(a);

    printf("Opposite matrix of a:\n");
    print_matrix(opposite_matrix_of_a);

    for (int i = MATRIX_DIMENSION_SIZE - 1; i >= 0; i--) {
        for (int j = MATRIX_DIMENSION_SIZE - 1; j >= 0; j--) {
            assert(opposite_matrix_of_a->itens[i][j] == -a->itens[i][j]);
        }
    }

    free_matrix(opposite_matrix_of_a);

    c = subtract_matrixes(a, b);

    printf("New matrix c:\n");
    print_matrix(c);

    for (int i = MATRIX_DIMENSION_SIZE - 1; i >= 0; i--) {
        for (int j = MATRIX_DIMENSION_SIZE - 1; j >= 0; j--) {
            if (i < j) assert(c->itens[i][j] == a->itens[i][j]);
            else if (i > j) assert(c->itens[i][j] == -b->itens[i][j]);
            else assert(c->itens[i][j] == 0);
        }
    }

    free_matrix(c);

    free_matrix(a);
    free_matrix(b);

    return 0;
}