#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char* strchrn(char* s, int c, int n)
{
    //takes in char* pointer , letter to search for, c  and  which instance of c to return
    int occurrence = 0;
    if (n <= 0) {
        return NULL;
    }
    while (occurrence != n) {
        //edge cases: i reach end of list not enough occurrences
        if (*s == '\0') {
            return NULL;
        } else {
            //if letter im searching for matches letter in pointer
            if (*s == c) {
                occurrence++;
            }
        }
        s++;
    }
    //return the pointer to the nth iteration of c
    return s - 1;


}



int main(void)
{
char* line = "This is a string";
for (int n = 1; n <= 5; n++) {
    char* ptr = strchrn(line, 'i', n);
    if (ptr != NULL) {
        int index = ptr - line;
        printf("Occurrence %d of 'i' found at index = %d\n", n, index);
    } else {
         printf("Occurrence %d of 'i' not found\n", n);
    }
}
}
