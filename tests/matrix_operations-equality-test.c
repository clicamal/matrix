#include "test.h"

int main(void) {
    const unsigned MATRIX_DIMENSION_SIZE = 4;

    MATRIX* a = create_matrix(MATRIX_DIMENSION_SIZE, MATRIX_DIMENSION_SIZE, set_matrix_a_item);
    MATRIX* b = get_opposite_matrix_of(a);
    MATRIX* identity = create_matrix(MATRIX_DIMENSION_SIZE, MATRIX_DIMENSION_SIZE, set_identity_matrix_item);
    MATRIX* c = multiply_matrices(a, identity);

    printf("Matriz A:\n");
    print_matrix(a);
    printf("\n");

    printf("Matriz B (oposta de A):\n");
    print_matrix(b);
    printf("\n");

    printf("Matriz Identidade:\n");
    print_matrix(identity);
    printf("\n");

    printf("Matriz C (A * I):\n");
    print_matrix(c);
    printf("\n");

    assert(matrices_are_equal(a, b) == false);
    assert(matrices_are_equal(a, a) == true);
    assert(matrices_are_equal(a, c) == true);

    free_matrix(a);
    free_matrix(b);
    free_matrix(identity);
    free_matrix(c);

    return 0;
}