#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




char* rotateLeft(char* s)
{
    char lengthofstring = strlen(s);
    char firstletter = *s;
    for(int i=0; (i < lengthofstring); i++) {
        s[i] = s[i + 1];
    }
    s[lengthofstring - 1] = firstletter;
    return s;
}



 int main(void)
 {
    char s[] = "Hello World!";
    printf("%s\n", rotateLeft(s));



 }
