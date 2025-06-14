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

int** mx_cr(int m) {
    int** matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
    return matrix;
}

int mx_sum(int** matrix, int r) {
    int sum = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main() {
    srand(time(NULL));
    clock_t start = clock();

    int day, month, year;
    FILE* date = fopen("data.txt", "r");
    if (date == NULL) {
        printf("Ошибка открытия data.txt\n");
        return 1;
    }

    if (fscanf(date, "%d.%d.%d", &day, &month, &year) != 3) {
        printf("Неверный формат даты\n");
        fclose(date);
        return 1;
    }
    fclose(date);

    time_t now;
    time(&now);
    struct tm target = { 0 };
    target.tm_mday = day;
    target.tm_mon = month - 1;
    target.tm_year = year - 1900;
    target.tm_isdst = -1;

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

    int N;
    printf("Введите размер матрицы m: ");
    scanf("%d", &N);

    int** matrix1 = NULL;
    int** matrix2 = NULL;
    int first = -1;
    int second = -1;
    bool found = false;

    while (!found) {
        int** matrix = mx_cr(N);
        int sum = mx_sum(matrix, m);

        if (matrix1 == NULL) {
            matrix1 = matrix;
            first = sum;
        }
        else if (matrix2 == NULL) {
            matrix2 = matrix;
            second = sum;
            if (first == second) {
                found = true;
            }
        }
        else {
            free_mx(matrix1, m);
            matrix1 = matrix2;
            first = second;
            matrix2 = matrix;
            second = sum;
            if (first == second) {
                found = true;
            }
        }
    }

    FILE* matr = fopen("output.txt", "w");
    if (matr == NULL) {
        printf("Не удалось открыть файл output.txt\n");
        free_mx(matrix1, m);
        free_mx(matrix2, m);
        return 1;
    }

    fprintf(matr, "Первая матрица (сумма: %d):\n", first);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(matr, "%d ", matrix1[i][j]);
        }
        fprintf(matr, "\n");
    }

    fprintf(matr, "Вторая матрица (сумма: %d):\n", second);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(matr, "%d ", matrix2[i][j]);
        }
        fprintf(matr, "\n");
    }

    fclose(matr);

    free_mx(matrix1, m);
    free_mx(matrix2, m);

    clock_t end = clock();
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Время выполнения: %f\n", time);
    return 0;
}