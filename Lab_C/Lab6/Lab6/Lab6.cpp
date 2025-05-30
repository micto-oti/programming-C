﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Создать текстовый файл с записями следующего вида:
	Иванов Петр Сергеевич 1975
	Сидоров Николай Андреевич 1981
	….
	Воробьянинов Ипполит Матвеевич 1978

Прочитать данные из этого файла и записать в другой только те строки, которые относятся к родившимся позднее 1980 года.
*/

int main() {
	char buffer[256];
	
	FILE* file1 = fopen("data.txt", "r");
	FILE* output1 = fopen("output.txt", "w");

	if (file1 == NULL || output1 == NULL) {
		printf("невозможно открыть: 'data.txt' или 'output1.txt'");
		return 1;
	}

	while (fgets(buffer, sizeof(buffer), file1) != NULL) {
		char* fs = buffer;

		if (fs[0] == 'A') {
			fprintf(output1, "%s", buffer);
			printf("%s", buffer);
		}
		
	}
	fclose(file1);
	fclose(output1);

	return 0;
}
