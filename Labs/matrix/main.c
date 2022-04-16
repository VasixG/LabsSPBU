#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix_init.h"
#include "matrix_operations.h"
#include "matrix_gauss.h"
#include "matrix_exponent.h"

/*
Author: Vasiliy Gorelov
Date: 13.04.2022
License: None
Education: SPBU
*/

/*
Library to work with matrix
*/
int main()
{
    //Gauss LSE
    printf("------------------------\n");
    printf("Check solving linear system of equations by Gauss \n");
    matrix *m2, *v2, *res;
    double a2[9] = {1, 0, 0, 0, 2, 0, 0, 0, -1}, c2[3] = {1, 2, -1};

    m2 = matrix_alloc(3, 3);
    v2 = matrix_alloc(3, 1);

    memcpy(m2->data, a2, m2->h*m2->w*sizeof(double));
    if(!m2->data)return -100;

    memcpy(v2->data, c2, v2->h*v2->w*sizeof(double));
    if(!v2->data)return -100;

    res = matrix_gauss_lse(m2, v2);
    if(res){
        printf("Matrix m2:\n");
        matrix_show(m2);printf("\n");
        printf("Constants matrix:\n");
        matrix_show(v2);printf("\n");
        printf("Results:\n");
        matrix_show(res);printf("\n");

        matrix_free(res);

        }
    matrix_free(m2);matrix_free(v2);

    printf("------------------------\n");
    //Gauss inversion matrix
    printf("------------------------\n");
    printf("Check inversing matrix by Gauss \n");
    matrix *m3, *inv, *mmr, *mml;
    double a3[9] = {1, 0, 0, 0, 2, 0, 0, 0, -1};

    m3 = matrix_alloc(3, 3);

    memcpy(m3->data, a3, m3->h*m3->w*sizeof(double));
    if(!m3->data)return -100;

    inv = matrix_gauss_inverse(m3);
    if(inv){
        printf("Matrix m3:\n");
        matrix_show(m2);printf("\n");
        printf("Inverse matrix:\n");
        matrix_show(inv);printf("\n");

        mmr = matrix_gauss_eps(matrix_operations_mult(inv, m3), 0.001);

        mml = matrix_gauss_eps(matrix_operations_mult(m3, inv), 0.001);

        printf("Inv*Mat3:\n");
        matrix_show(mmr);printf("\n");
        printf("Mat3*Inv:\n");
        matrix_show(mml);printf("\n");

        matrix_free(inv);matrix_free(mml);matrix_free(mmr);

        }
    matrix_free(m3);

    printf("------------------------\n");

    //matrix exponent
    printf("------------------------\n");
    printf("Check matrix exponent\n");
    matrix *m1, *exp;
    double a[9] = {1, 0, 0, 0, 2, 0, 0, 0, -1};

    m1 = matrix_alloc(3, 3);

    memcpy(m1->data, a, m1->h*m1->w*sizeof(double));
    if(!m1->data)return -100;

    exp = matrix_exp(m1, 0.01);
    printf("Matrix m1:\n");
    matrix_show(m1);printf("\n");
    printf("Exponent matrix:\n");
    matrix_show(exp);printf("\n");

    matrix_free(m1);matrix_free(exp);
    printf("------------------------\n");

    return 0;
}
