#include <assert.h>
#include <math.h>
#include "./../matrix.h"
#include "./../matrix_operations.h"

double set_matrix_a_item(unsigned i, unsigned j) {
    if (i <= j) return sqrt(i * j);
    return 0;
}

double set_matrix_b_item(unsigned i, unsigned j) {
    if (i >= j) return sqrt(i * j);
    return 0;
}