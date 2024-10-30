#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SCORES 100 // You can adjust this!

/*
a. This C code initializes an array x with five integer scores.
 It calculates the sum of these scores and then computes the average (mean)
 by dividing the total sum by the number of scores (5).

*/

//02avg.c code logic used to build the following code. 
void calculateStatistics(double scores[], int size) {
    double sum = 0.0, mean, variance = 0.0, stddev;
    // Frequency assuming the max score is 100?
    int frequency[101] = {0};
    int mode = scores[0], maxCount = 0;

    // Calculate sum and frequency for mode
    for (int i = 0; i < size; i++) {
        sum += scores[i];
        frequency[(int)scores[i]]++;
        if (frequency[(int)scores[i]] > maxCount) {
            maxCount = frequency[(int)scores[i]];
            mode = (int)scores[i];
        }
    }

    // Calculate mean
    mean = sum / size;

    // Calculate variance
    for (int i = 0; i < size; i++) {
        variance += (scores[i] - mean) * (scores[i] - mean);
    }
    variance /= size;

    // Calculate standard deviation
    stddev = sqrt(variance);

    // Calculate median
    // Sort the scores for median calculation
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (scores[j] > scores[j + 1]) {
                double temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }

    double median;
    if (size % 2 == 0) {
        median = (scores[size / 2 - 1] + scores[size / 2]) / 2.0;
    } else {
        median = scores[size / 2];
    }

    // Output results
    printf("Mean: %lf\n", mean);
    printf("Median: %lf\n", median);
    printf("Mode: %d\n", mode);
    printf("Standard Deviation: %lf\n", stddev);
}

// Code from 04use-read.c provided in-class.
int main() {
    double scores[MAX_SCORES];
    int count = 0;

    // Open the file for reading
    FILE* in_file = fopen("scores-data.txt", "r");
    if (!in_file) {
        printf("Oops, file can't be read\n");
        exit(-1);
    }

    // Read scores from the file
    while (fscanf(in_file, "%lf", &scores[count]) == 1) {
        count++;
        if (count >= MAX_SCORES) {
            break; // Prevent overflow
        }
    }
    
    fclose(in_file); // Always close the file after use

    // Calculate and print statistics
    if (count > 0) {
        calculateStatistics(scores, count);
    } else {
        printf("No scores were read from the file.\n");
    }

    return 0;
}
