#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fncs.h"

/*Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами типа double (значения n и элементы массивов ввести с консоли). 
А также ввести с консоли знак операции: '+', '-' или '*'. 
Написать функцию, вычисляющую сумму, разность или произведение данных матриц (их передать по указателю) и возвращающую указатель на массив-результат. 
Разместить эту функцию в отдельном модуле (отличном от того, где располагается функция main()).
Выдать на консоль значения полученного вектора.*/

int main(int argc, char *argv[]) {
	int i, j, m;
	char action[2];
	double **pr;

	printf("Size of matrix: ");
	scanf("%d", &i);

	double **matrix1 = (double**)malloc(i * sizeof(double*));
	double **matrix2 = (double**)malloc(i * sizeof(double*));
	

	for (j = 0; j < i; j++) {
		matrix1[j] = (double*)malloc(i * sizeof(double));
	}

	for (j = 0; j < i; j++) {
		matrix2[j] = (double*)malloc(i * sizeof(double));
	}


	for (m = 0; m < i; m++) {
		for (j = 0; j < i;j++) {
			printf("Input value for matrix 1 [%d][%d]: ", m, j);
			scanf("%lf", &matrix1[m][j]);
			
		}
	}

	printf("\n");

	for (m = 0; m < i; m++) {
		for (j = 0; j < i;j++) {
			printf("Input values for matrix 2 [%d][%d]: ", m, j);
			scanf("%lf", &matrix2[m][j]);

		}
	}

	printf("Input action (+, -, *): ");
	scanf("%s", &action);

	pr = mx_act(action, matrix1, matrix2, i);

	for (m = 0; m < i; m++) {
		for (j = 0; j < i; j++) {
			printf("%lf ", pr[m][j]);
		}
		printf("\n");
	}

	for (j = 0; j < i; j++) {
		free(matrix1[j]);
		free(matrix2[j]);
		free(pr[j]);
	}
	free(matrix1);
	free(matrix2);
	free(pr);
	

	return 0;
}
