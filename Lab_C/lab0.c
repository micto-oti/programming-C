#include <math.h>
/*
    Объявить вещественные переменные a, b и с и задать их значения. Предполагая, что a, b, c есть коэффициенты квадратного уравнения вывести на консоль значения их корней х1, х2. Следует подобрать такие значения коэффициентов, при которых корни будут существовать.
	Примечание. Для выполнения задания потребуется функции вычисления квадратного корня (возведение в степень), а так же вывод данных на консоль.
	Возведение в степень - подключаем заголовочныйcode файл	 math.h и используем функцию pow, первым параметром которого должен быть возводимое значение, а вторым – степень, тип данных double.
	Вывод данных - заголовочный файл stdio.h, функция printf, первым параметром является форматная строка, а последующие – переменные, значения которых необходимо вывести.
*/

int main(int argc, char *argv[]) {
    
    double a, b, c;
    double x1, x2, d;
    printf("Vvendite a:\n");
    scanf("%if",&a);
    printf("Vvendite b:\n");
    scanf("%if",&b);
    printf("Vvendite c:\n");
    scanf("%if",&c);

    printf("a = %if\n", a);
    printf("b = %if\n", b);
    printf("c = %if\n", c);

    d = pow(b, 2) - 4*a*c;
    printf("d = %if\n", d);

    if (d < 0) printf("korney net %if\n");
    if (d > 0) {
        
        x1 = (-b + sqrt(d))/(2*a);
        x2 = (-b - sqrt(d))/(2*a);

        printf("x1 = %if\n", x1);
        printf("x2 = %if\n", x2);

    }

    if (d == 0) {
        x1 = (-b + sqrt(d))/(2*a);
        printf("only one root x = %if\n", x1);
    }


    return 0;

}

