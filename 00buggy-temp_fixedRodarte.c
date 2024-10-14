#include <stdio.h>
int main() {
    float fahrenheit;
    // Declare celsius
    float celsius; 
    
    // Added semicolon
    printf("Enter temperature in Fahrenheit: "); 
    
    // Use & to get address of F
    scanf("%f", &fahrenheit); 
    
    //This is okay
    celsius = (fahrenheit - 32) * 5 / 9;
    
    // Remove the & before celsius since its stored in a variable
    printf("Temperature in Celsius: %f\n", celsius); 

    return 0;
}



