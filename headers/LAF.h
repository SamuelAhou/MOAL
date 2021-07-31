//
// Created by Samuel on 10/07/2021.
//

#ifndef LAMO_LAF_H
#define LAMO_LAF_H

typedef struct factorizationPair
{

    float **F;
    float **G;

} Pair;

/**
 * Computes matrix addition of A and B
 * @param m number of rows
 * @param n number of columns
 * @param A first matrix
 * @param B second matrix
 * @return Pointer to result matrix i.e. A+B
 */
float **add(size_t m, size_t n, float **A, float **B);

/**
 * Computes matrix subtraction of A and B
 * @param m number of rows
 * @param n number of columns
 * @param A first matrix
 * @param B second matrix
 * @return Pointer to result matrix i.e. A-B
 */
float **sub(size_t m, size_t n, float **A, float **B);

/**
 * Scales matrix A by the scalar factor a
* @param m number of rows
 * @param n number of columns
 * @param A matrix to scale
 * @param a scalar factor
 * @return Pointer to the scaled matrix i.e. a*A
 */
float **scale(size_t m, size_t n, float **A, float a);

/**
 * Computes the p-norm of x
 * @param x Vector
 * @param size size of x
 * @param p precise the type of norm to compute
 * @return P-norm of x i.e. [ sum i=0 to size ( | x[i] |^p) ]^ 1/p
 */
float norm(float **x, size_t size, int p);

/**
 * Computes the dot product of two same size vectors x, y.
 * @param x first vector
 * @param y second vector
 * @param size size of x,y (sizes must match)
 * @return Dot product of x and y i.e. x^T*y
 */
float dot(float **x, float **y, int size);

/**
 * Computes the matrix product of A and B, A*B = C
 * @param m number of rows of A
 * @param n number of columns of A also number of rows of B (sizes must match)
 * @param p number of columns of B
 * @param A matrix A
 * @param B matrix B
 * @return Pointer to product matrix i.e. A*B
 */
float **matrixProduct(size_t m, size_t n, size_t p, float **A, float **B);

/**
 * Computes the transpose of A i.e. A^T
 * @param m number of rows of A
 * @param n number of columns of A
 * @param A the matrix to transpose
 * @return Pointer to the transposed matrix i.e. A^T
 */
float **transpose(size_t m, size_t n, float **A);

#endif
