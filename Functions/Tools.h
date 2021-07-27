//
// Created by Samuel on 20/07/2021.
//

#ifndef LAMO_TOOLS_H
#define LAMO_TOOLS_H

#include "stdlib.h"
#include "assert.h"
#include "UF.h"

#define INIT_SIZE 32


/**
 * ADDR is a buffer structure containing a matrix A and its number of rows, 'size'.
 */
typedef struct matrixAddressContainer {
    float** A;
    int size;
} ADDR;


/**
 * 'buffer' contains all of the matrices to free at the end of the program. Its size, 'bufferSize',
 * is initially set to 'INIT_SIZE'.
 * 'current' is the current index at which the next 'ADDR' will be added.
 */
ADDR* buffer = NULL;
int bufferSize = INIT_SIZE;
int current = 0;


/**
 * Adds a new ADDR to buffer
 * @param m number of rows of A
 * @param A matrix A
 */
void addAddr(size_t m, float** A){

    if(current == bufferSize){
        bufferSize *= 2;
        buffer = (ADDR*) realloc(buffer, bufferSize*sizeof(ADDR));
        assert(buffer != NULL);
    }
    ADDR x = {.A = A, .size = m};
    buffer[current] = x;
    current++;

}


/**
 * Frees all of the matrices stored in buffer. To call at the end of main.
 */
void freeAll(){

    for (int i = 0; i < current; ++i) {
        freeMatrix(buffer[i].size, buffer[i].A);
    }

    free(buffer);

}


/**
 * Allocates memory and initializes 'buffer'.
 */
void initBuffer(){
    buffer = (ADDR*) calloc(bufferSize, sizeof(ADDR));
    assert(buffer!=NULL);
}


typedef struct matrixStruct {
    size_t m;
    size_t n;
    float** array;
} Matrix;

#endif //LAMO_TOOLS_H
