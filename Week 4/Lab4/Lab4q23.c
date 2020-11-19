

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

int tokenCopy(char* dest, const char* src, int destSize)
{
    int counter = 0;
    //pointer pointing to start of string src to destSize
    while ((counter < destSize -1) && (*src != 32) && (*src != '\0')) {
        //printf("%d, %p\n", *src, dest);
        //printf("%d hihiih\n", *src);
        *dest = *src;
        counter += 1;
        dest++;
        src++;
    }
    *dest = '\0';
    //printf("%d, %p\n", *src, dest);
    return counter;
}



int main(void)
{

char buff[5];
int n = tokenCopy(buff, "This is a string", 5);
printf("%d '%s'\n", n, buff);
}
