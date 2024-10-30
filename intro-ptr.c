#include <stdio.h>

// Function to multiply two integers
int mult(int a, int b) {
    return a * b;
}

// Function to swap two integers using pointers
void swap(int *ptr2a, int *ptr2b) {
    int temp = *ptr2a;  // Use a temporary variable to hold the value
    *ptr2a = *ptr2b;    // Swap the values
    *ptr2b = temp;
    printf("3. USING POINTERS swap function prints: a= %d, b=%d \n", *ptr2a, *ptr2b);   
}

int main() {
    int cat1, cat2;
    
    // Prompt user for input
    printf("1. Enter two integers: \n");
    scanf("%d %d", &cat1, &cat2); // Input two integers
    
    printf("2. Values of the integers before swap: %d and %d \n", cat1, cat2);
    
    // Swap values
    swap(&cat1, &cat2);
    
    printf("4. Values of the integers after swap: %d and %d \n", cat1, cat2);
    
    // Calculate and print the final profuct
    int product = mult(cat1, cat2);
    printf("5. The product of the two integers is: %d \n", product);

    return 0;
}
