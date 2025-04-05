#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
	int year;
	char buffer[256];

	FILE* file1 = fopen("data.txt", "r");
	FILE* output1 = fopen("output.txt", "w");

	if (file1 == NULL || output1 == NULL) {
		printf("Can't open: 'data.txt' or 'output1.txt'");
		return 1;
	}

	while (fgets(buffer, sizeof(buffer), file1) != NULL) {
		char* last_str = strrchr(buffer, ' ');
		
		/*if (last_str == NULL) {
			continue;
		}*/
		
		//printf("\n\nbefore: %s", last_str);  // Вывод: Hello
		//last_str[strlen(last_str) - 2] = '\0'; // Удаляем последний символ

		//printf("after: %s", last_str);  // Вывод: Hello

		//
		//printf("%s\n", last_str + 1);
		
		year = atoi(last_str + 1);

		if (year > 1980) {
			fprintf(output1, "%s\n", buffer);
			printf("%s\n", buffer);
		}

	}

	return 0;
}
