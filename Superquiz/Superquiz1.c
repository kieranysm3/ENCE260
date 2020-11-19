
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CRITICAL_HIGH = 9.81
#define CRITICAL_LOW = 5.0

// write function readDoubles return value is number of double-precision floating point numbrs read


int readDoubles( int n, double data[]) //take in integer and array data in format double
{
    //a for loop with max n iterations, fist check if input is a double type only if it is a double, counter n
    // if n condition is broken or EOF terminate for loop
    //can EOF be stored as a value
    int counter = 0;
    for (counter = 0; (counter < n); counter++) {
        double readvalue = 0;
        int truth = 0;
        truth = scanf("%lf", &readvalue);
        printf("%d", truth);
        if ( truth != EOF ) {
            //the input is invalid as it is EOF
            //the other exit condition will be hit by the for loop
            data[counter] = readvalue;
        } else {
            return counter;
        }
    }
    return counter;

}


int main(void)
{
double data[5] = {0.0};
int numRead = 0;

numRead = readDoubles(4, data);
printf("Read %d values:\n", numRead);
for (int i = 0; i < numRead; i++) {
    printf("%0.3lf\n", data[i]);
}
}
