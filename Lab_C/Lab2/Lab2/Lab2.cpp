#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Объявить массив данных типа double размером 3 на 3. Ввести с консоли его значения, вывести на консоль сумму его элементов, расположенных на главной диагонали и сумму элементов, расположенных на  побочной диагонали.
Объявить массив данных типа int размером 2 на 2. Ввести с консоли его значения, вывести на консоль квадрат данной матрицы.
*/

int main(int argc, char* argv[]) {

    int i, j;
    double Array[3][3], sumg, sump;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf_s("%lf", &Array[i][j]);
        }
    }


    sumg = Array[0][0] + Array[1][1] + Array[2][2];
    sump = Array[0][2] + Array[1][1] + Array[2][0];


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