#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

bool matrixes_have_same_order(MATRIX* a, MATRIX* b) {
    return (a->n_rows == b->n_rows && a->n_columns == b->n_columns);
}

MATRIX* sum_matrixes(MATRIX* a, MATRIX* b) {
    if (!matrixes_have_same_order(a, b)) {
        printf("Cannot sum matrixes of different order.\n");
        exit(SUM_OF_MATRIXES_OF_DIFFERENT_ORDER_ERROR);
    }

    MATRIX* result = create_matrix(a->n_rows, b->n_rows, set_null_matrix_item);

    for (int i = a->n_rows - 1; i >= 0; i--) {
        for (int j = a->n_columns - 1; j >= 0; j--) {
            result->itens[i][j] = a->itens[i][j] + b->itens[i][j];
        }
    }

    return result;
}

MATRIX* opposite_matrix_of(MATRIX* matrix) {
    MATRIX* result = create_matrix(matrix->n_rows, matrix->n_columns, set_null_matrix_item);

    for (int i = matrix->n_rows - 1; i >= 0; i--) {
        for (int j = matrix->n_columns - 1; j >= 0; j--) {
            result->itens[i][j] = -matrix->itens[i][j];
        }
    }

    return result;
}

MATRIX* subtract_matrixes(MATRIX* a, MATRIX* b) {
    if (!matrixes_have_same_order(a, b)) {
        printf("Cannot sum matrixes of different order.\n");
        exit(SUM_OF_MATRIXES_OF_DIFFERENT_ORDER_ERROR);
    }

    MATRIX* opposite_matrix_of_b = opposite_matrix_of(b);
    MATRIX* result = sum_matrixes(a, opposite_matrix_of_b);

    free_matrix(opposite_matrix_of_b);

    return result;
}