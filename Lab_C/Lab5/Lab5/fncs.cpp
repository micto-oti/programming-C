#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

double **mx_act(char action[2], double **matrix1, double **matrix2, int i) {
	int k, j, m;
	double **result = (double**)malloc(i * sizeof(double*));

	for (j = 0; j < i; j++) {
		result[j] = (double*)malloc(i * sizeof(double));
	}


	if (strcmp(action, "+") == 0) {
		for (m = 0; m < i; m++) {
			for (j = 0; j < i; j++) {
				result[m][j] = matrix1[m][j] + matrix2[m][j];
			}
		}
	}

	if (strcmp(action, "-") == 0) {
		for (m = 0; m < i; m++) {
			for (j = 0; j < i; j++) {
				result[m][j] = matrix1[m][j] - matrix2[m][j];
			}
		}
	}

	if (strcmp(action, "*") == 0) {
		for (m = 0; m < i; m++) {
			for (j = 0; j < i; j++) {
				result[m][j] = 0;
				for (k = 0; k < i; k++)
					result[m][j] += matrix1[m][k] * matrix2[k][j];
			}
		}
	}


	return result;
}