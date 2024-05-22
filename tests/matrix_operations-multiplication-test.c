#include "test.h"

int main(void) {
    const unsigned MATRIX_DIMENSION_SIZE = 4;

    MATRIX* a = create_matrix(MATRIX_DIMENSION_SIZE, MATRIX_DIMENSION_SIZE, set_matrix_a_item);
    MATRIX* b = create_matrix(MATRIX_DIMENSION_SIZE, MATRIX_DIMENSION_SIZE, set_matrix_b_item);
    MATRIX* c = multiply_matrices(a, b);

    printf("Matriz A:\n");
    print_matrix(a);
    printf("\n");

    printf("Matriz B:\n");
    print_matrix(b);
    printf("\n");

    printf("Matriz A * B (C):\n");
    print_matrix(c);
    printf("\n");

    for (int i = c->n_rows - 1; i >= 0; i--) {
        for (int j = c->n_columns - 1; j >= 0; j--) {
            double sum = 0;

            for (int k = a->n_columns - 1; k >= 0; k--) {
                sum +=  a->itens[i][k] * b->itens[k][j];
            }

            assert(c->itens[i][j] == sum);
        }
    }

    free_matrix(a);
    free_matrix(b);
    free_matrix(c);

    return 0;
}