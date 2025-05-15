#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#define MAX_DIG(arr, size, mx) \
    mx = arr[0]; \
    for (int i = 1; i < size; i++) { \
        if (arr[i] > mx) { \
            mx = arr[i]; \
        } \
    } \
    

/*
Написать программу вычисления максимального числа из введенных пользователем в виде одной строки.  
Использовать для этого макрос (без функции), на вход которому подается массив чисел и их количество.
*/

int main(){
	char st[1000];
    int *numbers = NULL;
    int count = 0;

	printf("Введите строку чисел через пробел:\n");
    fgets(st, sizeof(st), stdin);

    char* token = strtok(st, " ");
    while (token != NULL) {
        int num = atoi(token);

        numbers = (int*)realloc(numbers, (count + 1) * sizeof(int));
        if (numbers == NULL) {
            printf("Ошибка выделения памяти!\n");
            return 1;
        }
        numbers[count] = num;
        count++;

        token = strtok(NULL, " ");
    }

    int res = 0;
    for (int i = 0; i < count; i++) {
        res += numbers[i];
    }

    double avr = (double) res/count;

    if (count == 0) {
        printf("Не введено ни одного числа.\n");
        return 1;
    }


    int max_num;
    MAX_DIG(numbers, count, max_num);

    printf("Максимальное число: %d\n", max_num);
    printf("Среднее арифметическое: %lf", avr);


	return 0;
}