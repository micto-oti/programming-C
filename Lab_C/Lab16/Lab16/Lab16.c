#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

/* 
Написать программу подсчитывающая количество битов, выставленных в единицу у числа типа long и double. 
Сами значения чисел вводятся с клавиатуры.
*/


/* Ссылки */
// https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
// https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
// https://metanit.com/c/tutorial/6.6.php

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
        unsigned char bytes[sizeof(double)];
    } d_un;

    printf("Введите long: ");
    scanf("%ld", &l_un.l);

    printf("Введите double: ");
    scanf("%lf", &d_un.d);
    
    printf("\n");
    
    int bits_i = c_bits(&l_un.bytes, sizeof(l_un.bytes));
    int bits_f = c_bits(&d_un.bytes, sizeof(d_un.bytes));

    printf("Количество битов long: %d\n", bits_i);
    printf("Количество битов double: %d\n", bits_f);


    return 0;
}