#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findTwoLargest(const int data[], int n, int* largest, int* secondLargest)

{
    if (data[0] < data[1]) {
        *largest = data[1];
        *secondLargest = data[0];
    } else {
        *largest = data[0];
        *secondLargest = data[1];
    }
    for (int i = 2; i < n; i++) {
        //if data greater than largest, largest = data put old value of largest into second largest
        if (data[i] >= *largest) {
            *secondLargest = *largest;
            *largest = data[i];
        } else if (data[i] > *secondLargest) {
            *secondLargest = data[i];
        }
    }
}



int main(void)
{
int data[] = {5, 4};
int result1 = 0, result2 = 0;
findTwoLargest(data, 2, &result1, &result2);
printf("%d %d\n", result1, result2);
printf("%d %d\n", data[0], data[1]);
}
