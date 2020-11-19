#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
if any of the roots are zero, print not a quad
if i compute a negative square root, then its a imaginary root
How to create a function that takes in 2 parameters HELPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP

*/

int main(void)
{
    float Var1 = 0.0;
    float Var2 = 0.0;
    float Var3 = 0.0;
    float Root1;
    float Root2;
    float Determinant;
    scanf("%f", & Var1);
    scanf("%f", & Var2);
    scanf("%f", & Var3);
    Determinant = ((Var2 * Var2) - (4 * Var1 * Var3));
    if (Var1 == 0) {
            puts("Not a quadratic");
        } else if (Determinant < 0.0 ) {
            puts("Imaginary roots");
        } else {


        Root1 = (-Var2 - sqrt((Var2 * Var2)- (4 * Var1 * Var3)))/(2 * Var1);
        Root2 = (-Var2 + sqrt((Var2 * Var2)- (4 * Var1 * Var3)))/(2 * Var1);
if (Root1 < Root2)
{
        printf("Roots are  %.4f and %.4f", Root1, Root2);
    } else {
        printf("Roots are  %.4f and %.4f", Root2, Root1);
    }
    }
}

