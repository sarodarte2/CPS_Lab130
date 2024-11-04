#include <stdio.h>

#define SIZE 10

// Function to find the maximum value in an array using pointers
int findMax(int *arr, int size) {
    int max = *arr;  // Initialize max to the first element of the array
    for (int i = 1; i < size; ++i) {
        if (*(arr + i) > max) {
            max = *(arr + i);  // Update max if the current element is greater
        }
    }
    return max;
}

int main() {
    int dog[SIZE];  // Declare an array to store 10 integers
    int input;

    // Prompt the user to enter 10 integers
    printf("Enter 10 integers:\n");
    for (int i = 0; i < SIZE; ++i) {
	while (1) {
        	printf("dog[%d]: ", i);  // Print index for user clarity
        	//  Ensure input is a valid integer
            	if (scanf("%d", &input) != 1) {
                	// Invalid input
                	printf("Invalid input. Please enter a valid integer:  ");
                	while (getchar() != '\n') {}  // Clear the input buffer
            	} else {
                	dog[i] = input;  // Store valid input in the array
                	break;           // Exit the loop on valid input
           	}
         }
    }

    // Pointer to the first element of the array
    int *ptr2dog = dog;

    // Call the findMax function to get the maximum value
    int max = findMax(ptr2dog, SIZE);

    // Print the result
    printf("\nThe maximum value from the value given is: %d\n", max);

    return 0;
}
