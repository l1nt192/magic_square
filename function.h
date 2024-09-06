#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996);
int** Matrix_Create_F(const char* file_name_, size_t* size_);
bool is_Magic_Square(int** matrix, int size);
