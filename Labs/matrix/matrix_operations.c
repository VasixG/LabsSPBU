#include <stdio.h>
#include <stdlib.h>

#include "matrix_init.h"
#include "matrix_operations.h"

// add two matrix if it is allowed (return third matrix)
matrix * matrix_operations_sum (const matrix *m1, const matrix *m2){

    if(!m1 || !m2) return NULL;

    matrix *nm;

    nm = matrix_alloc(m1->h, m1->w);

    matrix_assign(nm, m2);

    for(int i = 0; i < m1->h; ++i){
        for(int j = 0; j < m1->w;++j){
            *matrix_sget(nm, i, j) += *matrix_sget(m1, i, j);
        }
    }
    return nm;

}

// add m2 to m1
matrix * matrix_operations_add (matrix *m1, const matrix *m2){

    if(!m1 || !m2) return NULL;

    size_t h_m = m1->h >= m2->h? m2->h: m1->h, w_m = m1->w >= m2->w? m2->w: m1->w;

    for(int i = 0; i < h_m; ++i){
        for(int j = 0; j < w_m;++j){
            *matrix_sget(m1, i, j) += *matrix_sget(m2, i, j);
        }
    }
    return m1;
}

// multiply two matrix if it is allowed (return third matrix)
matrix * matrix_operations_mult(const matrix *m1, const matrix *m2){

    if(!m1 || !m2 || m1->w != m2->h ) return NULL;

     matrix *nm;

     nm = matrix_alloc(m1->h, m2->w);

     for(int i = 0; i < m1->h; ++i){
        for(int j = 0; j < m2->w; ++j){
            double sm = 0;
            for(int k = 0; k < m1->w; ++k){
                sm += (*matrix_sget(m1, i, k)) * (*matrix_sget(m2, k, j));
            }
            *matrix_sget(nm, i, j) = sm;
        }
     }

     return nm;
}

// multiply m2 to m1
matrix * matrix_operations_mult_to(matrix *m1, const matrix *m2){

    if(!m1 || !m2 || m1->w != m2->h ) return NULL;

     matrix *nm;

     nm = matrix_alloc(m1->h, m2->w);

     for(int i = 0; i < m1->h; ++i){
        for(int j = 0; j < m2->w; ++j){
            double sm = 0;
            for(int k = 0; k < m1->w; ++k){
                sm += (*matrix_sget(m1, i, k)) * (*matrix_sget(m2, k, j));
            }
            *matrix_sget(nm, i, j) = sm;
        }
     }

     matrix_full_assign(m1, nm);
     matrix_free(nm);

     return m1;
}

//transpose matrix
matrix * matrix_operations_transpose(matrix *mat){

    if(!mat)return NULL;

    matrix *nm;

    nm = matrix_alloc(mat->w, mat->h);

    for(int i = 0; i < mat->h; ++i){
        for(int j = 0; j < mat->w; ++j){
            *matrix_sget(nm, j, i) = *matrix_sget(mat, i, j);
        }
    }

    matrix_full_assign(mat, nm);
    matrix_free(nm);
    return mat;
}

// multiply matrix and scalar
matrix * matrix_operations_sclar_mult(matrix *mat, double s){

    if(!mat)return NULL;

    for(int i = 0; i < mat->h; ++i){
        for(int j = 0; j < mat->w; ++j){
            *matrix_sget(mat, i, j) *= s;
        }
    }

    return mat;
}

// multiply matrix and scalar
matrix * matrix_operations_sclar_mult_row(matrix *mat, size_t i, double s){

    if(!mat)return NULL;

    for(int j = 0; j < mat->w; ++j){
        *matrix_sget(mat, i, j) *= s;
    }

    return mat;
}

// add i row to j row
matrix * matrix_operations_rows_add (matrix *mat, size_t i, size_t j, double s){

    if(!mat)return NULL;

    for(int k = 0; k < mat->w; ++k){
        *matrix_sget(mat, j, k) += (*matrix_sget(mat, i, k)) * s;
    }

    return mat;
}

// permutation j row and i row
matrix * matrix_operations_rows_permutate(matrix *mat, size_t i, size_t j){
    if(!mat)return NULL;
    double y;

    for(int k = 0; k < mat->w; ++k){
        y = *matrix_sget(mat, j, k);
        *matrix_sget(mat, j, k) = *matrix_sget(mat, i, k);
        *matrix_sget(mat, i, k) = y;
    }

    return mat;
}

