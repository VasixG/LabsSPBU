#ifndef MATRIX_OPERATIONS_H_INCLUDED
#define MATRIX_OPERATIONS_H_INCLUDED

matrix * matrix_operations_sum (const matrix *m1, const matrix *m2);// add two matrix if it is allowed (return third matrix)

matrix * matrix_operations_add (matrix *m1, const matrix *m2);// add m2 to m1

matrix * matrix_operations_mult(const matrix *m1, const matrix *m2);// multiply two matrix if it is allowed (return third matrix)

matrix * matrix_operations_mult_to(matrix *m1, const matrix *m2);// multiply m2 to m1

matrix * matrix_operations_transpose(matrix *mat);//transpose matrix

matrix * matrix_operations_sclar_mult(matrix *mat, double s);//multiply matrix and scalar

matrix * matrix_operations_sclar_mult_row(matrix *mat, size_t i, double s);// multiply scalar to row

matrix * matrix_operations_rows_add (matrix *mat, size_t i, size_t j, double k);// add i row to j row

matrix * matrix_operations_rows_permutate(matrix *mat, size_t i, size_t j);// permutation j row and i row

#endif // MATRIX_OPERATIONS_H_INCLUDED
