#include<iostream>
#include<math.h>

using namespace std;

int main() {
  int i, j, k, n;

  cout << "\nEnter the no. of equations: ";
  cin >> n;

  // Here size of the augmented matrix will be n*n+1 
  float matrix[n][n + 1];

  /* we will store the n unknown constants of n equations in array 'result' */
  float result[n];

  cout << "\nEnter the augmented matrix: ";
  for (i = 0; i < n; i++) {
    for (j = 0; j < n + 1; j++) {
      cin >> matrix[i][j];
    }
  }

  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (abs(matrix[i][i]) < abs(matrix[j][i])) {
        for (k = 0; k < n + 1; k++) {

          /* we will swap the matrix[i][k] and matrix[j][k] to get the lowest element on top */
          matrix[i][k] = matrix[i][k] + matrix[j][k];
          matrix[j][k] = matrix[i][k] - matrix[j][k];
          matrix[i][k] = matrix[i][k] - matrix[j][k];
        }
      }
    }
  }

  /* Using Gaussian elimination to form upper triangular matrix */
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      float f = matrix[j][i] / matrix[i][i];
      for (k = 0; k < n + 1; k++) {
        matrix[j][k] = matrix[j][k] - f * matrix[i][k];
      }
    }
  }

  /* Using backward substitution to find the unknown values */
  for (i = n - 1; i >= 0; i--) {
    result[i] = matrix[i][n];

    for (j = i + 1; j < n; j++) {
      if (i != j) {
        result[i] = result[i] - matrix[i][j] * result[j];
      }
    }
    result[i] = result[i] / matrix[i][i];
  }

  cout << "\nThe unknown values for the above equations are:\n";
  for (i = 0; i < n; i++) {
    cout << result[i] << "\n";
  }
  return 0;
}