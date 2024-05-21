#include <stdio.h>
#include <stdlib.h>
#include "header.h"

MATRIX* sum_matrixes(MATRIX* a, MATRIX* b) {
    if (a->n_rows != b->n_rows || a->n_columns != b->n_columns) {
        printf("Cannot sum matrixes of different order.");
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