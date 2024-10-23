#include <stdio.h>
#include <math.h>

/*
Solver for x^6 - x - 1 = 0
Option 1: Bisection
Option 2: Newton
Option 3: Secant
*/

// Function
double f(double x) {
    return pow(x, 6) - x - 1;
}

// Derivative for plugin
double f_prime(double x) {
    return 6 * pow(x, 5) - 1; // Derivative of f
}

// Bisection Method
// We are interested on the sign mainly
double bisection(double a, double b, double tol, int max_itter) {
    double c;
    for (int i = 0; i < max_itter; i++) {
        c = (a + b) / 2; // Compute midpoint
        if (f(c) == 0.0) {
            return c; // Root
        }
        if (f(c) * f(a) < 0) {
            b = c; // Root is in [a, c]
        } else {
            a = c; // Root is in [c, b]
        }
        if (fabs(b - a) < tol) {
            return c; // Convergence
        }
    }
    return c; // Last midpoint approximation
}

// Newton's Method
double newton(double x0, double tol, int max_itter) {
    double x1;
    for (int i = 0; i < max_itter; i++) {
        x1 = x0 - f(x0) / f_prime(x0);
        if (fabs(x1 - x0) < tol) {
            // Convergence
            return x1; 
        }
        x0 = x1;
    }
    return x1; // Last approximation
}

// Secant Method
double secant(double x0, double x1, double tol, int max_itter) {
    double x2;
    for (int i = 0; i < max_itter; i++) {
        if (f(x1) - f(x0) == 0) {
            printf("Error: Division by zero\n");
            return NAN;
        }
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        if (fabs(x2 - x1) < tol) {
            return x2; // Convergence
        }
        x0 = x1;
        x1 = x2;
    }
    return x2; // Last approximation
}

int main() {
    double tol = 0.001;
    int max_itter = 50;
    int option;

    printf("Select method:\n");
    printf("1: Bisection\n");
    printf("2: Newton\n");
    prin1tf("3: Secant\n");
    scanf("%d", &option);

    if (option == 1) { // Bisection method
        double a = 0.0, b = 2.0; // Initial bounds
        printf("Bisection Solver\n");
        double root = bisection(a, b, tol, max_itter);
        printf("Root found: %.5lf\n", root);
    } 
    else if (option == 2) { // Newton's method
        double x0 = 1.0; // Initial guess
        printf("Newton's Solver\n");
        double root = newton(x0, tol, max_itter);
        printf("Root found: %.5lf\n", root);
    } 
    else if (option == 3) { // Secant method
        double x0 = 1.0; // Initial guess 1
        double x1 = 1.5; // Initial guess 2
        printf("Secant Solver\n");
        double root = secant(x0, x1, tol, max_itter);
        printf("Root found: %.5lf\n", root);
    } 
    else {
        printf("Invalid option.\n");
    }

    return 0;
}
