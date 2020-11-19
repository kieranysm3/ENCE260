#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(void)
{
    int i = 0;
    int j = 1;
    int store;
    //remember exit condition can be bools to eliminate i = 0 edge case
    scanf("%d",  &i);
    for(j = 1; j <= i; j++) {
        store = (j * j);
        printf("%d\n", store);
    }
}
