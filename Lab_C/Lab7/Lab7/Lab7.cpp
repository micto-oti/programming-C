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
int compareHumen(const humen* a, const humen* b) {
    if (a->Year != b->Year) {
        return a->Year - b->Year;
    }
}

int main() {
    int count = 0;
    char buffer[256];
    int i;

    // открытие файлов ввода и вывода, создание файла вывода
    FILE* input1 = fopen("data.txt", "r");
    FILE* output1 = fopen("output.txt", "w");
    if (!input1 || !output1) {
        printf("Не удалось открыть файл для чтения или записи.");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), input1)) { // определяем размер файла ввода
        count++;
    }
    rewind(input1);

    humen* people = (humen*)malloc(count * sizeof(humen));


    for (i = 0; i < count; i++) { 
        fscanf(input1, "%s %s %s %d", people[i].secondName, people[i].Name, people[i].lastName, &people[i].Year); 
    }
    fclose(input1);

    // сортировка массива
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (compareHumen(&people[j], &people[j + 1]) > 0) {
                humen temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
    

    for (int i = 0; i < count; ++i) {
        fprintf(output1, "%s %s %s %d\n", people[i].secondName, people[i].Name, people[i].lastName, people[i].Year);
    }
    fclose(output1);

    
    free(people);

    printf("Данные успешно обработаны и записаны в output.txt\n");
    printf("Обработано записей: %d", count);

    return 0;
}
