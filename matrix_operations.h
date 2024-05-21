#include <stdio.h>
#include <stdlib.h>
#include "header.h"

bool matrices_have_same_order(MATRIX* a, MATRIX* b) {
    return (a->n_rows == b->n_rows && a->n_columns == b->n_columns);
}

bool matrices_are_equal(MATRIX* a, MATRIX* b) {
    if (!matrices_have_same_order(a, b)) return false;

    for (int i = a->n_rows - 1; i >= 0; i--) {
        for (int j = a->n_columns - 1; j >= 0; j--) {
            if (a->itens[i][j] != b->itens[i][j]) return false;
        }
    }

    return true;
}

MATRIX* sum_matrices(MATRIX* a, MATRIX* b) {
    if (!matrices_have_same_order(a, b)) {
        printf("Cannot sum matrices of different order.\n");
        exit(SUM_OF_MATRICES_OF_DIFFERENT_ORDER_ERROR);
    }

    MATRIX* result = create_matrix(a->n_rows, b->n_rows, set_null_matrix_item);

    for (int i = a->n_rows - 1; i >= 0; i--) {
        for (int j = a->n_columns - 1; j >= 0; j--) {
            result->itens[i][j] = a->itens[i][j] + b->itens[i][j];
        }
    }

    return result;
}

MATRIX* get_opposite_matrix_of(MATRIX* matrix) {
    MATRIX* result = create_matrix(matrix->n_rows, matrix->n_columns, set_null_matrix_item);

    for (int i = matrix->n_rows - 1; i >= 0; i--) {
        for (int j = matrix->n_columns - 1; j >= 0; j--) {
            result->itens[i][j] = -matrix->itens[i][j];
        }
    }

    return result;
}

MATRIX* subtract_matrices(MATRIX* a, MATRIX* b) {
    if (!matrices_have_same_order(a, b)) {
        printf("Cannot sum matrices of different order.\n");
        exit(SUM_OF_MATRICES_OF_DIFFERENT_ORDER_ERROR);
    }

    MATRIX* opposite_matrix_of_b = get_opposite_matrix_of(b);
    MATRIX* result = sum_matrices(a, opposite_matrix_of_b);

    free_matrix(opposite_matrix_of_b);

    return result;
}

MATRIX* multiply_matrices(MATRIX* a, MATRIX* b) {
    if (a->n_columns != b->n_rows) {
        printf("Cannot multiply matrices. Matrix a does not have the same number of columns of matrix b number of rows.\n");
        exit(INVALID_MULTIPLICATION_OF_MATRICES_ERROR);
    }

    MATRIX* result = create_matrix(a->n_rows, b->n_columns, set_null_matrix_item);

    for (int i = result->n_rows - 1; i >= 0; i--) {
        for (int j = result->n_columns - 1; j >= 0; j--) {
            for (int k = a->n_columns - 1; k >= 0; k--) {
                result->itens[i][j] += a->itens[i][k] * b->itens[k][j];
            }
        }
    }

    return result;
}