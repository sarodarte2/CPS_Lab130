#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cblas.h>

/*
Approximates the derivative of f(x) = sin(x) over [0, 2pi] using forward difference and central difference formulas.

*/

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("Usage: %s N\n", argv[0]);
        return -1;
    }

    int N = atoi(argv[1]);

    if (N <= 0) {
        printf("N must be positive integer.\n");
        return -1;
    }

    double a = 0.0;
    double b = 2.0 * M_PI;
    double h = (b - a) / N;

    // Allocate arrays
    double* x = (double*)malloc((N+1)*sizeof(double));
    double* u = (double*)malloc((N+1)*sizeof(double));
    double* exact_du = (double*)malloc((N+1)*sizeof(double));
    double* du_fd = (double*)malloc((N+1)*sizeof(double));
    double* du_cd = (double*)malloc((N+1)*sizeof(double));
    double* errors_fd = (double*)malloc((N+1)*sizeof(double));
    double* errors_cd = (double*)malloc((N+1)*sizeof(double));

    if (x == NULL || u == NULL || exact_du == NULL || du_fd == NULL || du_cd == NULL || errors_fd == NULL || errors_cd == NULL) {
        printf("Error allocating memory.\n");
        return -1;
    }

    // Initialize x[i], u[i], exact_du[i]
    for (int i = 0; i <= N; ++i) {
        x[i] = a + i * h;
        u[i] = sin(x[i]);
        exact_du[i] = cos(x[i]);
    }

    // Compute forward difference approximation
    for (int i = 0; i < N; ++i) {
        du_fd[i] = (u[i+1] - u[i]) / h;
    }
    // For the last point, use backward difference
    du_fd[N] = (u[N] - u[N-1]) / h;

    // Compute central difference approximation
    // For the first point, use forward difference
    du_cd[0] = (u[1] - u[0]) / h;
    for (int i = 1; i < N; ++i) {
        du_cd[i] = (u[i+1] - u[i-1]) / (2*h);
    }
    // For the last point, use backward difference
    du_cd[N] = (u[N] - u[N-1]) / h;

    // Compute errors
    for (int i = 0; i <= N; ++i) {
        errors_fd[i] = du_fd[i] - exact_du[i];
        errors_cd[i] = du_cd[i] - exact_du[i];
    }

    // Compute L2 norms of errors
    double error_L2_fd = cblas_ddot(N+1, errors_fd, 1, errors_fd, 1);
    error_L2_fd = sqrt(error_L2_fd * h);

    double error_L2_cd = cblas_ddot(N+1, errors_cd, 1, errors_cd, 1);
    error_L2_cd = sqrt(error_L2_cd * h);

    printf("Forward Difference L2 Error: %e\n", error_L2_fd);
    printf("Central Difference L2 Error: %e\n", error_L2_cd);


    // Free memory
    free(x);
    free(u);
    free(exact_du);
    free(du_fd);
    free(du_cd);
    free(errors_fd);
    free(errors_cd);

    return 0;
}

