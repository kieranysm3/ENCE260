#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int x;
    int y;
    int z;
} Vector3d;

Vector3d vector(int x, int y, int z)
{
    Vector3d createdvector;
    createdvector.x = x;
    createdvector.y = y;
    createdvector.z = z;
    return createdvector;

}



Vector3d vectorCrossProduct(Vector3d a, Vector3d b)
{
    Vector3d crossresult;
    crossresult.x = ((a.y * b.z) - (a.z * b.y));
    crossresult.y = ((a.z * b.x) - (a.x * b.z));
    crossresult.z = ((a.x * b.y) - (a.y * b.x));
    return crossresult;



}



int main(void)
{

    Vector3d v1 = vector(1, 2, 3);
    Vector3d v2 = vector(-4, -6, 2);
    Vector3d v3 = vectorCrossProduct(v1, v2);
    printf("(%d, %d, %d)\n", v3.x, v3.y, v3.z);
}
