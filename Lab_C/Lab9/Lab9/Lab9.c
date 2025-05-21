#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
Реализовать программу-калькулятор с возможностью выполнения арифметических действий (+, -), унарный и бинарный вариант.
У пользователя запрашивается выражение, например, "-123.5 + 4 - 456+56", программа должна решить выражение.
Для разбора входной строки использовать функцию strok.
*/


double act(char* exp) {
    double result = 0.0;
    char* token;
    char* rest = exp;


    token = strtok_s(rest, " \t", &rest);
    while (token != NULL) {
        result += atof(token);
        token = strtok_s(NULL, " ", &rest);
    }

    return result;
}

int main() {
    char st[1000];
    int i = 0, j = 0;
    printf("введите выражение: ");
    fgets(st, sizeof(st), stdin);

    int res_l = strlen(st);
    char temp[1000];
    for (i = 0; i < res_l; i++) {
        if (st[i] == ' ');
        else {
            temp[j++] = st[i];
        }
    }
    temp[j++] = '\0';


    j = 0;
    char res[1005];
    res_l = strlen(temp);
    printf("%i\n", res_l);
    for (i = 0; i < res_l; i++) {
        if (temp[i] == '-' || temp[i] == '+') {
            res[j++] = ' ';
            res[j++] = temp[i];
        }
        else {
            res[j++] = temp[i];
        }
    }
    res[j++] = '\0';

    double rsl = act(res);
    printf("ответ: %f", rsl);

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