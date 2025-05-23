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
        printf("Выберите сигнал:\n"
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
            raise(SIGFPE);
            //int zero = 0;
            //int x = 1 / zero; // Вызовет SIGFPE
            //(void)x;
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
            //int* p = NULL;
            //*p = 42; // Вызовет SIGSEGV
            break;
        }
        case 6:
            raise(SIGTERM);
            break;
        }
    }

    return 0;
}
