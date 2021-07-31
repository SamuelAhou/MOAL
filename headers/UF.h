//
// Created by Samuel on 20/07/2021.
//

#ifndef LAMO_UF_H
#define LAMO_UF_H

/**
 * Produce an m*n zero matrix
 * @param m number of rows
 * @param n number of columns
 * @return pointer to the zero matrix produced
 */
float **zeros(size_t m, size_t n);

/**
 * Produces an m*n matrix full of ones
 * @param m number of rows
 * @param n number of columns
 * @return pointer to the matrix full of ones produced
 */
float **ones(size_t m, size_t n);

/**
 * Produces an n*n identity matrix
 * @param n dimension of the matrix
 * @return pointer to the identity matrix produced
 */
float **eye(size_t n);

/**
 * Creates a matrix from an array
 * @param m number of rows
 * @param n number of columns
 * @param array array from which to create the matrix
 * @return float** matrix with input M_ij = array[i*n + j]
 */
float **matrixFromArray(size_t m, size_t n, float array[m * n]);

/**
 * Creates a new matrix from inputs
 * @param m number of rows
 * @param n number of column
 * @return pointer to the new matrix created
 */
float **matrixFromInputs(size_t m, size_t n);

/**
 * Completely frees a matrix previously allocated by malloc or calloc
 * @param m number of rows of the matrix
 * @param A matrix to free
 */
void freeMatrix(size_t m, float **A);

/**
 * Diplays the matrix A on stdout
 * @param m size_t, number of rows of A
 * @param n size_t, number of columns of A
 * @param A Matrix A
 */
void displayMatrix(size_t m, size_t n, float **A);

/**
 * Gets sub matrix from matrix, given first and last entry the sub matrix
 * @param m row index of first entry of the sub matrix
 * @param n column index of first entry of the sub matrix
 * @param k row index of last entry of the sub matrix
 * @param l column index of last entry of the sub matrix
 * @param A matrix from which to gets sub matrix
 * @return pointer to sub matrix of size (k-m+1)*(l-n+1) with first entry (m,n) and last entry (k,l) in A
 */
float **getSubMatrix(int m, int n, int k, int l, float **A);

/**
 * Sets a sub matrix of A to a given matrix B, given first and last entry the sub matrix to set
 * @param m row index of first entry of the sub matrix
 * @param n column index of first entry of the sub matrix
 * @param k row index of last entry of the sub matrix
 * @param l column index of last entry of the sub matrix
 * @param A matrix to set
 * @param B matrix of size (k-m+1)*(l-n+1) to set in A from entry (m,n) to entry (k,l) in A
 */
void setSubMatrix(int m, int n, int k, int l, float **A, float **B);

#endif
