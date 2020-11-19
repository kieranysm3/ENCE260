#include <stdio.h>
#include <stdlib.h>


/*
int gringe(int boink, int flunk) {
    int floodle;
    if (boink == flunk) {
        floodle = 42;
    } else {
        floodle = flunk - 11;
    }
    return floodle;
}
*/


int gringe(int boink, int flunk) {

    return ((boink == flunk) ? 42: (flunk - 11));
}


int main(void)

{
printf("%d\n", gringe(23, 24));
printf("%d\n", gringe(23, 23));
}
