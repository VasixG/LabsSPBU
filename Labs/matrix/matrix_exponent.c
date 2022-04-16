#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix_init.h"
#include "matrix_operations.h"
#include "matrix_exponent.h"

//find matrix norm
double matrix_norm(const matrix *m){

    if(!m || !m->data) return 0;
    double max, srow;

    for(int i = 0; i < m->w; ++i){
        max +=  fabs(*matrix_sget(m, 0, i));
    }

    for(int i = 1; i < m->h; ++i){
        srow = 0;
        for(int j = 0; j < m->w; ++j){
            srow += fabs(*matrix_sget(m, i, j));
        }
        if(srow > max){
            max = srow;
        }
    }
    return max;
}

//find matrix exponent
matrix * matrix_exp(const matrix * m, double eps){

    if(!m) return NULL;

    matrix *mat_exp, *an;

    mat_exp = matrix_alloc_unit(m->h, m->w);
    if(!mat_exp) return NULL;

    an = matrix_alloc_unit(m->h, m->w);
    if(!an){matrix_free(mat_exp); return NULL;}

    if(!mat_exp) return NULL;

    double n = 1, norm = 1;

    while(norm > eps){
        matrix_operations_sclar_mult(matrix_operations_mult_to(an, m),1/n);//an = a(n-1)*Mat*1/n
        matrix_operations_add(mat_exp, an);//MatExp += an
        norm = matrix_norm(an);//  ||an||
        ++n;
    }

    matrix_free(an);
    return mat_exp;
}
