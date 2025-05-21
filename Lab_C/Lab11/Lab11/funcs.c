#include <stdarg.h>

int sum(int count, ...) {
    va_list args;
    va_start(args, count);

    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }

    va_end(args);
    return total;
}

int max_val(int count, ...) {
    if (count <= 0) return 0;

    va_list args;
    va_start(args, count);

    int mx_vl = va_arg(args, int);

    for (int i = 1; i < count; i++) {
        int elem = va_arg(args, int);
        if (elem > mx_vl) {
            mx_vl = elem;
        }
    }

    va_end(args);
    return mx_vl;
}

int min_val(int count, ...) {
    if (count <= 0) return 0;

    va_list args;
    va_start(args, count);

    int mn_vl = va_arg(args, int);

    for (int i = 1; i < count; i++) {
        int elem = va_arg(args, int);
        if (elem < mn_vl) {
            mn_vl = elem;
        }
    }

    va_end(args);
    return mn_vl;
}

double avr(int count, ...) {
    va_list args;
    va_start(args, count);

    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }

    va_end(args);
    return (double)total / count;
}