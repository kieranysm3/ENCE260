#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

//single and double quotes have different meaning
//strlen --> gives length of string
//strstr - find within string in hexadecimal
//strncpy copy string but myst give size of copy
// double quotes is for string and single quotes is for chracter/ you can store character using double quote but not vice versa
int main(void)
{
    #define NUM_CHARS_TO_PRINT 20

/* printChars prints out its parameter using a printf with a %s format.
 * It then interprets the parameter as a char array, and prints
 * the first NUM_CHARS_TO_PRINT values of that array (both the character value
 * and the decimal integer value). Note that the string must be null-terminated.
 */
void printChars(char* s)
{
    int length = -1;
    printf("Parameter s = '%s'\n", s);
    printf("Now, as an array of individual chars ...\n");
    for (int i = 0; i < NUM_CHARS_TO_PRINT; i++) {
        printf("s[%d] = '%c' (%d)\n", i, s[i], (int) s[i]);
        if (s[i] == '\0') {
            length = i;
            break;
        }
    }
    if (length == -1) {
        printf("That string has %d or more characters.\n", NUM_CHARS_TO_PRINT);
    } else {
        printf("String length = %d\n", length);
    }
}

/* A "roll-your own" version of the puts ("put string") function.
 * Really just a simplified version of printChars above.
 * Note that the parameter type is char array, but that's equivalent
 * to char*
 */
void myPuts(char s[])
{
    int i = 0;
    while (s[i]) {
        putchar(s[i++]);
    }
}


// Another version of puts, using a char* parameter and pointer
// arithmetic.
void myPuts2(char* s)
{
    while (*s) {
        putchar(*s++);
    }
}


int main(void)
{
    char* s = "This is a string literal.\n";
    char s2[] = {'T','h','i','s',' ','i','s',' ','a','n',' ',
                 'a','r','r','a','y','\n','\0'};
    puts("'puts' prints a string. Its parameter is of type char*.\n");
    char s3[] = "This is an array too!\n";
    puts(s);  /* So we can pass in a variable of type 'char*' */
    puts(s2); /* ... or an array of chars... */
    puts(s3); /* ... and another array, with different initialiser syntax */
    puts(&s3[6]);  /* Think carefully about this one! */
    printf("s2 = %s\n\n", s2); /* We can format a string for output with %s */
    printChars("A test string");
    myPuts("A test string printed with myPuts\n");
    myPuts2("A test string printed with myPuts2\n");
    return 0;
}
    char c = 'a';
    if (isalpha(c)) {
        puts("Yes");
    }


    char s[] = {'T', 'h', 'i', 's', 0};
    char s2[] = "This";
    char* s3 = "This";

    printf("%p %p %p\n", s, s2, s3);
    // address of s3 is located at a different location from the hexadecimal location mentioned

    s[1] = '*';
    s2[1] = '*';
    //s3[1] = '*';
    puts(s);
    puts(s2);
    puts(s3);
}

