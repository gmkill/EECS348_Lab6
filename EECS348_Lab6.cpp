#include <iostream>
#include <fstream>
#include <iomanip> //used for formatting the output
using namespace std;

// sets the maximum matrix size to 100
const int MAX_MATRIX_SIZE = 100;

//this function reads matrix data from a file and stores it in a 2D array
void ReadMatrixFromFile(const string& filename, int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int& size) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open the input file." << endl;
        exit(1);
    }

    file >> size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> matrix[i][j];
        }
    }

    file.close();
}

//this function prints out a matrix
void Print_Matrix(const int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(6) << matrix[i][j]; //adjusts the width as needed
        }
        cout << endl;
    }
}

//function which adds two matrices and stores the result in a third matrix
void AddMatrices(const int matrix1[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], const int matrix2[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int result[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j]; //adds the two
        }
    }
}

//this function multiplies two matrices and stores the result in a third matrix
void MultiplyMatrices(const int matrix1[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], const int matrix2[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int result[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

//function used to subtract the second matrix from the first matrix
void SubtractMatrices(const int matrix1[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], const int matrix2[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int result[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j]; //subtraction happens here
        }
    }
}

int main() { //main function that uses all the above functions
    int matrix1[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    int matrix2[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    int result[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    int size;

    ReadMatrixFromFile("matrix_input.txt", matrix1, size);
    ReadMatrixFromFile("matrix_input.txt", matrix2, size);

    cout << "Matrix 1:" << endl;
    Print_Matrix(matrix1, size);

    cout << "Matrix 2:" << endl;
    Print_Matrix(matrix2, size);

    AddMatrices(matrix1, matrix2, result, size);
    cout << "Matrix 1 + Matrix 2:" << endl;
    Print_Matrix(result, size);

    MultiplyMatrices(matrix1, matrix2, result, size);
    cout << "Matrix 1 * Matrix 2:" << endl;
    Print_Matrix(result, size);

    SubtractMatrices(matrix1, matrix2, result, size);
    cout << "Matrix 1 - Matrix 2:" << endl;
    Print_Matrix(result, size);

    return 0;  //end of the program, returns 0
}
