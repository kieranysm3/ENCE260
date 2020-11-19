#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CRITICAL_HIGH 9.81
#define CRITICAL_LOW 5.0

void smoothData(int n, double data[])
{
    double current = data[0];
    double previous = 0;
    for (int counter = 0; counter < n; counter++) {
        current = data[counter];
        if (counter == 0) {
            previous = current;
            data[counter] = (((3 * current) + data[counter + 1]) / 4);
        } else if (counter == (n - 1)) {
            //last number
            data[counter] = ((previous + (3 * data[n - 1])) / 4);
            previous = current;
        } else {
            //normal case
            data[counter] = ((previous + (2 * data[counter]) + data[counter + 1]) / 4);
            previous = current;
        }
    }
}

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
    //have switch = true if acceleration exceeded --> print message --> do nothing till drop below critical low
    //then enable printing message again
    //have 2 checks if critical low hit and is critical high
    //prevent message spamming
    //run smoothing in for loop for every 3 values given
    //use readdoubles to check for eof?
double data[100000];
    int ValidInput = 0;

    ValidInput = readDoubles(100000, data);
    smoothData(ValidInput, data);
    //int High_hit = 0;
    int Low_hit = 1;
    double MaxValue = 0;
    double MaxTime = 0;
    for (int i = 0; i < ValidInput; i++)

    {
        double smoothed_value;
        smoothed_value = data[i];
        if (MaxValue < data[i]) {
            MaxValue = data[i];
            MaxTime = i;
            }
        //case1 hit critical high
        if ((smoothed_value >= CRITICAL_HIGH) && (Low_hit == 1)) {
            double j = i;

            printf("Acceleration of 9.81 m/sec^2 exceeded at t = %.2lf secs.\n", j/100.0);
            //change Low_hit to false
            Low_hit = 0;
            //High_hit = 1;
        } else if ((smoothed_value >= CRITICAL_HIGH) && (Low_hit == 0)) {
            //i have already exceeded but havent hit low so just continue
        } else if((smoothed_value <= CRITICAL_LOW) && (Low_hit == 0)) {
            //i hit low so reset switch
            Low_hit = 1;
            //High_hit = 0;
    }
    //int High_hit = 0;
    //int Low_hit = 1;)

}printf("\nMaximum acceleration: %0.2lf m/sec^2 at t = %0.2lf secs.", MaxValue, MaxTime/100.0);
}














