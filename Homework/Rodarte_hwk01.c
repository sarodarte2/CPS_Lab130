#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For sqrt function

#define MAX_SIZE 100 // Maximum possible number of elements

int main()
{
    int number[MAX_SIZE]; // Array to store the numbers
    int i = 0;            // Index for reading numbers
    int total_numbers = 0; // Total numbers read from the file

    // Open the file "data.txt" for reading
    FILE* in_file = fopen("data.txt", "r");
    if (!in_file) // Check if the file was successfully opened
    {
        printf("Oops, file can't be read\n");
        exit(-1); // Exit the program with an error code
    }

    // Read numbers from the file and store them into the array
    while (fscanf(in_file, "%d", &number[i]) == 1)
    {
        printf("Score read: %d\n", number[i]);
        i++;
        if (i >= MAX_SIZE) // Check for array overflow
        {
            printf("Exceeded maximum size of the array\n");
            break;
        }
    }
    total_numbers = i; // Total numbers read
    fclose(in_file);   // Close the file

    // Initialize frequency array to zero (for numbers 0 to 100)
    int freq[101] = {0};

    // Variables for calculations
    double sum = 0.0;       // Sum of all numbers
    double mean = 0.0;      // Mean (average)
    double variance = 0.0;  // Variance
    double stddev = 0.0;    // Standard deviation
    double median = 0.0;    // Median

    // Count the frequency of each number and calculate the sum
    for (i = 0; i < total_numbers; i++)
    {
        int num = number[i];
        if (num >= 0 && num <= 100) // Check if number is within valid range
        {
            freq[num]++; // Increment the frequency of the number
            sum += num;  // Add the number to the sum
        }
        else
        {
            printf("Invalid number %d found in data\n", num);
        }
    }

    // Calculate the mean (average)
    mean = sum / total_numbers;

    // Calculate the variance
    for (i = 0; i < total_numbers; i++)
    {
        variance += (number[i] - mean) * (number[i] - mean);
    }
    variance = variance / total_numbers;

    // Calculate the standard deviation
    stddev = sqrt(variance);

    // Find the maximum frequency among all numbers
    int max_freq = 0;
    for (i = 0; i <= 100; i++)
    {
        if (freq[i] > max_freq)
        {
            max_freq = freq[i];
        }
    }

    // Find all numbers that have the maximum frequency (modes)
    printf("Mode(s): ");
    int mode_found = 0; // Flag to check if at least one mode is found
    for (i = 0; i <= 100; i++)
    {
        if (freq[i] == max_freq && max_freq > 1) // Numbers occurring more than once
        {
            printf("%d ", i);
            mode_found = 1;
        }
    }
    if (!mode_found) // If no number occurs more than once
    {
        printf("No mode (all numbers occur only once)");
    }
    printf("\n");

    // Sort the scores for median calculation
    // Using bubble sort to sort the array which should be more efficient
    for (i = 0; i < total_numbers - 1; i++)
    {
        int j;
        for (j = 0; j < total_numbers - 1 - i; j++)
        {
            if (number[j] > number[j + 1])
            {
                // Swap number[j] and number[j + 1]
                int temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
            }
        }
    }

    // Median Calculation
    if (total_numbers % 2 == 0)
    {
        // If even number of scores, print the two middle values
        int mid1_index = total_numbers / 2 - 1;
        int mid2_index = total_numbers / 2;
        int mid1 = number[mid1_index];
        int mid2 = number[mid2_index];
        printf("Median values: %d and %d\n", mid1, mid2);
    }
    else
    {
        // If odd, take the middle value
        int mid_index = total_numbers / 2;
        int mid = number[mid_index];
        printf("Median value: %d\n", mid);
    }

    // Output the results
    printf("Mean: %.2lf\n", mean);
    printf("Standard Deviation: %.2lf\n", stddev);
    printf("The maximum frequency is %d\n", max_freq);

    return 0;
}
