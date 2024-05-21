#include <stdio.h>
#include <stdlib.h>
#include "header.h"

MATRIX* create_matrix(unsigned n_rows, unsigned n_columns, SET_MATRIX_ITEM_FUNCTION set_item) {
    MATRIX* matrix = (MATRIX*) malloc(sizeof(MATRIX));

    if (matrix == NULL) {
        printf("Error allocating memory for matrix.\n");
        exit(MATRIX_ALLOCATION_ERROR);
    }

    matrix->n_rows = n_rows;
    matrix->n_columns = n_columns;

    matrix->itens = (double**) malloc(sizeof(double*) * n_rows);

    if (matrix->itens == NULL) {
        printf("Error allocating memory for matrix rows.\n");
        exit(MATRIX_ROWS_ALLOCATION_ERROR);
    }

    for (int i = n_rows - 1; i >= 0; i--) {
        matrix->itens[i] = (double*) malloc(sizeof(double) * n_columns);

        if (matrix->itens[i] == NULL) {
            printf("Error allocating memory for matrix columns.\n");
            exit(MATRIX_COLUMNS_ALLOCATION_ERROR);
        }

        for (int j = n_columns; j >= 0; j--) {
            matrix->itens[i][j] = set_item(i + 1, j + 1);
        }
    }

    return matrix;
}

void  print_matrix(MATRIX* matrix) {
    for (int i = 0; i < matrix->n_rows; i++) {
        for (int j = 0; j < matrix->n_columns; j++) {
            if (j == 0) printf("| ");

            printf("%lf", matrix->itens[i][j]);

            if (j == matrix->n_columns - 1) printf(" |");
            else printf("\t");
        }

        printf("\n");
    }
}

void free_matrix(MATRIX* matrix) {
    for (int i = matrix->n_rows - 1; i >= 0; i--) {
        free(matrix->itens[i]);
    }

    free(matrix->itens);
    free(matrix);
}

double set_null_matrix_item(unsigned i, unsigned j) {
    return 0;
}