/*
#include <stdio.h>
#define N_MAX 100
*/
/*
int main(void)
{
    char line[N_MAX] = {0};   // An array of char. initialse arrays like this
    int c = 0;       // A generic character, cast to an int
    int i = 0;       // Generic loop index/counter
    int n = 0;       // Number of bytes read
    // sizeof gives size of the line
    //%zu z is for size u is for unsigned ( unsigned portable size type)
    printf("Variable n requires %zu bytes of memory\n", sizeof n);
    printf("Array line occupies %zu bytes of memory\n", sizeof line);
    printf("Enter a line of text, terminated by 'Enter'\n");
    while ((c = getchar())!= '\n' && c != EOF && n < N_MAX) { // Read a line
        line[i++] = c;    // Add char to line, increment index
                          // [an ok style rule exception]
    }
    n = i;   // Number of bytes read

    for (int i = n - 1; i >= 0; i--) {  // Print it out backwards
        putchar(line[i]);
    }
    putchar('\n');
    // From now on we'll rely on C99 to return 0 (EXIT_SUCCESS) by default
}
*/
/* Simple array demo program.
 * Also demonstrates sizeof.
 * Reads a line of input characters into a 1D array
 * of 'char', then writes the line out backwards.
 * Written for ENCE260 by RJL.
 * February 2011, June 2013, July 2015, June 2016
 */

#include <stdio.h>
#include <stdlib.h>

#define N_MAX 100

int main(void)
{
    char line[N_MAX] = { 0 };     // An array of char, init'ed to zero
    int c = 0;                    // An int with a char in its low byte
    int n = 0;

    printf("Variable n requires %zu bytes of memory\n", sizeof n);
    printf("Array line occupies %zu bytes of memory\n", sizeof line);

    printf("Enter a line of text, terminated by 'Enter'\n");

    // Read characters until EOF, newline or buffer full

    c = getchar();              /* Get char (cast to int) or EOF */
    while (c != EOF && c != '\n' && n < N_MAX) {
        line[n] = c;
        n += 1;
        c = getchar();
    }

    // Now print out all those characters backwards

    printf("Your input line, written backwards, is:\n");
    for (int i = n - 1; i >= 0; i--) {
        putchar(line[i]);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}
