#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void free_mx(int** matrix, int r) {
    for (int j = 0; j < r; j++) {
        free(matrix[j]);
    }
    free(matrix);
}

int** mx(int n, int* arr) {
    int** matrix;

    int r = floor(sqrt(n));

    matrix = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++)
    {
        matrix[i] = (int*)malloc(r * sizeof(int));
    }


    int k = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            if (k < n) {
                matrix[i][j] = arr[k++];
            }

        }
    }

    return matrix;
}

int** mx_mult(int r, int** matrix1, int** matrix2) {
    int i;
    int** mult;

    mult = (int**)malloc(r * sizeof(int*));
    for (i = 0; i < r; i++) {
        mult[i] = (int*)malloc(r * sizeof(int));
    }

    for (int m = 0; m < r; m++) {
        for (int j = 0; j < r; j++) {
            mult[m][j] = 0;
            for (int k = 0; k < i; k++)
                mult[m][j] += matrix1[m][k] * matrix2[k][j];
        }
    }

    return mult;
}

int** mx_sum(int r, int** matrix1, int** matrix2) {
    int i;
    int** sum;

    sum = (int**)malloc(r * sizeof(int*));
    for (i = 0; i < r; i++) {
        sum[i] = (int*)malloc(r * sizeof(int));
    }


    for (int m = 0; m < r; m++) {
        for (int j = 0; j < i; j++) {
            sum[m][j] = matrix1[m][j] + matrix2[m][j];
        }
    }

    return sum;
}





int main() {
    srand(time(NULL));
    clock_t start = clock();


    int i = 0, j = 0, k = 0;
    int N;
    int* arr1;
    int* arr2;

    FILE* inp = fopen("input.txt", "w");


    printf("Введите N: ");
    scanf("%d", &N);

    arr1 = (int*)malloc(N * sizeof(int));
    arr2 = (int*)malloc(N * sizeof(int));


    for (i = 0; i < N; i++) {
        arr1[i] = rand() % 100;
    }

    for (i = 0; i < N; i++) {
        arr2[i] = rand() % 100;
    }


    int** matrix1 = mx(N, arr1);
    int** matrix2 = mx(N, arr2);

    int r = floor(sqrt(N));


    FILE* matr = fopen("matrix.txt", "w");
    if (matr == NULL) {
        printf("Не удалось создать matrix.txt\n");

        free_mx(matrix1, r);
        free_mx(matrix2, r);
        free(arr1);
        free(arr2);

        return 1;
    }


    for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
            fprintf(matr, "%d ", matrix1[i][j]);
        }
        fprintf(matr, "\n");
    }

    printf("\n");

    for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
            fprintf(matr, "%d ", matrix2[i][j]);
        }
        fprintf(matr, "\n");
    }

    fclose(matr);
    free_mx(matrix1, r);
    free_mx(matrix2, r);


    matr = fopen("matrix.txt", "r");

    if (matr == NULL) {
        printf("Ошибка открытия matrix.txt\n");
        return 1;
    }

    matrix1 = (int**)malloc(r * sizeof(int*));
    matrix2 = (int**)malloc(r * sizeof(int*));

    for (i = 0; i < r; i++) {
        matrix1[i] = (int*)malloc(r * sizeof(int));
        for (j = 0; j < r; j++) {
            fscanf(matr, "%d", &matrix1[i][j]);
        }
    }

    for (i = 0; i < r; i++) {
        matrix2[i] = (int*)malloc(r * sizeof(int));
        for (j = 0; j < r; j++) {
            fscanf(matr, "%d", &matrix2[i][j]);
        }
    }

    fclose(matr);


    int m;
    int** sum;
    int** mult;


    sum = mx_sum(r, matrix1, matrix2);

    mult = mx_mult(r, matrix1, matrix2);

    FILE* out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Ошибка открытия output.txt\n");
        return 1;
    }


    printf("Сумма матриц:\n");
    fprintf(out, "Сумма матриц:\n");

    for (m = 0; m < i; m++) {
        for (j = 0; j < i; j++) {
            printf("%i ", sum[m][j]);
            fprintf(out, "%i ", sum[m][j]);
        }
        fprintf(out, "\n");
        printf("\n");
    }
    printf("\n");

    printf("Произведение матриц:\n");
    fprintf(out, "Произведение матриц:\n");

    for (m = 0; m < i; m++) {
        for (j = 0; j < i; j++) {
            printf("%i ", mult[m][j]);
            fprintf(out, "%i ", mult[m][j]);
        }
        fprintf(out, "\n");
        printf("\n");
    }
    printf("\n");

    int minimal = 0;
    for (m = 0; m < i; m++) {
        for (j = 0; j < i; j++) {
     
        
        }
    }





    return 0;
}