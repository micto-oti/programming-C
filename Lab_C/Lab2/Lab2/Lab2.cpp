#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(int argc, char* argv[]) {

    int i, j;
    double A[3][3], sumg, sump;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }


    sumg = A[0][0] + A[1][1] + A[2][2];
    sump = A[0][2] + A[1][1] + A[2][0];


    printf(" Summa sumg = %lf \n", sumg);
    printf(" Summa sump = %lf \n", sump);

    int B[2][2];
    int a, b, c, d;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    a = pow(B[0][0], 2) + (B[0][1] * B[1][0]);
    b = (B[0][0] * B[0][1]) + (B[0][1] * B[1][1]);
    c = (B[1][0] * B[0][0]) + (B[1][1] * B[1][0]);
    d = (B[1][0] * B[0][1]) + pow(B[1][1], 2);
    printf("%d ", a);
    printf("%d \n", b);
    printf("%d ", c);
    printf("%d \n", d);

    return 0;


}