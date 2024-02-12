#include <iostream>
#include <iomanip>

void ArrayInit(int* array, int size);
void ArrayPrint(int* array, int size);

int** MatrixCreate(int rows, int columns);
void MatrixInit(int** matrix, int rows, int columns);
void MatrixPrint(int** matrix, int rows, int columns);
void MatrixDelete(int** matrix, int rows);

int main()
{
    srand(time(nullptr));

    int size{ 10 };
    int* array = new int[size];

    int rows{ 5 };
    int columns{ 7 };
    
    int** matrix = MatrixCreate(rows, columns);
    MatrixInit(matrix, rows, columns);
    MatrixPrint(matrix, rows, columns);
    MatrixDelete(matrix, rows);

    matrix = new int*[rows];
    for (int i{}; i < rows; i++)
        matrix[i] = new int[2 + rand() % 9];
    
}

void ArrayInit(int* array, int size)
{
    for (int i{}; i < size; i++)
        *(array + i) = rand() % 100;
}

void ArrayPrint(int* array, int size)
{
    for (int i{}; i < size; i++)
        std::cout << *(array + i) << " ";
    std::cout << "\n";
}

int** MatrixCreate(int rows, int columns)
{
    int** matrix = new int* [rows];
    for (int i{}; i < rows; i++)
        matrix[i] = new int[columns] {};

    return matrix;
}

void MatrixInit(int** matrix, int rows, int columns)
{
    for (int i{}; i < rows; i++)
        for (int j{}; j < columns; j++)
            matrix[i][j] = rand() % 100;
}

void MatrixPrint(int** matrix, int rows, int columns)
{
    for (int i{}; i < rows; i++)
    {
        for (int j{}; j < columns; j++)
            std::cout << std::setw(3) << matrix[i][j];
        std::cout << "\n";
    }
}

void MatrixDelete(int** matrix, int rows)
{
    for (int i{}; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}
