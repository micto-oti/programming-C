#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/*
Написать программу, обрабатывающую получение сигналов (SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM). 
Также программа, может возбуждать эти сигналы по указанию пользователя. 
В качестве обработчика должно быть реализовано логирование (вывод на консоль).
*/

void sig_handler(int sig) {
    switch (sig) {
    case SIGABRT:
        printf("[LOG] Получен сигнал SIGABRT\n");
        break;
    case SIGFPE:
        printf("[LOG] Получен сигнал SIGFPE (ошибка арифметики)\n");
        break;
    case SIGILL:
        printf("[LOG] Получен сигнал SIGILL (недопустимая инструкция)\n");
        break;
    case SIGINT:
        printf("[LOG] Получен сигнал SIGINT (Ctrl+C)\n");
        break;
    case SIGSEGV:
        printf("[LOG] Получен сигнал SIGSEGV (ошибка доступа к памяти)\n");
        break;
    case SIGTERM:
        printf("[LOG] Получен сигнал SIGTERM (запрос завершения)\n");
        break;
    default:
        printf("[LOG] Получен неизвестный сигнал: %d\n", sig);
    }
    exit(sig);
}

void sig_hand() {
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
    sig_hand();

    int ch;
    while (1) {
        printf("Выберите сигнал для возбуждения:\n"
            "1. SIGABRT\n"
            "2. SIGFPE\n"
            "3. SIGILL\n"
            "4. SIGINT\n"
            "5. SIGSEGV\n"
            "6. SIGTERM\n");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            raise(SIGABRT);
            break;
        case 2: {
            int zero = 0;
            int x = 1 / zero; // Вызовет SIGFPE
            (void)x;
            break;
        }
        case 3:
            raise(SIGILL);
            break;
        case 4:
            raise(SIGINT);
            break;
        case 5: {
            int* p = NULL;
            *p = 42; // Вызовет SIGSEGV
            break;
        }
        case 6:
            raise(SIGTERM);
            break;
        case 0:
            printf("Выход из программы.\n");
            return 0;
        default:
            printf("Неверный выбор, попробуйте снова.\n");
        }
    }

    return 0;
}
