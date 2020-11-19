#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    char* beverage;
    float abv;
    int volume;
} Drink;


int main(void)
{
    Drink shot = {"Tequila", 0.6, 30};
    printf("A %d mL drink of %s is about %.1f standard drinks.\n", shot.volume, shot.beverage, shot.volume * shot.abv * 0.0789);
}
