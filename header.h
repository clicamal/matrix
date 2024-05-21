#pragma once

typedef enum MATRIX_ERRORS {
    MATRIX_ALLOCATION_ERROR = 1,
    MATRIX_ROWS_ALLOCATION_ERROR,
    MATRIX_COLUMNS_ALLOCATION_ERROR,
    SUM_OF_MATRICES_OF_DIFFERENT_ORDER_ERROR,
    INVALID_MULTIPLICATION_OF_MATRICES_ERROR
} MATRIX_ERRORS;

typedef double (*SET_MATRIX_ITEM_FUNCTION)(unsigned i, unsigned j);

typedef struct MATRIX {
    unsigned n_rows;
    unsigned n_columns;

    double **itens;
} MATRIX;

MATRIX* create_matrix(unsigned n_rows, unsigned n_columns, SET_MATRIX_ITEM_FUNCTION set_item);
void  print_matrix(MATRIX* matrix);
void free_matrix(MATRIX* matrix);
double set_null_matrix_item(unsigned i, unsigned j);