#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения. 
Объявить два массива из четырёх элементов типа humen. 
Ввести с консоли или из файла элементы одного массива и построить на их основе другой, упорядочив элементы по годам рождения. 
Вывести результат.
*/

struct humen {
    char secondName[50];
    char Name[50]; 
    char lastName[50]; 
    int Year; 
};

// функция сравнения
int compareHumen(const void* a, const void* b) {
    return ((const humen*)a) -> Year - ((const humen*)b) -> Year;
}

int main() {
    int count = 0;
    char buffer[256];
    int i;

    // открытие файла ввода и создание файла вывода
    FILE* input1 = fopen("data.txt", "r");
    FILE* output1 = fopen("output.txt", "w");
    if (!input1 || !output1) {
        printf("Не удалось открыть файл для чтения или записи.");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), input1)) { // определяем размер файла ввода
        count++;
    }

    humen* people = (humen*)malloc(count * sizeof(humen));

    FILE* input1 = fopen("data.txt", "r"); // открытие файла для чтения

    for (i = 0; i < count; i++) { // чтение элементов из файла
        fscanf(input1, "%s %s %s %d", people[i].secondName, people[i].Name, people[i].lastName, &people[i].Year); 
    }
    fclose(input1);

    // сортировка массива
    qsort(people, count, sizeof(humen), compareHumen);

    // запись результата в файл
    for (int i = 0; i < count; ++i) {
        fprintf(output1, "%s %s %s %d\n", people[i].secondName, people[i].Name, people[i].lastName, people[i].Year);
    }
    fclose(output1);

    // освобождение памяти
    free(people);

    printf("Данные успешно обработаны и записаны в output.txt\n");
    printf("Обработано записей: %d", count);

    return 0;
}