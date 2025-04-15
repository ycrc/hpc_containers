#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments are provided
    if (argc != 2) {
        printf("Syntax: MC <number_of_points>\n");
        return 1;
    }

    // Convert the number of points to an integer
    int num_points = atoi(argv[1]);

    // Check if the number of points is positive
    if (num_points <= 0) {
        printf("Please enter a positive integer for the number of points.\n");
        return 1;
    }

    int inside_circle = 0;
    double x, y;

    // Initialize random number generator with the current time
    srand(time(NULL));

    // Generate random points and check if they fall inside the unit circle
    for (int i = 0; i < num_points; i++) {
        // Generate random x and y coordinates between -1 and 1
        x = (double)rand() / RAND_MAX * 2.0 - 1.0;
        y = (double)rand() / RAND_MAX * 2.0 - 1.0;

        // Check if the point is inside the circle (x^2 + y^2 < 1)
        if (x * x + y * y <= 1) {
            inside_circle++;
        }
    }

    // Calculate the approximation of pi
    double pi_approx = (double)inside_circle / num_points * 4.0;

    // Print the result
    printf("Approximation of Pi with %d points: %f\n", num_points, pi_approx);

    return 0;
}

