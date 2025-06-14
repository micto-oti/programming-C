#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <bool.h>


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

    arr1 = (int*)malloc(N * sizeof(int));


    for (i = 0; i < N; i++) {
        arr1[i] = rand() % 10;
    }

    int** matrix1 = mx(N, arr1);



    int m;
    printf("Введите размер матрицы m: ");
    scanf("%d", &m);

    int** first_matrix = NULL;
    int** second_matrix = NULL;
    int first_sum = -1;
    int second_sum = -1;
    bool found = false;

    while (!found) {
        // Создаем новую матрицу
        int** matrix = create_matrix(m);
        int sum = calculate_matrix_sum(matrix, m);

        // Проверяем, совпадает ли сумма с предыдущими матрицами
        if (first_matrix == NULL) {
            first_matrix = matrix;
            first_sum = sum;
        }
        else if (second_matrix == NULL) {
            second_matrix = matrix;
            second_sum = sum;
            if (first_sum == second_sum) {
                found = true;
            }
        }
        else {
            // Освобождаем память от предыдущей первой матрицы
            free_matrix(first_matrix, m);
            // Перемещаем вторую матрицу в первую
            first_matrix = second_matrix;
            first_sum = second_sum;
            // Сохраняем новую матрицу как вторую
            second_matrix = matrix;
            second_sum = sum;
            if (first_sum == second_sum) {
                found = true;
            }
        }
    }






    return 0;
}