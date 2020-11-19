#include <stdio.h>
#include <stdlib.h>

int main(void)
{
 char* s = "Ummm: ";
//while value of s --> put character(value of s increment)
//s[0] a pointer to s
//while *s means loop until terminator '\0' is found
while (*s) putchar(*s);
printf("s[0] = %c", s[0]);
}
