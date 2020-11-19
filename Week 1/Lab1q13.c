#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




/*
int main(void)
{
    int n1 = 0;
    int n2 = 0;

    scanf("%d", &n1);
    scanf("%d", &n2);
    for (int i = n1 ; (i <= n2); i++) {
        for (int j = 2; (j < (i - 1)); j++) {
            if (( i % j) == 0) {
                break;
                }
        printf("%d\n", i);}
    }
}
*/

int main(void)
{
    int n1 = 0;
    int n2 = 0;
    scanf("%d", &n1);
    scanf("%d", &n2);
    for (int i = n1 ; (i <= n2); i++) {
        bool prime = true;
        for (int j = 2; (j < (i - 1)); j++) {
            if ((i % j) == 0) {
                prime = false;
            }
        }
    if (prime == true) {
            printf("%d\n", i);

}
}
}
