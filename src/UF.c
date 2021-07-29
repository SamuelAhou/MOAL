//
// Created by Samuel on 20/07/2021.
//

#include "Tools.h"
#include "stdlib.h"
#include "stdio.h"
#include "assert.h"
#include "UF.h"


float** zeros(size_t m, size_t n){

    float** zero_ptr = calloc(m, sizeof(float*));
    assert(zero_ptr != NULL);
    addAddr(m, zero_ptr);

    for (int i = 0; i < m; ++i) {
        zero_ptr[i] = calloc(n, sizeof(float));
        assert(zero_ptr[i] != NULL);
    }

    return zero_ptr;
}


float** ones(size_t m, size_t n){

    float** ones_ptr = calloc(m, sizeof(float*));
    assert(ones_ptr != NULL);
    addAddr(m, ones_ptr);

    for (int i = 0; i < m; ++i) {
        ones_ptr[i] = calloc(n, sizeof(float));
        assert(ones_ptr[i] != NULL);
        for (int j = 0; j < n; ++j) {
            ones_ptr[i][j] = 1;
        }
    }

    return ones_ptr;
}


float** eye(size_t n){

    float** eye_ptr = calloc(n, sizeof(float*));
    assert(eye_ptr != NULL);
    addAddr(n, eye_ptr);

    for (int i = 0; i < n; ++i) {
        eye_ptr[i] = calloc(n, sizeof(float));
        assert(eye_ptr[i] != NULL);
        eye_ptr[i][i] = 1;
    }

    return eye_ptr;

}


float** matrixFromInputs(size_t m, size_t n){

    float** A = zeros(m,n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            float temp = 0;
            printf("Entry (%d, %d) : \t", i+1, j+1);
            scanf("%f", &A[i][j]);
        }
    }

    return A;
}


float** matrixFromArray(size_t m, size_t n, float array[m*n]){

    float** A = zeros(m, n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = array[i*m + j];
        }
    }

    return A;
}


void freeMatrix(size_t m,  float** A){

    for (int i = 0; i < m; ++i) {
        free(A[i]);
    }
    free(A);
}


void displayMatrix(size_t m, size_t n, float** A){

    printf("\n[");

    for (int i = 0; i < m; ++i) {

        if (i != 0){
            printf(" [");
        }else{
            printf("[");
        }

        for (int j = 0; j < n; ++j) {

            if(j != n-1){
                printf("%.2f   ", A[i][j]);
            } else{
                printf("%.2f", A[i][j]);
            }

        }
        if (i != m-1){
            printf("]\n");
        } else{
            printf("]");
        }

    }

    printf("]\n\n");
}

float** getSubMatrix(int m, int n, int k, int l, float** A){

    float** B = zeros(k - m + 1, l - n + 1);

    for (int i = 0; i <= k-m; ++i) {
        for (int j = 0; j <= l-n; ++j) {
            B[i][j] = A[i+m][j+n];
        }
    }
    return B;

}


void setSubMatrix(int m, int n, int k, int l, float** A, float** B){

    for (int i = 0; i <= k-m; ++i) {
        for (int j = 0; j <= l-n; ++j) {
            A[i+m][j+n] = B[i][j];
        }
    }

}


