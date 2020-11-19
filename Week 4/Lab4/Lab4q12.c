
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

char data[100];

bool isInData(char* p)
{
    //array is just allocated memory with pointer at the start
    //just check memory address at start and end of allocation?
    //how do i check address of

    //char* endOfData = &data[100];
    //if address of value p is before the address at data[100] and greater than the address at data[0]
    return ((p <= &data[100]) && (p >= &data[0]));
}

int main(void)
{

printf("%d\n", isInData(&data[0]));

}
