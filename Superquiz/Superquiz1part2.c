
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CRITICAL_HIGH = 9.81
#define CRITICAL_LOW = 5.0


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

int main(void)
{
    double data[] = {1.0, 2.0, 4.0, 4.0};
    smoothData(4, data);
    printf("Smoothed data: %.3lf", data[0]);
    for (int i = 1; i < 4; i++) {
        printf(", %.3lf", data[i]);
}
puts("");
}
