#include <assert.h>
#include <math.h>
#include "./../matrix.h"
#include "./../matrix_operations.h"

double set_matrix_a_item(unsigned i, unsigned j) {
    if (i <= j) return sqrt(i * j);
    return 0;
}

int main(void) {
    const unsigned MATRIX_DIMENSION_SIZE = 4;

    MATRIX* a = create_matrix(MATRIX_DIMENSION_SIZE, MATRIX_DIMENSION_SIZE, set_matrix_a_item);
    MATRIX* b = get_opposite_matrix_of(a);

    printf("Matriz A:\n");
    print_matrix(a);
    printf("\n");

    printf("Matriz B (oposta de A):\n");
    print_matrix(b);
    printf("\n");

    for (int i = b->n_rows - 1; i >= 0; i--) {
        for (int j = b->n_columns - 1; j >= 0; j--) {
            assert(b->itens[i][j] == -a->itens[i][j]);
        }
    }

    free_matrix(a);
    free_matrix(b);

    return 0;
}