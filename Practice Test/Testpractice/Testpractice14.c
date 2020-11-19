#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char** split(const char* s)
{
    size_t len = strlen(s);
    //malloc the length of the entire string
    char* string = malloc(len+1);
    strncpy(string, s, len+1);
    int i = 0;
    //malloc the size of the array
    char** result = malloc(sizeof(char*));

    char* word = strtok(string, " ");

    while(word != NULL) {
        size_t lenword = strlen(word);
        result[i] = malloc(lenword +1);
        strcpy(result[i], word);
        //what does strtok do?
        word = strtok(NULL, " ");
        i++;
        result = realloc(result, (i+1)*sizeof(char*));
    }
    result[i] = NULL;
    free(string);
    return result;

}

int main(void)
{
char** words = split("He said 'hello' to me!");
int i = 0;
while (words[i] != NULL) {
    puts(words[i]);
    free(words[i]);
    i += 1;
}
free(words);
}
