/*
#include<stdio.h>
//This program calculates the average of the scores of 5 students.
int main(){
	//int n = 5;
	//int max_student_size = 1000;
	int x[5];//array of variable length. 
	//x[1]= x[2]= wrong because 
	// indexing begins at 0. x[0] and x[1].
	double avg=-5.0;
	x[0]= 10;
	x[1]= 7;
	x[2]= 5;
	x[3]= 9;
	x[4]= 10;
	double sum = 0.0;//sum 41
	for (int i = 0 ;i < 5; ++i)
		{
		sum +=x[i];
		printf("for i = %d, sum = %lf \n ", i, sum );
			//more for checking if the right sum is being 
			//computed.
		} // for-loop
	avg = sum/5;
	printf("the average score is: %lf \n", avg);
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SCORES 100 // You can adjust this!
/*
a. This C code initializes an array x with five integer scores.
 It calculates the sum of these scores and then computes the average (mean)
 by dividing the total sum by the number of scores (5).

*/

//02avg.c code logic was used to build the following code. 
void calculateStatistics(double scores[], int size) {
    double sum = 0.0, mean, variance = 0.0, stddev;
    
    // Frequency assuming the max score is 100 cause its a grade. 
    int frequency[101] = {0};  // Assuming scores are between 0 and 100
    int maxCount = 0;

    // Calculate sum and frequency for mode / each score
    for (int i = 0; i < size; i++) {
        sum += scores[i];
        frequency[(int)scores[i]]++;  // Increment the frequency for each score
        if (frequency[(int)scores[i]] > maxCount) {
            maxCount = frequency[(int)scores[i]];  // Update max frequency
        }
    }

    // Calculate mean
    mean = sum / size;

    // **Mode Calculation**: Find all modes with max frequency
    printf("Modes: ");
    int foundMode = 0;
    for (int i = 0; i < 101; i++) {
        if (frequency[i] == maxCount && maxCount > 1) {  // More than one occurrence
            printf("%d ", i);
            foundMode = 1;
        }
    }
    if (!foundMode) {
        printf("No mode (all scores are unique)");  // If all scores are unique
    }
    printf("\n");

    // Calculate variance
    for (int i = 0; i < size; i++) {
        variance += (scores[i] - mean) * (scores[i] - mean);
    }
    variance /= size;

    // Calculate standard deviation
    stddev = sqrt(variance);

    // **Sort the scores for median calculation**:
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (scores[j] > scores[j + 1]) {
                double temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }

    // **Median Calculation**:
    double median;
    if (size % 2 == 0) {
        // If even number of scores, print two middle values
        median = (scores[size / 2 - 1] + scores[size / 2]) / 2.0;
        printf("Median: %lf and %lf\n", scores[size / 2 - 1], scores[size / 2]);
    } else {
        // If odd, print the middle value
        median = scores[size / 2];
        printf("Median: %lf\n", median);
    }

    // Output other results
    printf("Mean: %lf\n", mean);
    printf("Standard Deviation: %lf\n", stddev);
}

// Code from 04use-read.c (file-reader.c) provided in-class.
int main() {
    double scores[MAX_SCORES];
    int count = 0;

    // Open the file for reading
    FILE* in_file = fopen("scores-data.txt", "r"); //only open a pre-existing file in read mode. 
    if (!in_file) { // equivalent to saying if ( in_file == NULL ) 
        printf("Oops, file can't be read\n");
        exit(-1);
    }

    // Read scores from the file
    // attempt to read the next line and store 
    // the value in the "number" variable 
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

/*
Answers for the file read provided:
Mean: 39.750000
Median: 37.000000
Mode: 0
Standard Deviation: 35.002678
*/ 

