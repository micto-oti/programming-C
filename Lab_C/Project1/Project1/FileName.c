#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// Функция для расчета количества дней до заданной даты
int calculate_days_until_date(int day, int month, int year) {
    time_t now;
    time(&now);
    struct tm* current_time = localtime(&now);

    struct tm target_date = { 0 };
    target_date.tm_year = year - 1900;
    target_date.tm_mon = month - 1;
    target_date.tm_mday = day;
    target_date.tm_hour = 0;
    target_date.tm_min = 0;
    target_date.tm_sec = 0;
    target_date.tm_isdst = -1;

    time_t target_time = mktime(&target_date);
    if (target_time == -1) {
        printf("Ошибка в дате\n");
        return -1;
    }

    double seconds = difftime(target_time, now);
    int days = (int)(seconds / (60 * 60 * 24));

    return days;
}

// Функция для создания квадратной матрицы размера m*m, заполненной случайными числами от 0 до 9
int** create_matrix(int m) {
    int** matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
    return matrix;
}

// Функция для вычисления суммы всех элементов матрицы
int calculate_matrix_sum(int** matrix, int m) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Функция для освобождения памяти, выделенной под матрицу
void free_matrix(int** matrix, int m) {
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Функция для записи матрицы в файл
void write_matrix_to_file(FILE* file, int** matrix, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
}

int main() {
    clock_t start_time = clock();
    srand(time(NULL));

    // Задача 1: Расчет количества дней до даты из файла input.txt
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Не удалось открыть файл input.txt\n");
        return 1;
    }

    int day, month, year;
    if (fscanf(input_file, "%d %d %d", &day, &month, &year) != 3) {
        printf("Ошибка чтения даты из файла\n");
        fclose(input_file);
        return 1;
    }
    fclose(input_file);

    int days_until_date = calculate_days_until_date(day, month, year);
    if (days_until_date >= 0) {
        printf("Количество дней до %02d.%02d.%d: %d\n", day, month, year, days_until_date);
    }

    // Задачи 2 и 3: Создание матриц до тех пор, пока не найдутся две с одинаковой суммой
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

    // Записываем найденные матрицы в файл output.txt
    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {