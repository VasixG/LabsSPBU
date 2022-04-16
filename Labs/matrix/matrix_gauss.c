#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix_init.h"
#include "matrix_operations.h"
#include "matrix_gauss.h"

//solve linear system of equations with gauss method
matrix * matrix_gauss_lse(const matrix * m, const matrix * v){

    if(!m || !v || m->h != m->w || m->h != v->h || v->w != 1 || !m->data) return NULL;

    size_t n = m->h;
    int k;
    double koef;

    matrix *mat, *vals;

    mat = matrix_clone(m);
    vals = matrix_clone(v);

    if(!mat || !vals ){matrix_free(mat); matrix_free(vals); return NULL;}

    for(int i = 0; i < n ; ++i){
        k = i;
        while(k != n && *matrix_sget(mat, k, i) == 0){
            ++k;
        }
        if(k < n){
            if(k != i){
                matrix_operations_rows_permutate(mat, i, k);
                matrix_operations_rows_permutate(vals, i, k);
            }
            for(int j = i + 1; j < n; ++j){
                koef = (-1)*((*matrix_sget(mat, j, i))/(*matrix_sget(mat, i, i)));
                matrix_operations_rows_add(mat, i, j, koef);
                matrix_operations_rows_add(vals, i, j, koef);
            }
        }
    }

    for(int i = n - 1 ; i >= 0; --i){
        if(*matrix_sget(mat, i, i) != 0){
            for(int j = i - 1; j >= 0; --j){
                koef = (-1)*((*matrix_sget(mat, j, i))/(*matrix_sget(mat, i, i)));
                matrix_operations_rows_add(mat, i, j, koef);
                matrix_operations_rows_add(vals, i, j, koef);
            }
            koef = 1/(*matrix_sget(mat, i, i));
            matrix_operations_sclar_mult_row(mat, i, koef);
            matrix_operations_sclar_mult_row(vals, i, koef);
        }else{
            printf("Matrix doesn't have inversion matrix\n");
            return NULL;
        }
    }

    matrix_free(mat);

    return vals;
}

//find inverse matrix with gauss method
matrix * matrix_gauss_inverse(const matrix * m){

    matrix *inv_mat;

    inv_mat = matrix_alloc_unit(m->h, m->w);

    if(!m || !inv_mat || m->h != m->w || !m->data){matrix_free(inv_mat); return NULL;}

    matrix *mat;

    mat = matrix_clone(m);

    if(!mat)return NULL;

    size_t n = m->h;
    int k;
    double koef;

    for(int i = 0; i < n ; ++i){
        k = i;
        while(k != n && *matrix_sget(mat, k, i) == 0){
            ++k;
        }
        if(k < n){
            if(k != i){
                matrix_operations_rows_permutate(mat, i, k);
                matrix_operations_rows_permutate(inv_mat, i, k);
            }
            for(int j = i + 1; j < n; ++j){
                koef = (-1)*((*matrix_sget(mat, j, i))/(*matrix_sget(mat, i, i)));
                matrix_operations_rows_add(mat, i, j, koef);
                matrix_operations_rows_add(inv_mat, i, j, koef);
            }
        }
    }

    for(int i = n - 1 ; i >= 0; --i){
        if(*matrix_sget(mat, i, i) != 0){
            for(int j = i - 1; j >= 0; --j){
                koef = (-1)*((*matrix_sget(mat, j, i))/(*matrix_sget(mat, i, i)));
                matrix_operations_rows_add(mat, i, j, koef);
                matrix_operations_rows_add(inv_mat, i, j, koef);
            }
            koef = 1/(*matrix_sget(mat, i, i));
            matrix_operations_sclar_mult_row(mat, i, koef);
            matrix_operations_sclar_mult_row(inv_mat, i, koef);
        }else{
            printf("Matrix doesn't have inversion matrix\n");
            return NULL;
        }
    }

    matrix_free(mat);

    return inv_mat;
}

//|mat[i][j]|<eps
matrix * matrix_gauss_eps(matrix * mat, double eps){

    if(!mat || !mat->data)return NULL;
    double el;

    for(int i = 0; i < mat->h; ++i){
        for(int j = 0; j < mat->w; ++j){
            el = *matrix_sget(mat, i, j);
            if(fabs(el) < eps){
                *matrix_sget(mat, i, j) = 0;
            }else{
                if(fabs(el - 1) < eps) *matrix_sget(mat, i, j) = 1;
            }
        }
    }
    return mat;
}
