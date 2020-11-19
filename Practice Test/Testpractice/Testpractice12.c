#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* alphaShiftRight(char* s)
{
    int aii = 0;
    while ((s[aii] != '\0')) {
        if (isalpha(s[aii])) {
            if (s[aii] == 'Z') {
                s[aii] = 'A';
            }
            if (s[aii] == 'z') {
                s[aii] = 'a';
            } else {
                s[aii] += 1;
            }
        }
        aii++;
    }
    return s;
}




int main(void)
{
char s[] = "Hello World!";
printf("%s\n", alphaShiftRight(s));
}
