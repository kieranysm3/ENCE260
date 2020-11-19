#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int* pairSumSearch(int* data, int numEls, int pairSum)
{
    for (int i = 1; (i < numEls); i++) {
        int *current = data;
        int* next = data + 1;
        if ((*current + *next) == pairSum) {
            return current;
        }
        data++;
        }

    return NULL;
}



int main(void)
{
int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int* p = pairSumSearch(data, 10, 19);
if (p != NULL) {
    printf("Found at position %zd\n", p - data);
}
else {
    puts("Not found");
}
}
