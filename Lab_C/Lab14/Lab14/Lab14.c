#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <setjmp.h>

int fibonacci(int n) {
    if (n <= 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void fib_sum(jmp_buf env, int* count, int limit, int* sum) {
    if (*count >= limit) {
        longjmp(env, 1);
    }

    (*count)++;
    *sum += fibonacci(*count);

    fib_sum(env, count, limit, sum);
}

int main() {
    jmp_buf jump_buffer;
    int count = 0;
    int limit = 0;
    int sum = 0;

    printf("Введите количество чисел Фибоначчи для суммирования: ");
    scanf("%d", &limit);

    if (setjmp(jump_buffer) == 0) {
        fib_sum(jump_buffer, &count, limit, &sum);
    }
    else {
        printf("Сумма первых %d чисел Фибоначчи: %d\n", limit, sum);
    }

    return 0;
}
