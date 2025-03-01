#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

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
		printf("Input trianlnge side a: \n");
		scanf("%d", &a);
		printf("Input trianlnge side b: \n");
		scanf("%d", &b);
		printf("Input trianlnge side c: \n");
		scanf("%d", &c);

		if (a + b > c && a + c > b && b + c > a) {
			test = true;
		}
		else {
			printf("Invalid side values\n");
		}

	}

	return 0;
}

double calculateArea(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main(int argc, char argv[]) 
{
	double peremeter, S;
	
	
	triangle();
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);


	peremeter = a + b + c;
	S = calculateArea(a, b, c);
	printf("Peremeter = %d\n", peremeter);
	printf("S = %d", S);

	return 0;
}