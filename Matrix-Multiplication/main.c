/*
  Eugenio Leal A01022983
  Matrix Multiplication:
    Reads 2 Matrices from 2 separate files and multiplies them.
  Requirements: C99 compatible compiler for variable sized arrays/matrix; for example: int matrix[m][n];
  Compiler: gcc version 5.4.0
*/

#include <stdio.h>
#include <stdlib.h> // atoi, atof

// Function Declarations
void print_matrix(int m, int n, float matrix[m][n]);
void multiply_matrix(int m, int n, int p, float matrixA[m][n], float matrixB[n][p], float result[m][p]);

int main(int argc, char const *argv[]) {
  // file i/o
  FILE *fp;
  char buff[255];
  // rows and columns: matrixA[m][n] and matrixB[n][p]
  int m, n, p;

  //-----------------------------------//
  //--- Matrix A: Reading from file ---//
  //-----------------------------------//
  fp = fopen("Matrix_A.txt", "r");

  // Get the values for number of rows and columns
  fscanf(fp, "%s", buff);
  m = atoi(buff);
  fscanf(fp, "%s", buff);
  n = atoi(buff);
  // Declare matrix
  float matrixA[m][n];
  // Filling Matrix A
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) {
      fscanf(fp, "%s", buff);
      matrixA[i][j] = atof(buff);
    }
  }
  // Print Matrix A
  printf("Matrix A: \n");
  print_matrix(m, n, matrixA);

  //-----------------------------------//
  //--- Matrix B: Reading from file ---//
  //-----------------------------------//
  fp = fopen("Matrix_B.txt", "r");

  // Get the values for number of rows and columns
  fscanf(fp, "%s", buff);
  // Check if the two matrices can be multiplied
  int check;
  check = atoi(buff);
  if( check != n ) {
    fprintf(stderr, "The #columns of the first matrix must equal to the #rows of the second matrix!");
    exit(EXIT_FAILURE);
  }
  fscanf(fp, "%s", buff);
  p = atoi(buff);
  // Declare Matrix B
  float matrixB[n][p];
  // Fill Matrix
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < p; j++) {
      fscanf(fp, "%s", buff);
      matrixB[i][j] = atof(buff);
    }
  }
  // Print Matrix B
  printf("Matrix B:\n");
  print_matrix(n, p, matrixB);

  //-------------------------------------------------------//
  //--- Matrix Multiplication using Iterative Algorithm ---//
  //-------------------------------------------------------//
  float result[m][p];
  multiply_matrix(m, n, p, matrixA, matrixB, result);
  // Print Result
  printf("Result: \n");
  print_matrix(m, p, result);

  fclose(fp);
  return 0;
}

//-------------------------------------------------------//
//--- Matrix Multiplication using Iterative Algorithm ---//
//-------------------------------------------------------//
void multiply_matrix(int m, int n, int p, float matrixA[m][n], float matrixB[n][p], float result[m][p]) {
  float sum;
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < p; j++) {
      sum = 0;
      for (int k = 0; k < n; k++) {
        sum = sum + *(*(matrixA + i) + k) * *(*(matrixB + k) + j);
      }
      *(*(result + i) + j) = sum;
    }
  }
}

void print_matrix(int m, int n, float matrix[m][n]) {
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) {
      printf("%.1f ", matrix[i][j]);
    }
    printf("\n");
  }
}
