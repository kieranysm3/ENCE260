#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isWonRow(char player, char game[3][3], int rowNum)
{
    int i = 0;
    int isWon = 0;
    for(i = 0; i < 3; i++) {
        if (game[rowNum][i] == player) {
            isWon = 1;
        } else {
            isWon = 0;
        }
    }
    return isWon;
}


int main(void)
{
    int value;
    value = isWonRow('X', game, 1));
    printf("%d", value);
    return EXIT_SUCCESS;
}
