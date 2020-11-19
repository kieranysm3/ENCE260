#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int countMatches(int n, int data[], int searchValue)
{
    int counter = 0;
    for (int position = 0; (position < n); position++) {
        printf("%d %d %d\n", data[position], searchValue, counter);
        if (data[position] == searchValue) {
            counter += 1;
        }
    }
    return counter;
}

int main(void) {
    int nums[] = {1, 2, 3, 4, 1, 1, 5};
    int counter = countMatches(7, nums, 1);
    printf("%d", counter);
}


