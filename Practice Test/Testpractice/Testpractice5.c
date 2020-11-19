#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int countChars(const char* s, const char* charsOfInterest)
{
    int lengthofs = strlen(s);
    int lengthcharinterest = strlen(charsOfInterest);

    int counter = 0; // counter for number of appearences
    for (int indexofs = 0; indexofs < lengthofs; indexofs++) {
        for(int indexofcharsofinterest = 0; indexofcharsofinterest < lengthcharinterest; indexofcharsofinterest++) {
            if (s[indexofs] == charsOfInterest[indexofcharsofinterest]) {
                counter += 1;
            }
        }
    }
    return counter;





}


int main(void)
{
    printf("%d\n", countChars("ABBCCCDDD!", "BC!5"));
}
