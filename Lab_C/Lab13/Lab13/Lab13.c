#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/* Использованные ссылки */
// https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/signal?view=msvc-170
// https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/raise?view=msvc-170

/*
Написать программу, обрабатывающую получение сигналов (SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM). 
Также программа, может возбуждать эти сигналы по указанию пользователя. 
В качестве обработчика должно быть реализовано логирование (вывод на консоль).
*/

void sig_handler(int sig) {
    switch (sig) {
    case SIGABRT:
        printf("Сигнал SIGABRT (abort)\n");
        break;
    case SIGFPE:
        printf("Сигнал SIGFPE (ошибка вычесленй)\n");
        break;
    case SIGILL:
        printf("Сигнал SIGILL (ошибка выполнения)\n");
        break;
    case SIGINT:
        printf("Сигнал SIGINT (Ctrl+C)\n");
        break;
    case SIGSEGV:
        printf("Сигнал SIGSEGV (ошибка доступа к памяти)\n");
        break;
    case SIGTERM:
        printf("Сигнал SIGTERM (запрос завершения)\n");
        break;
    }
    exit(sig);
}

void sigs() {
    signal(SIGABRT, sig_handler);
    signal(SIGFPE, sig_handler);
    signal(SIGILL, sig_handler);
    signal(SIGINT, sig_handler);
    signal(SIGSEGV, sig_handler);
    signal(SIGTERM, sig_handler);
}

void print_menu() {
    printf("\nВыберите сигнал для возбуждения:"
        "\n 1. SIGABRT\n"
        "2. SIGFPE\n"
        "3. SIGILL\n"
        "4. SIGINT\n"
        "5. SIGSEGV\n"
        "6. SIGTERM\n");
}

int main() {
    sigs();

    int ch;
    while (1) {
        printf("Выберите сигнал:\n1. SIGABRT\n2. SIGFPE\n3. SIGILL\n4. SIGINT\n5. SIGSEGV\n6. SIGTERM\n");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            raise(SIGABRT);
            break;
        case 2: {
            int a = 10, b = 0;
            printf("деление на ноль: %d / %d\n", a, b);
            int result = a / b;
            // raise(SIGFPE);
            break;
        }
        case 3:
            raise(SIGILL);
            break;
        case 4:
            raise(SIGINT);
            break;
        case 5: {
            raise(SIGSEGV);
            break;
        }
        case 6:
            raise(SIGTERM);
            break;
        }
    }

    return 0;
}
