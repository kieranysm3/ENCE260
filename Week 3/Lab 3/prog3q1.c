/* Program to introduce the 'char' data type, plus the use of getchar and
 * putchar to read and write chars from/to standard input.
 * Reads characters from stdin, printing each one out in both decimal and octal,
 * until '\n' or end-of-file is reached.
 * Written for ENCE260 by RJL.
 * June 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// 0x = Octal \ = hexdeciaml int e.g. 32 = decimal
// %c and %d diff for printing EOF

int main(void)
{
    int c = 0;                  // An int with a char in its low byte "
    // Read and print characters until newline or End-Of-File           // Get char (cast to int) or EOF
    c = getchar();
    while (c != EOF) {
        if (c ==  '\012') {
            printf("'\\n'\n");
        } else if (isalpha(c)) {
            if (c >= 91) {
                printf("'%c': Letter %d\n", c, (c - '`'));
            } else {
                printf("'%c': Letter %d\n", c, (c - '@'));
            }

        } else if (isdigit(c)) {
            printf("'%c': Digit %c\n", c, c);
        } else {
            printf("'%c': Non-alphanumeric\n", c);
        }
        c = getchar();
    }
    return EXIT_SUCCESS;
}
