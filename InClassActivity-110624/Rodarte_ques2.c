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
#include <math.h>

// This program calculates the average, mode, and st.d of the scores of 5 students.

int main() {
    // Original array of scores for the 5 students.
    int x[5];
    double avg = -5.0; // Initialize the average value
    x[0] = 10;
    x[1] = 7;
    x[2] = 5;
    x[3] = 9;
    x[4] = 10;

    // Initialize variables for storing our final sols.
    double sum = 0.0; // Sum of the scores
    double variance = 0.0, standard_deviation;
    int mode = x[0], mode_count = 1;

    // Calculate the sum of the scores and print intermediate sums as done before
    for (int i = 0; i < 5; ++i) {
        sum += x[i];
        printf("for i = %d, sum = %lf\n", i, sum);  // Debugger output
    }

    // Calculate the average (mean)
    avg = sum / 5;
    printf("The average score is: %lf\n", avg);

    // Calculate the variance and standard deviation
    for (int i = 0; i < 5; ++i) {
        variance += pow(x[i] - avg, 2);  // Sum of squared differences from the mean
    }
    variance /= 5;  // Calculate variance
    standard_deviation = sqrt(variance);  // Standard deviation is the square root of variance. Need mathpackage. Remeber -lm when running command. 

    // Find the mode (assuming there is exactly one mode)
    for (int i = 0; i < 5; ++i) {
        int count = 0;
        for (int j = 0; j < 5; ++j) {
            if (x[i] == x[j]) {
                count++;
            }
        }
        // If this score occurs more times, it becomes the new mode
        if (count > mode_count) {
            mode_count = count;
            mode = x[i];
        }
    }

    // Output the results
    printf("The mode of the scores is: %d\n", mode);
    printf("The standard deviation is: %.2lf\n", standard_deviation);

    return 0;
}
