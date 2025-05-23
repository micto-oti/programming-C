#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <setjmp.h>

/*
Написать программу с использованием нелокального перехода setjmp/longjmp, 
которая вычисляет сумму чисел Фибоначчи (начиная с1, 1,...). Использовать рекурсивную функции для вычисления суммы, 
в качестве механизма возврата из вложенных вызовов использовать нелокальный переход.
*/

void fib_sum(jmp_buf env, int* count, int limit, int* sum, int a, int b) {
    if (*count >= limit) {
        longjmp(env, 1);
    }

    (*count)++;
    *sum += a;

    // Следующий член ряда: b, a + b
    fib_sum(env, count, limit, sum, b, a + b);
}

int main() {
    jmp_buf buffer;
    int count = 0;
    int lim = 0;
    int sum = 0;

    printf("Введите количество чисел Фибоначчи: ");
    scanf("%d", &lim);

    int checkpoint = setjmp(buffer);
    
    if (checkpoint == 0) {
        fib_sum(buffer, &count, lim, &sum);
    }
    else {
        printf("Сумма первых %d чисел Фибоначчи: %d\n", lim, sum);
    }

    return 0;
}