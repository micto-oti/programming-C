#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

/* Ссылки */
// https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
// https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
// 

// Функция подсчёта битов, выставленных в 1, для любого блока памяти
int bits(unsigned char byte) {
    int count = 0;
    while (byte) {
        count += byte & 1;
        byte >>= 1;
    }
    return count;
}

int c_bits(const unsigned char *bytes, size_t size) {
    int total = 0;
    for (size_t i = 0; i < size; i++) {
        total += bits(bytes[i]);
    }
    return total;
}

int main() {
    union {
        long l;
        unsigned char bytes[sizeof(long)];
    } l_un;
    
    union {
        double d;
        unsigned char bytes[sizeof(long)]
    } d_un;
    
    
    
    
    
    
    
    
    
    
    
    /*long lnum;
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

    return 0;*/
}
