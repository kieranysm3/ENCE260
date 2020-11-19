#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* mystrchr(char* s, int c)
{
    while (*s != '\0') {
        if (*s == c) {
            return s;
        }
        s++;
    }
    return NULL;
}


int main(void)
{
    char* s = "ENCE260";
char* foundAt = mystrchr(s, '2');
if (foundAt == NULL) {
    puts("Not found");
}
else {
    printf("%zd\n", foundAt - s);
}
}
