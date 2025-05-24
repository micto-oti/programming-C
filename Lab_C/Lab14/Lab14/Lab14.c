#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <setjmp.h>
#include <limits.h>

/* Использованные ссылки */
// https://metanit.com/c/tutorial/10.2.php
// https://en.wikipedia.org/wiki/Fibonacci_number
// https://www.geeksforgeeks.org/fibonacci-series-2/
// https://metanit.com/c/tutorial/2.3.php
// https://habr.com/ru/articles/768288/

/*
Написать программу с использованием нелокального перехода setjmp/longjmp, 
которая вычисляет сумму чисел Фибоначчи (начиная с1, 1,...). Использовать рекурсивную функции для вычисления суммы, 
в качестве механизма возврата из вложенных вызовов использовать нелокальный переход.
*/

void fib_sum(jmp_buf n, int* count, int lim, long long *sum, int a, int b) {
    if (*count >= lim) {
        longjmp(n, 1);
    }

    (*count)++;
    *sum += a;

    // Следующий член ряда: b, a + b
    fib_sum(n, count, lim, sum, b, a + b);
}

int main() {
    jmp_buf check;
    int count = 0;
    int lim = 0;
    long long sum = 0;

    printf("Введите количество чисел Фибоначчи: ");
    scanf("%d", &lim);

    int checkpoint = setjmp(check);
    
    if (checkpoint == 0) {
        fib_sum(check, &count, lim, &sum, 1, 1);
    }
    else {
        printf("Сумма первых %d чисел Фибоначчи: %d\n", lim, sum);
    }

    return 0;
}