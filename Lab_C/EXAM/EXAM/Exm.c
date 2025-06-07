#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



/* #5 */
int **mx(int n, int *arr) {
    int** matrix;

    int r = floor(sqrt(n-1));

    matrix = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++)
    {
        matrix[i] = (int*)malloc(r * sizeof(int));
    }


    int k = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            if (k < n-1) {
                matrix[i][j] = arr[k++];
            }
        }
    }

    return matrix;
}




int main() {
	
    /* #1 */
    clock_t start = clock();

    FILE* inp = fopen("input.txt", "w");
    int i = 0, j = 0;
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

    char st[256];

    for (i = 0; i < N; i++) {
        fgets(st, sizeof(st), inp);
        arr[i] = atoi(st);
    }

    //for (i = 0; i < N; i++) {
    //    if (arr[i] % 5 == 0 || arr[i] % 7 == 0) { // #4 
    //        fprintf(N_F, "пятьсемь\n");
    //    }
    //    else if (arr[i] % 7 == 0) // #3
    //    {
    //        fprintf(N_F, "семь\n"); // #3
    //    }
    //    else if (arr[i] % 5 == 0) { // #3
    //        fprintf(N_F, "пять\n");
    //    }
    //}




    /* #5 */
    int **matrix;
    matrix = mx(N, arr);
    int r = floor(sqrt(N)); 




    /* #6 */
    int sum = 0;
    for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
            sum += matrix[i][j];
        }
    }


    for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Сумма элементов матрицы: %d\n\n", sum);



    for (j = 0; j < i; j++) {
        free(matrix[j]);
    }
    free(matrix);



    /* #7 */
    clock_t end = clock();
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("время выполнения: %f", time);

    return 0;
}
