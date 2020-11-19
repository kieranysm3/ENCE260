#include <stdio.h>

#include <stdlib.h>

#define SCALE_FACTOR 1.609344

int main(void)
{
    float miles = 0;
    float kilometres = 0;
    printf("How many miles? ");

    scanf("%f", &miles);
    kilometres = (miles * SCALE_FACTOR);
    printf("That's %.2f km.", kilometres);
    //printf("Celsius equivalent: %.f", celsius);
    return EXIT_SUCCESS;
}
