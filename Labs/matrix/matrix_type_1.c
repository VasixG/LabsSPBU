#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "matrix.h"
#include "matrix_operations.h"

//make matrix structure
void * matrix_alloc(struct matrix * mat, size_t h, size_t w, size_t bbyte, size_t p_bbyte){

    mat->byte = bbyte;
    mat->p_byte = p_bbyte;
    mat->h = h;
    mat->w = w;

    mat->data = malloc(h * p_bbyte);

    if(!mat->data){
        return NULL;
    }

    for(int i = 0; i < h; ++i){

        mat->data[i] = malloc(w * bbyte);

        if(!mat->data[i]){
        return NULL;
    }

    }
    return mat;
}

//free struct matrix
void matrix_free(struct matrix * mat){

    for(int i = 0; i < mat->h; ++i){
        free(mat->data[i]);
    }

    free(mat->data);
}

// clone matrix
void * matrix_clone(const struct matrix *mat, struct matrix *cmat){

    cmat->byte = mat->byte;
    cmat->p_byte = mat->p_byte;
    cmat->h = mat->h;
    cmat->w = mat->w;
    cmat->data = malloc(cmat->h * cmat->p_byte);

    if(!cmat->data){
        return NULL;
    }

    memcpy(cmat->data, mat->data, cmat->h * cmat->p_byte);

    for(int i = 0; i < cmat->h; ++i){

        cmat->data[i] = malloc(cmat->w * cmat->byte);

        if(!cmat->data[i]){
            return NULL;
        }

        memcpy(cmat->data[i], mat->data[i], cmat->h * cmat->byte);

    }

    return cmat;
}

//get element in matrix by cols an rows
void *matrix_get(struct matrix *mat, size_t i, size_t j){
    return mat->data[i] + j*mat->byte;
}

//get element in matrix by n
void *matrix_cget(struct matrix *mat, size_t n){
    return mat->data[n/mat->h] + mat->byte*(n - n/mat->h);
}

// set matrix with zeros
struct matrix * matrix_set_zero (struct matrix *mat){

    if(mat->byte != sizeof(int) && mat->byte != sizeof(double)){
        return NULL;
    }

    for (void **a = mat->data, **e = mat->data + mat->h*mat->p_byte; *a < *e; *a+=mat->p_byte){
        for (void *b = *a, *eb = *a + mat->byte*mat->w; b < eb; b+=mat->byte){
            if(mat->byte == sizeof(double)){

                double c = 0.0;
                b = &c;

                }else{

                int c = 0;
                b = &c;

            }

        }
    }

    return mat;
}


void matrix_double_int_show(const struct matrix *mat){



}
