
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define BUFFER_INCREMENT 1

void fillRamp(int* data, int n)
{
    for (int i = 0; i < n; i++)
    {
        data[i] = i + 1;
    }



}

int main(void)
{
    int* data = malloc(4 * sizeof(int));
    fillRamp(data, 4);
    for (int i = 0; i < 4; i++) {
        printf("data[%d] = %d\n", i, data[i]);
    }
    free(data);
}



/*
double* randomArray(int n)
{
    double* numbers = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {      // Fill with random numbers
        numbers[i] = (1.0 * rand()) / RAND_MAX;
        // Note numerator is converted to a double
        // to ensure floating point division is done.
    }
    return numbers;
}
*/
