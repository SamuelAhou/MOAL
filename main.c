#include <stdio.h>        
#include "headers/UF.h"        
#include "headers/LAF.h"        
#include "headers/Tools.h"


int main(int argc, char* argv[]) {
    initBuffer();

    float array[9] = {1,2,3,4,5,6,7,8,9};
    Matrix matrix = {3, 3, matrixFromArray(3, 3, array)};
    displayMatrix(matrix.m,matrix.n,matrix.array);

    freeAll();
    return 0;
}
