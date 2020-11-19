
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


char* skipping(const char* s)
{
    //i allocate 1 more memory slot for string terminator
    //am i not allocating double the required memory here?
    char* data = malloc((strlen(s) + 1) * sizeof(int));
    int counter = 0;
    //add every 2nd char to a new string ( data )
    for (int i = 0; (i <= strlen(s)); i += 2) {
        data[counter] = s[i];
        counter++;
    }
    data[counter] = '\0';
    return data;
}

int main(void)
{
    char* s = skipping("0123456789");
    printf("%s\n", s);
    free(s);
}
