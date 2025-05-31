#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

/* Ссылки */
// https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
// https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
// 

// Функция подсчёта битов, выставленных в 1, для любого блока памяти
int c_bits(const void* ptr, size_t size) {
    int count = 0;
    const unsigned char* bytes = (const unsigned char*)ptr;
    for (size_t i = 0; i < size; i++) {
        unsigned char byte = bytes[i];
        // Подсчёт битов в байте
        for (int bit = 0; bit < 8; bit++) {
            if (byte & (1 << bit))
                count++;
        }
    }
    return count;
}

int main() {
    long lnum;
    double dnum;

    printf("Введите число типа long: ");
    if (scanf("%ld", &lnum) != 1) {
        printf("Ошибка ввода для long\n");
        return 1;
    }

    printf("Введите число типа double: ");
    if (scanf("%lf", &dnum) != 1) {
        printf("Ошибка ввода для double\n");
        return 1;
    }

    int bits_i = c_bits(&lnum, sizeof(lnum));
    int bits_f = c_bits(&dnum, sizeof(dnum));

    printf("Количество битов, выставленных в 1 у long: %d\n", bits_i);
    printf("Количество битов, выставленных в 1 у double: %d\n", bits_f);

    return 0;
}
