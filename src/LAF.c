//
// Created by Samuel on 10/07/2021.
//

#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "LAF.h"
#include "UF.h"
#include "Tools.h"


typedef struct factorizationPair {

    float** F;
    float** G;

} Pair;


float** add(size_t m, size_t n, float** A, float** B){

    float** C = zeros(m, n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}


float** sub(size_t m, size_t n, float** A, float** B){

    float** C = zeros(m,n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}


float** scale(size_t m, size_t n, float** A, float a){

    float** B = zeros(m,n);
    printf("%p\n", &B);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            B[i][j] = a*A[i][j];
        }
    }

    return B;
}


float norm(float** x, size_t size, int p){

    float result = 0;

    for (int i = 0; i < size; ++i) {
        result += powf(fabs(x[0][i]), p);
    }

    return powf(result, 1.0/p);
}


float dot(float** x, float** y, int size){

    float result = 0;

    for (int i = 0; i < size; ++i) {
        result += x[0][i]*y[0][i];
    }

    return result;
}


float** matrixProduct(size_t m, size_t n, size_t p, float** A, float** B){

    float** C = zeros(m,p);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}


float** transpose(size_t m, size_t n, float** A){

    float** AT = zeros(n, m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            AT[i][j] = A[j][i];
        }
    }

}


void permuteRows(int i, int j, float** A){

    float* temp = A[i];
    A[i] = A[j];
    A[j] = temp;

}


void permuteColumns(int i, int j, size_t m, size_t n, float** A){

    for (int k = 0; k < m; ++k) {
        float temp = A[k][i];
        A[k][i] = A[k][j];
        A[k][j] = temp;
    }

}


Pair QR(size_t m, size_t n, float** A){

    float** R = zeros(m, n);
    memcpy(R, A, m*n*sizeof(float)); // R=A

}








