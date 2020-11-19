#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Declare the StringPair type.
// Note that we have incorporated the struct declaration into
// the typedef, but that this only works because we don't have any
// StringPair pointers in the structure (e.g. StringPair* next).
typedef struct stringpair_s {
    char* first;
    char* second;
 } StringPair;

StringPair* newStringPair(const char* s1, const char* s2)
{
        StringPair* newPair = malloc(sizeof(StringPair));
        char* data1 = malloc((strlen(s1) + 1) * sizeof(char));
        char* data2 = malloc((strlen(s2) + 1) * sizeof(char));
        newPair->first = data1;
        newPair->second = data2;
        strncpy(newPair->first, s1, (strlen(s1)) * sizeof(char));
        strncpy(newPair->second, s2, (strlen(s2)) * sizeof(char));
        newPair->first[strlen(s1)] = '\0';
        newPair->second[strlen(s2)] = '\0';
        return newPair;

}

int main(void)
{
    char s1[] = "My first string";
    char s2[] = "Another one";
    StringPair* pair = NULL;

    pair = newStringPair(s1, s2);

    // Before printing, alter the initial strings to ensure
    // the function hasn't just copied the pointers.
    strncpy(s1, "Smasher1", sizeof(s1));
    strncpy(s2, "Clobber2", sizeof(s2));

    // Now print the new StringPair.
    printf("String pair: ('%s', '%s')\n", pair->first, pair->second);

    // Lastly free all dynamic memory involved.
    free(pair->first);
    free(pair->second);
    free(pair);
}
