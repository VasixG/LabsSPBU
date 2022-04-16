#ifndef MATRIX_GAUSS_H_INCLUDED
#define MATRIX_GAUSS_H_INCLUDED


matrix * matrix_gauss_lse(const matrix * mat, const matrix * vals);//solve linear system of equations with gauss method

matrix * matrix_gauss_inverse(const matrix * mat);//find inverse matrix with gauss method

matrix * matrix_gauss_eps(matrix * mat, double eps);//|mat[i][j]|<eps

#endif // MATRIX_GAUSS_H_INCLUDED
