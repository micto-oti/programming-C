#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>



void free_mx(int** matrix, int r) {
    for (int j = 0; j < r; j++) {
        free(matrix[j]);
    }
    free(matrix);
}


int** mx_cr(int n) {
    int** matrix;

    int r = floor(sqrt(n));

    matrix = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++)
    {
        matrix[i] = (int*)malloc(r * sizeof(int));
    }
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

int** mx_sum(int** matrix, int r) {
    int i;
    int sum = 0;

    for (int m = 0; m < r; m++) {
        for (int j = 0; j < i; j++) {
            sum += matrix[m][j];
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
    char line[100];


    /* #1 */
    int day, month, year;
    FILE* date = fopen("data.txt", "r");

    if (date == NULL) {
        printf("Ошибка открытия data.txt\n");
        return 1;
    }

    if (fgets(line, sizeof(line), date)) {
        if (sscanf(line, "%d.%d.%d", &day, &month, &year) != 3) {
            printf("Неверный формат даты\n");
            /*printf("\n%s\n", line);
            printf("%d %d %d\n", day, month, year);*/
            fclose(date);
            return 1;
        }
    }
    fclose(date);

    time_t now;
    time(&now);
    struct tm target = { 0 };
    target.tm_mday = day;
    target.tm_mon = month - 1;
    target.tm_year = year - 1900;


    time_t tar_time = mktime(&target);
    if (tar_time == -1) {
        printf("Неверная дата\n");
        return 1;
    }

    double sec = difftime(tar_time, now);

    int days = (int)(sec / (60 * 60 * 24));

    if (days > 0) {
        printf("До даты (%02d.%02d.%04d) осталось %d дней.\n", day, month, year, days);
    }
    else if (days == 0) {
        printf("Дата (%02d.%02d.%04d) сегодня\n", day, month, year);
    }
    else {
        printf("Дата (%02d.%02d.%04d) прошла\n", day, month, year);
    }


    printf("Введите N: ");
    scanf("%d", &N);

    int r = floor(sqrt(N));

    arr1 = (int*)malloc(N * sizeof(int));


    for (i = 0; i < N; i++) {
        arr1[i] = rand() % 10;
    }

    int** mxmatr = mx(N, arr1);




    int** matrix1 = NULL;
    int** matrix2 = NULL;
    int first = -1;
    int second = -1;
    bool found = false;

    while (!found) {
        int** matrix = mx_cr(r);
        int sum = mx_sum(matrix, r);

        if (matrix1 == NULL) {
            matrix1 = matrix;
            second = sum;
        }
        else if (second == NULL) {
            matrix2 = matrix;
            second = sum;
            if (first == second) {
                found = true;
            }
        }
        else {
            free_mx(matrix1, r);
            
            matrix1 = matrix2;
            first = second;
            
            matrix2 = matrix;
            second = sum;
            if (first == second) {
                found = true;
            }
        }
    }






    return 0;
}