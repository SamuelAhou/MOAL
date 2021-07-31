//
// Created by Samuel on 20/07/2021.
//

#include <stdlib.h>
#include <assert.h>
#include "../headers/Tools.h"
#include "../headers/UF.h"

#define INIT_SIZE 32

/**
 * 'buffer' contains all of the matrices to free at the end of the program. Its size, 'bufferSize',
 * is initially set to 'INIT_SIZE'.
 * 'current' is the current index at which the next 'ADDR' will be added.
 */
ADDR *buffer = NULL;
int bufferSize = INIT_SIZE;
int current = 0;

void addAddr(size_t m, float **A)
{

    if (current == bufferSize)
    {
        bufferSize *= 2;
        buffer = (ADDR *)realloc(buffer, bufferSize * sizeof(ADDR));
        assert(buffer != NULL);
    }
    ADDR x = {.A = A, .size = m};
    buffer[current] = x;
    current++;
}

void freeAll()
{

    for (int i = 0; i < current; ++i)
    {
        freeMatrix(buffer[i].size, buffer[i].A);
    }

    free(buffer);
}

void initBuffer()
{
    buffer = (ADDR *)calloc(bufferSize, sizeof(ADDR));
    assert(buffer != NULL);
}
