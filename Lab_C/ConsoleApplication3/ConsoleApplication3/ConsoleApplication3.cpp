#include <stdio.h>
#include <math.h>
#include <string.h>
#define _countof(arr) (sizeof(arr) / sizeof(arr[0]))

/*
    Объявить вещественные переменные a, b и с и задать их значения. Предполагая, что a, b, c есть коэффициенты квадратного уравнения вывести на консоль значения их корней х1, х2. Следует подобрать такие значения коэффициентов, при которых корни будут существовать.
    Примечание. Для выполнения задания потребуется функции вычисления квадратного корня (возведение в степень), а так же вывод данных на консоль.
    Возведение в степень - подключаем заголовочныйcode файл	 math.h и используем функцию pow, первым параметром которого должен быть возводимое значение, а вторым – степень, тип данных double.
    Вывод данных - заголовочный файл stdio.h, функция printf, первым параметром является форматная строка, а последующие – переменные, значения которых необходимо вывести.
*/

int main(int argc, char* argv[]) {
    char choose[10];

    while (1) {
        
        double a, b, c;
        double x1, x2, d;

        while (getchar() != '\n');

        printf("Input a:\n");
        scanf_s("%lf", &a);
        printf("Input b:\n");
        scanf_s("%lf", &b);
        printf("Input c:\n");
        scanf_s("%lf", &c);

        printf("a = %lf\n", a);
        printf("b = %lf\n", b);
        printf("c = %lf\n", c);

        d = pow(b, 2) - 4 * a * c;
        printf("d = %lf\n", d);

        if (d < 0) {
            printf("objects 'korny' not found\n");
        }
        if (d > 0) {
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);
            printf("x1 = %lf\n", x1);
            printf("x2 = %lf\n", x2);
        }
        if (d == 0) {
            x1 = -b / (2 * a);
            printf("only one koren x = %lf\n", x1);
        }
        

        printf("Continue?\n");
        scanf_s("%s", choose, (unsigned)_countof(choose));

        if (strcmp(choose, "no") == 0) {
            break;
        }
    }

    return 0;
}