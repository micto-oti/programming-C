#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <setjmp.h>

/*
Написать программу с использованием нелокального перехода setjmp/longjmp, 
которая вычисляет сумму чисел Фибоначчи (начиная с1, 1,...). Использовать рекурсивную функции для вычисления суммы, 
в качестве механизма возврата из вложенных вызовов использовать нелокальный переход.
*/

int fib(int n) {
    if (n <= 2) return 1;
    return fib(n - 1) + fib(n - 2);
}

void fib_sum(jmp_buf env, int* count, int limit, int* sum) {
    if (*count >= limit) {
        longjmp(env, 1);
    }

    (*count)++;
    *sum += fib(*count);

    fib_sum(env, count, limit, sum);
}

int main() {
    jmp_buf buffer;
    int count = 0;
    int lim = 0;
    int sum = 0;

    printf("Введите количество чисел Фибоначчи для суммирования: ");
    scanf("%d", &lim);

    setjmp(buffer);
    
    fib_sum(buffer, &count, lim, &sum);

    printf("Сумма первых %d чисел Фибоначчи: %d\n", lim, sum);

    return 0;
}
