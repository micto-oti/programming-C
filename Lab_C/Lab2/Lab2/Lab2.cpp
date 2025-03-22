#define _CRT_SECURE_NO_WARNINGS // отключение сообщений об ошибке связанной с безопасностью
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Объявить массив данных типа double размером 3 на 3. Ввести с консоли его значения, вывести на консоль сумму его элементов, расположенных на главной диагонали и сумму элементов, расположенных на  побочной диагонали.
Объявить массив данных типа int размером 2 на 2. Ввести с консоли его значения, вывести на консоль квадрат данной матрицы.
*/

int main(int argc, char* argv[]) {

    int i, j, h, k, x;
    double Arr[3][3], sumg = 0, sump = 0; // объявлоналейяем матрицу и переменные для диаг

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &Arr[i][j]); // заполняем матрицу
        }
    }

    for (k = 0; k < i; k++) {
        sumg += Arr[k][k]; // вычисление главной диагонали
    }

    for (h = 0; h < i; h++) {
        k--;
        sump += Arr[h][k]; // вычисление побочной диагонали
        }
    
    printf(" Sum main diag = %lf \n", sumg);
    printf(" Sum second diag = %lf \n", sump);




    
    int B[2][2], R[2][2];
    //int a, b, c, d;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("B[%d][%d]: ", i, j); // заполнение матрицы
            scanf("%d", &B[i][j]);
        }
    }

    for (j = 0; j < i; j++) {
        for (h = 0; h < i; h++) {
            R[j][h] = 0;
            for (k = 0; k < i; k++) {
                R[j][h] += B[j][k] * B[k][h];
            }
        }
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\n", R[i][j]);
        }
    }

    return 0;
}