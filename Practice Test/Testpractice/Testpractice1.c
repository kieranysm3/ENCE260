#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int add_even_sub_odd(const int data[], int n)
{
    int counter = 0;
    //int first = data[counter];

    //int last = data[n - 1];
    int store = 0;
    //printf("this is first %d this is last %d\n", data[counter], last);
    for(; counter != n; counter++) {
        //printf("data[counter] is %d\n", data[counter]);
        //printf("this is store %d\n", store);
        //printf("data[counter] mod 2 is %d\n", (data[counter] % 2));

        if ((data[counter] % 2) == 0) {
            //printf("data[counter] mod 2 is %d\n", data[counter]% 2);
            store += data[counter];
        } else {
            store -= data[counter];
        }
    }

    return store;
}


int main(void)
{

int data[4] = {-1, 2, -3, -4};
printf("%d\n", add_even_sub_odd(data, 3));
}
