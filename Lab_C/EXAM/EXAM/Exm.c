#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


//int mx(int n, int *arr) {
//    int** matrix;
//
//
//    int r = floor(sqrt(n));
//
//    matrix = (int**)malloc(r * sizeof(int*));
//    for (int i = 0; i < r; i++)
//    {
//        matrix[i] = (int*)malloc(r * sizeof(int));
//    }
//
//
//    int k = 0;
//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < r; j++) {
//            if (k < n) {
//                matrix[i][j] = arr[k++];
//            }
//        }
//    }
//
//    return **matrix;
//}




int main() {
	
    /* #1 */

    clock_t start = clock();

    FILE* inp = fopen("input.txt", "w");
    int i = 0;
    int N;


    printf("Введите N: ");
    scanf("%d", &N);

    int* arr;
    arr = (int*)malloc(N * sizeof(int));

    
    for (i = 0; i < N; i++) {
        fprintf(inp, "%d\n", rand() % 100); // случайное число
    }


    /* #2 */
    
    fclose(inp);
    free(arr);


    /* #3 */
    
    inp = fopen("input.txt", "r");
    FILE* N_F = fopen("output.txt", "w");

    char line[256];

    for (i = 0; i < N; i++) {
        fgets(line, 256, inp);
        arr[i] = atoi(line);
    }

    for (i = 0; i < N; i++) {
        if (arr[i] == 0) {

        }
        else if (arr[i] % 5 == 0 || arr[i] % 7 == 0) { // #4 
            fprintf(N_F, "пятьсемь\n");
        }
        else if (arr[i] % 7 == 0) // #3
        {
            fprintf(N_F, "семь\n"); // #3
        }
        else if (arr[i] % 5 == 0) { // #3
            fprintf(N_F, "пять\n");
        }
    }


    /* #5 */
    int** matrix;
    int r = floor(sqrt(N));

    matrix = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        matrix[i] = (int*)malloc(r * sizeof(int));
    }

    int k = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            if (k < N) {
                matrix[i][j] = arr[k++];
            }
        }
    }

    /*
    int matrix;
    matrix = mx(N, arr);
    int r = floor(sqrt(N)); 
    */

    /* #6 */
    int sum = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            sum += matrix[i][j];
        }
    }
    printf("Сумма строк и столбцов матрицы: %d\n\n", sum);































    clock_t end = clock();
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    return 0;

}
