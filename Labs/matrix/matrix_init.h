#ifndef MATRIX_INIT_H_INCLUDED
#define MATRIX_INIT_H_INCLUDED

typedef struct matrix{
    double *data;
    size_t h, w;
    }
 matrix;

matrix * matrix_alloc (size_t h, size_t w);//make matrix structure

void matrix_free(matrix *mat);//free struct matrix

matrix * matrix_clone (const matrix *m);// clone matrix

matrix * matrix_resize(const matrix *mat, size_t n_h, size_t n_w);// resize matrix

double * matrix_get(const matrix *mat, size_t i, size_t j);//get element in matrix by cols and rows

const double * matrix_cget(const matrix *mat, size_t i, size_t j);//get element in const matrix

double * matrix_sget(const matrix *mat, size_t i, size_t j);//safety get element in matrix by cols and rows

const double * matrix_csget(const matrix *mat, size_t i, size_t j);//safety get element in const matrix

matrix * matrix_set_zero (matrix *mat);// set matrix with zeros

matrix * matrix_alloc_zero (size_t h, size_t w);// new matrix with zeros, need matrix_free

matrix * matrix_set_unit (matrix *mat);// set unitary matrix

matrix * matrix_alloc_unit (size_t h, size_t w);// new unitary matrix, need matrix_free

matrix * matrix_assign(matrix *mat1, const matrix * mat2);//assign m1 as m2

matrix * matrix_full_assign(matrix *mat1, matrix * mat2);//assign m1 as m2

const matrix * matrix_show(const matrix *mat);//show double or int matrix

matrix * matrix_set(matrix *mat);//set matrix

#endif // MATRIX_INIT_H_INCLUDED
