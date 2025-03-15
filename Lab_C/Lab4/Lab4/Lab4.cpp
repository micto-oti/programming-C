#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "perim_s.h"

/*
Написать функции, вычисляющие периметр и площадь треугольника по значениям длин трёх его сторон. 
Разместить их в отдельном модуле (отличном от того, где располагается функция main( )). 
Ввести с консоли значения длин сторон треугольника (с проверкой на корректность неравенства треугольника) и выдать на консоль вычисленные с помощью написанных функций значения его периметра и площади.
*/

// создаём функцию для ввода данных о сторонах треугольника

double a, b, c;

int triangle()
{	
	bool test = false;

	// проверка на корректность данных
	while (!test) {
		printf("Input triangle side a: \n");
		scanf("%lf", &a);
		printf("Input triangle side b: \n");
		scanf("%lf", &b);
		printf("Input triangle side c: \n");
		scanf("%lf", &c);

		if (a + b > c && a + c > b && b + c > a) {
			test = true;
		}
		else {
			printf("Invalid side values\n");
		}

	}

	return 0;
}

int main(int argc, char argv[]) 
{
	double perimet, S;
	
	
	triangle();
	printf("a = %f\n", a);
	printf("b = %f\n", b);
	printf("c = %f\n", c);

	perimet = perimeter(a, b, c);

	S = calculateArea(a, b, c);

	printf("Perimeter = %f\n", perimet);
	printf("S = %f", S);

	return 0;
}