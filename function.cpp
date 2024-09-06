#include "function.h"

int** Matrix_Create_F(const char* file_name_, size_t* size_)
{
    FILE* file = fopen(file_name_, "r");
    if (!file)
        return NULL;
    if (fscanf(file, "%zu", size_) != 1) 
    {
        fclose(file);
        return NULL;
    }
    int** matrix = (int**)calloc(*size_, sizeof(int*));
    if (!matrix)
    {
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < *size_; ++i)
    {
        matrix[i] = (int*)calloc(*size_, sizeof(int));
        if (!matrix[i])
        {
            for (size_t j = 0; j < i; ++j)
                free(matrix[j]);
            free(matrix);
            fclose(file);
            return NULL;
        }
    }

    for (size_t i = 0; i < *size_; i++)
    {
        for (size_t j = 0; j < *size_; j++)
        {
            if (fscanf(file, "%d", &matrix[i][j]) != 1) {
                for (size_t k = 0; k <= i; ++k)
                    free(matrix[k]);
                free(matrix);
                fclose(file);
                return NULL;
            }
        }
    }

    fclose(file);
    return matrix;
}

bool is_Magic_Square(int** matrix, int size)
{
    int magic_sum = 0;
    int sum_rever = 0;
    int diag_sum = 0;

    for (int i = 0; i < size; i++)
        diag_sum += matrix[i][i];
    magic_sum = diag_sum;
    for (int i = 0; i < size; i++)
        sum_rever += matrix[i][size - 1 - i];

    if (sum_rever != magic_sum)
        return false;

    for (int i = 0; i < size; i++)
    {
        int sum_row = 0;
        for (int j = 0; j < size; j++)
            sum_row += matrix[i][j];
        if (sum_row != magic_sum)
            return false;
    }
    for (int i = 0; i < size; i++)
    {
        int sum_col = 0;
        for (int j = 0; j < size; j++)
            sum_col += matrix[j][i];
        if (sum_col != magic_sum)
            return false;
    }
    return true;
}
