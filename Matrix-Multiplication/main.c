/*
  Eugenio Leal A01022983
  Matrix Multiplication
*/

#include <stdio.h>
#include <stdlib.h> // atoi, atof

void print_matrix(int m, int n, float matrix[m][n]) {
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) {
      printf("%.1f ", matrix[i][j]);
    }
    printf("\n");
  }
}

void multiply_matrix(int m, int n, int p, float matrixA[m][n], float matrixB[n][p]) {
  float sum;
  float result[m][p];
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

  printf("Matrix A: \n");
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) {
      fscanf(fp, "%s", buff);
      matrixA[i][j] = atof(buff);
      printf("%.1f ", matrixA[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  // testing function
  print_matrix(m, n, matrixA);
  // testing without function
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) {
      printf("%.1f ", *(*(matrixA + i) + j));
    }
    printf("\n");
  }

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

  float matrixB[100][100];

  printf("Matrix B:\n");
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < p; j++) {
      fscanf(fp, "%s", buff);
      matrixB[i][j] = atof(buff);
      printf("%.1f ", matrixB[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  float result[m][p];
  // Start Matrix Multiplication
  // Iterative algorithm
  float sum;
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < p; j++) {
      sum = 0;
      for (int k = 0; k < n; k++) {
        // testing: printf("%f + %f * %f\n", sum, matrixA[i][k], matrixB[k][j] );
        sum = sum + matrixA[i][k] * matrixB[k][j];
      }
      result[i][j] = sum;
    }
  }
  printf("Result: \n");
  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 0; j < 4; j++) {
      printf("%.1f ", result[i][j]);
    }
    printf("\n");
  }

  fclose(fp);
  return 0;
}
