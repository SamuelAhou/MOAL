
#ifndef LAMO_TOOLS_H
#define LAMO_TOOLS_H

/**
 * matrixStruct (alias Matrix) contains a 2D array, its number of rows and columns
 */
/*
typedef struct matrixStruct
{
    size_t m;
    size_t n;
    float **array;
} Matrix;
/*

/**
 * ADDR is a buffer structure containing a matrix A and its number of rows, 'size'.
 */
typedef struct matrixAddressContainer
{
    float **A;
    int size;
} ADDR;

/**
 * Adds a new ADDR to buffer
 * @param m number of rows of A
 * @param A matrix A
 */
void addAddr(size_t m, float **A);

/**
 * Frees all of the matrices stored in buffer. To call at the end of main.
 */
void freeAll();

/**
 * Allocates memory and initializes 'buffer'.
 */
void initBuffer();

#endif //LAMO_TOOLS_H