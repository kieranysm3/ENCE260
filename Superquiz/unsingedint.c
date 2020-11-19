#include <stdio.h>

#include <stdlib.h>
// shouldnt n = 60000 exceed the 8 bite requirement now and wrap around
// why does sizeof n give me 2 bytes when its a char call
int main(void)
{
    unsigned short n;
    n = -6;
    printf("Big number = %d\n", n * 60000);
    printf("n occupies %zu bytes of memory\n", sizeof n);
    }
