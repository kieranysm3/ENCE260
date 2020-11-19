#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

 // * is used to dereference in c means i get the value not the address
 // & is what i use to get the address
 // is q3 saying that an unsinged long is able to be the address bus for 16gig?
// why cant i print the address of an integer using %ls and &i

 void printViaPtr(const int* intPtr)
 {
     printf("%d\n", *intPtr);
}


void print2Ints(int i, int j)
{
    int* Pointer1 = &i;
    int* Pointer2 = &j;
    printViaPtr(Pointer1);
    printViaPtr(Pointer2);
}


int main(void)
{
    print2Ints(11, -93);
}

