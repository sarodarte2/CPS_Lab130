#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cblas.h>

// Credit to Dr. Sharma's code and suggestions to change the code.
// Loop needs to go into the interior.
// Stop at N-1 in void diff. 

/*
  void diff(double* u, int N, double dx, double* d2u)

  Computes a finite difference approximation for d2u/dx^2

  Inputs: 
  u: pointer for input array
  N: length of the array
  dx: the space step size
  d2u: pointer to output array

  Outputs: 
  d2u: the second-order finite difference approximation
*/
void diff(double* u, int N, double dx, double* d2u) {
    for(int i = 1; i <= N - 2; ++i) { //Could be N-1?
        d2u[i] = (u[i + 1] - 2.0 * u[i] + u[i - 1]) / (dx * dx);
    }
}

/*
  void init(double* u, int N, double dx)

  Initializes the data array with the sin function

  Inputs: 
  u: pointer to array where values will be stored
  N: length of the array
  dx: the space step size

  Outputs: 
  u: data for a sin function
*/
void init(double* u, int N, double dx) {
    for (int i = 0; i <= N; ++i) {
        u[i] = sin(i * dx);
    }
}

/*
  int main(int argc, char* argv[])

  Function computes the second-order derivative of sin(x) and compares with exact values
  using L2 error norm.

  Inputs: argc should be 2
  argv[1] is the integer length of the data array

  Outputs: L2 error between the computed and exact derivatives
*/
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <N>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    if (N < 2) {
        printf("N must be greater than or equal to 2.\n");
        return 1;
    }

    double* u = (double*)malloc((N + 1) * sizeof(double));
    double* d2u = (double*)malloc((N + 1) * sizeof(double));
    double* errd2u = (double*)malloc((N - 1) * sizeof(double));

    double dx = M_PI / N;

    init(u, N, dx);
    diff(u, N, dx, d2u);

    for (int i = 1; i <= N - 2; ++i) {
        double exact = -sin(i * dx);
        errd2u[i - 1] = exact - d2u[i];
    }

    double error_L2 = cblas_ddot(N - 1, errd2u, 1, errd2u, 1);
    printf("L2 error = %f\n", sqrt(error_L2));

    free(u);
    free(d2u);
    free(errd2u);

    return 0;
}

