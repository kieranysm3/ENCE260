

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>


char* mystrrchr(char* s, int c)
{
    char* lastchar = 0;
    int counter = 0;
    for (; *s != 0; s++) {
        if (*s == c) {
            lastchar = s;
        }
        counter += 1;
    }
    return lastchar;



}



int main(void)
{
    char* s = "ENCE26E0";
    char* foundAt = mystrrchr(s, 'E');
    if (foundAt == NULL) {
        puts("Not found");
    }
    else {
        printf("%zu\n", foundAt - s);
    }
}
