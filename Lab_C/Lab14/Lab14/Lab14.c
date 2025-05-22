#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <setjmp.h>

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

    if (setjmp(buffer) == 0) {
        fib_sum(buffer, &count, lim, &sum);
    }
    else {
        printf("Сумма первых %d чисел Фибоначчи: %d\n", lim, sum);
    }

    return 0;
}
