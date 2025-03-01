#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

/*
Написать функции, вычисляющие периметр и площадь треугольника по значениям длин трёх его сторон. 
Разместить их в отдельном модуле (отличном от того, где располагается функция main( )). 
Ввести с консоли значения длин сторон треугольника (с проверкой на корректность неравенства треугольника) и выдать на консоль вычисленные с помощью написанных функций значения его периметра и площади.
*/

// создаём функцию для ввода данных о сторонах треугольника

int a, b, c;

int trianlge(int argc, char argv[])
{
	
	printf("Input trianlnge side a: \n");
	scanf("\lf", &a);
	printf("Input trianlnge side b: \n");
	scanf("\lf", &b);
	printf("Input trianlnge side c: \n");
	scanf("\lf", &c);
	
	int abside = a + b;
	int bcside = b + c;
	int acside = a + c;

	// проверка на корректность данных
	while (1);
		if (a > bcside){
			printf("a > b + c, you should change sides\n");
			printf("Input trianlnge side a: \n");
			scanf("\lf", &a);
			printf("Input trianlnge side b: \n");
			scanf("\lf", &b);
			printf("Input trianlnge side c: \n");
			scanf("\lf", &c);
	}

		if (b > acside) {
			printf("b > a + c, you should change sides\n");
			printf("Input trianlnge side a: \n");
			scanf("\lf", &a);
			printf("Input trianlnge side b: \n");
			scanf("\lf", &b);
			printf("Input trianlnge side c: \n");
			scanf("\lf", &c);
	}
		if (c > abside) {
			printf("c > a + b, you should change sides\n");
			printf("Input trianlnge side a: \n");
			scanf("\lf", &a);
			printf("Input trianlnge side b: \n");
			scanf("\lf", &b);
			printf("Input trianlnge side c: \n");
			scanf("\lf", &c);
	}
	
	return 0;
}

int main(int argc, char argv[]) 
{
	

	return 0;
}