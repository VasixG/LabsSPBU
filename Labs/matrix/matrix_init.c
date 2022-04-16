#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix_init.h"

//make matrix structure
matrix * matrix_alloc (size_t h, size_t w){

    matrix *m = malloc(sizeof(matrix));

    if(!m) return NULL;

    m->data = malloc(h*w*sizeof(double));

    if(!m->data){
        free(m);
        return NULL;
    }

    m->h = h;
    m->w = w;

    return m;

}

//free struct matrix
void matrix_free(matrix *m){
    free(m->data);
    free(m);
}

//get element in matrix by cols and rows
double * matrix_get(const matrix *mat, size_t i, size_t j){
    return mat->data+mat->w*i +j;
}

//get element in const matrix
const double * matrix_cget(const matrix *mat, size_t i, size_t j){
    return mat->data+mat->w*i +j;
}

//safety get element in matrix by cols and rows
double * matrix_sget(const matrix *mat, size_t i, size_t j){
    if(!mat->data || i >= mat->h || j >= mat->w) return NULL;
    return matrix_get(mat, i, j);
}

//safety get element in matrix by cols and rows
const double * matrix_csget(const matrix *mat, size_t i, size_t j){
    if(!mat->data || i >= mat->h || j >= mat->w) return NULL;
    return matrix_cget(mat, i, j);
}

// clone matrix
matrix * matrix_clone (const matrix *m){

    if(!m) return NULL;

    matrix *cm = malloc(sizeof(matrix));

    if(!cm) return NULL;

    cm->h = m->h;
    cm->w = m->w;

    cm->data = malloc(cm->h * cm->w * sizeof(double));

    if(!cm->data){free(cm); return NULL;}

    memcpy(cm->data, m->data, cm->h * cm->w * sizeof(double));

    return cm;
}

// resize matrix
matrix * matrix_resize(const matrix *mat, size_t n_h, size_t n_w){

    matrix *cm, *nm;

    cm = matrix_clone(mat);

    nm = matrix_alloc(n_h, n_w);

    if(n_h == 0 || n_w == 0 || !cm || !nm){ matrix_free(nm); return cm;}

    size_t h_m = mat->h >= n_h? mat->h: n_h, w_m = mat->w >= n_w? mat->w: n_w;

    for(int i = 0; i < h_m; ++i){

        if(i < nm->h){
            if(i >= mat->h){
                for(int j = 0; j < n_w; ++j){
                    if(j < nm->w) *matrix_sget(nm, i, j) = 0;
                }
            }
            else{
                for(int j = 0; j < w_m; ++j){
                    if(j >= mat->w){
                        *matrix_sget(nm, i, j) = 0;
                    }else{
                        if(j < nm->w){
                            *matrix_sget(nm, i, j) = *matrix_sget(mat, i, j);
                        }
                    }
                }
            }
        }
    }

    matrix_free(cm);
    return nm;
}

// set matrix with zeros
matrix * matrix_set_zero (matrix *mat){

    if(!mat) return NULL;

    for(int i = 0; i < mat->h; ++i){
        for(int j = 0; j < mat->w; ++j){
            *matrix_sget(mat, i, j) = 0;
        }
    }
    return mat;
}

// new matrix with zeros, need matrix_free
matrix * matrix_alloc_zero (size_t h, size_t w){

    matrix *mat;

    mat = matrix_alloc(h, w);

    if(!mat) return NULL;

    matrix_set_zero(mat);

    return mat;
}

// set unitary matrix
matrix * matrix_set_unit (matrix *mat){

    if(mat->h != mat->w || !mat) return NULL;

    for(int i = 0; i < mat->h; ++i){
        for(int j = 0; j < mat->w; ++j){
            if(i != j){*matrix_sget(mat, i, j) = 0;}else{*matrix_sget(mat, i, j) = 1;}
        }
    }
    return mat;
}

// new unitary matrix, need matrix_free
matrix * matrix_alloc_unit (size_t h, size_t w){

    matrix *mat;

    mat = matrix_alloc(h, w);

    if(!mat) return NULL;

    matrix_set_unit(mat);

    return mat;
}

//assign m1 as m2
matrix * matrix_assign(matrix *mat1, const matrix * mat2){
    if(!mat1 || !mat2) return NULL;

    if(mat1->h != mat2->h || mat1->w != mat2->w){
        matrix *mr;
        mr = matrix_resize(mat2, mat1->h, mat1->w);
        if(!mr) return NULL;
        for(int i = 0; i < mat1->h; ++i){
            for(int j = 0; j < mat1->w; ++j){
                *matrix_sget(mat1, i, j) = *matrix_sget(mr, i, j);
            }
        }
        matrix_free(mr);
        return mat1;
    }

    for(int i = 0; i < mat1->h; ++i){
            for(int j = 0; j < mat1->w; ++j){
                *matrix_sget(mat1, i, j) = *matrix_sget(mat2, i, j);
            }
        }
    return mat1;

}

//full assign
matrix * matrix_full_assign(matrix *mat1, matrix * mat2){

    if(!mat1 || !mat2) return NULL;

    mat1->h = mat2->h;
    mat1->w = mat2->w;

    if(!mat1->data){mat1->data = malloc(mat2->h * mat2->w * sizeof(double));}
    else{mat1->data = realloc(mat1->data ,mat2->h * mat2->w * sizeof(double));}

    if(!mat1->data) return NULL;

    memcpy(mat1->data, mat2->data, mat2->h * mat2->w * sizeof(double));

    return mat1;
}
//set matrix
matrix * matrix_set(matrix *mat){

    if(!mat) return NULL;

    for(double *a = mat->data, *e = mat->data + mat->h*mat->w; a < e; ++a){
        scanf("%lf", a);
    }

    return mat;
}

//show matrix
const matrix * matrix_show(const matrix *mat){

    if(!mat) return NULL;

    for(int i = 0; i < mat->h; ++i){
        for(int j = 0; j < mat->w; ++j){
            printf("%.2lf\t", *matrix_sget(mat, i, j));
        }
        printf("\n");
    }
    return mat;
}
