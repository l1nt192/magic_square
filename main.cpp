#pragma once
#include "function.h"
int main()
{
    size_t size = 0;
    int** matrix = Matrix_Create_F("matrix.txt", &size);
    if (matrix == NULL)
        return -1;
    bool is_magic = is_Magic_Square(matrix, (int)size);
    printf("%d\n", is_Magic_Square(matrix, (int)size));
    for (size_t i = 0; i < size; ++i)
        free(matrix[i]);
    free(matrix);
    return 0;
}