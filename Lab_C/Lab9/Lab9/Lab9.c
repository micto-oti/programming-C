#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*
Реализовать программу-калькулятор с возможностью выполнения арифметических действий (+, -), унарный и бинарный вариант.
У пользователя запрашивается выражение, например, "-123.5 + 4 - 456+56", программа должна решить выражение.
Для разбора входной строки использовать функцию strok.
*/


double act(char* exp) {
    double result = 0.0;
    char* token;
    char* rest = exp;

    // первый символ 
    token = strtok_s(rest, " ", &rest);
    while (token != NULL) {
        result += atof(token);
        token = strtok_s(NULL, " \t", &rest);
    }

    return result;
}

int main() {
    char st[1000];
    printf("Введите выражение (например, \"-123.5 + 4 - 456+56\"): ");
    fgets(st, sizeof(st), stdin);

    st[strcspn(st, "\n")] = '\0';

    int length = sizeof(st) / sizeof(st[0]);
    char res[1000];
    int index = 0;

    /* удаляем все пробелы */
    for (int i = 0; st[i] != '\0'; i++) {
        if (!isspace((unsigned char)st[i])) {
            res[index++] = st[i];
        }
    }
    res[index] = '\0';


    int res_l = strlen(res);
    int k, j = 0;
    for (k = 0; res[k] != '\0'; ) {
        if ((res[k] == '+' && res[k + 1] == '-') ||
            (res[k] == '-' && res[k + 1] == '+')) {
            res[j++] = '-';
            k += 2;
        }
        else if (res[k] == '-' && res[k + 1] == '-') {
            res[j++] = '+';
            k += 2;
        }
        else if (res[k] == '+' && res[k + 1] == '+') {
            res[j++] = '+';
            k += 2;
        }
        else {
            res[j++] = res[k++];
        }
    }
    res[j] = '\0';


    int i;
    char temp[2000] = {0};
    for (i = 0; i < res_l; i++) {
        if (res[i] == '+' || res[i] == '-') {
            strcat(temp, " ");
            strcat(temp, (char[]) { res[i], '\0' });
        }
        else {
            strcat(temp, (char[]) { res[i], '\0' });
        }
    }

    double result = act(temp);
    printf("Результат: %f\n", result);

    return 0;
}




























/*
    int tl = strlen(temp);
    int j = 0;
    for (i = 0; i < tl; i++) {
        if ((temp[i] == '+' && temp[i + 1] == '-') ||
            (temp[i] == '-' && temp[i + 1] == '+')) {
            temp[j++] = '-';
            i += 2;
        }
        else if (temp[i] == '-' && temp[i + 1] == '-') {
            temp[j++] = '+';
            i += 2;
        }
        else {
            temp[j++] = temp[i++];
        }
    }
*/