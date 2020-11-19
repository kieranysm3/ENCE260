#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void swap3(int* x, int* y, int* z)
{
    int a = *x; //biggest
    int b = *y; //middle
    int c = *z; //smallest
    if(a > b && a > c) {
        //a is biggest
        if(b > c) {
            //order is c, b, a
            *x = a;
            *y = b;
            *z = c;
        } else {
            //order is b c a
            *x = a;
            *y = c;
            *z = b;
        }
    } else if(b > a && b > c) {
        //b is biggest
        if(a > c) {
            //order is c a b
            *x = b;
            *y = a;
            *z = c;
        } else {
            //order is a c b
            *x = b;
            *y = c;
            *z = a;
        }
    } else if (c > a && c > b) {
        //c is the biggest
        if (a > b) {
            //order is b a c
            *x = c;
            *y = a;
            *z = b;
        } else {
            //order is a b c
            *x = c;
            *y = b;
            *z = a;
        }
    }
}

int main(void)
{
    int a = 10;
    int b = 0;
    int c = 7;
    swap3(&a, &b, &c);
    printf("%d <= %d <= %d\n", c, b, a);
}
