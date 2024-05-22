#include <assert.h>
#include "./../matrix.h"

double set_triangular_superior_matrix_item(unsigned i, unsigned j) {
    if (i <= j) return 1;
    return 0;
}

int main(void) {
    MATRIX* matrix = create_matrix(4, 4, set_triangular_superior_matrix_item);

    assert(matrix->n_rows == 4);
    assert(matrix->n_columns == 4);

    for (int i = matrix->n_rows - 1; i >= 0; i--) {
        for (int j = matrix->n_columns - 1; j >= 0; j--) {
            if (i <= j) assert(matrix->itens[i][j] == 1);
            else assert(matrix->itens[i][j] == 0);
        }
    }

    printf("Matriz triangular superior:\n");
    print_matrix(matrix);

    free_matrix(matrix);

    return 0;
}